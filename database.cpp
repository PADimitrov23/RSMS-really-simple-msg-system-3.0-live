#include <iostream>
#include "database.hpp"

using namespace std;

bool openDatabase(sqlite3** db)
{
    if (sqlite3_open("chat.db", db) != SQLITE_OK) {
        cerr << "Error opening DB || Error Creating DB" << "\n";
        
        return false;
    }
    else {
        cout << "Database opened successfully" << "\n";

        return true;
    }
}
//Opening the database && checking if it is open successfully

bool createTable(sqlite3* db)
{
    const char* sql = "CREATE TABLE IF NOT EXISTS messages ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "sender TEXT NOT NULL,"
                      "message TEXT NOT NULL,"
                      "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP"
                      ");";

    char* errorMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errorMsg) != SQLITE_OK) {
        cerr << "Error creating table: " << errorMsg << "\n";
        sqlite3_free(errorMsg);
        
        return false;
    }
    else {
        cout << "Table created successfully" << "\n";
        
        return true;

    }

}
//Creating our SQL query, errorMsg && creating our table

void closeDatabase(sqlite3* db)
{

if (db) {
    sqlite3_close(db);
    cout << "Database closed successfully" << "\n";
}

}
//Checking if database is still active, open && closing it

bool insertSender(sqlite3* db, string sender, string message)
{
    // Example SQL insertion
    std::string sql = "INSERT INTO messages (sender, message) VALUES (?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement\n";
        return false;
    }

    sqlite3_bind_text(stmt, 1, sender.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, message.c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Failed to execute statement\n";
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}


vector<Message> getAllMessages(sqlite3* db)
{
    vector<Message> results;

    const char* sql =
        "SELECT id, sender, message, timestamp " 
        "FROM messages "
        "ORDER BY id ASC"; //top to bottom

    sqlite3_stmt* stmt = nullptr;

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "function getAllMessages preparation failed " << sqlite3_errmsg(db) << "\n";

        return results;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        Message m;
        m.id = sqlite3_column_int(stmt, 0);
        const unsigned char* s1 = sqlite3_column_text(stmt, 1);
        const unsigned char* s2 = sqlite3_column_text(stmt, 2);
        const unsigned char* s3 = sqlite3_column_text(stmt, 3);
        m.sender = s1 ? reinterpret_cast<const char*>(s1) : "";
        m.message = s2 ? reinterpret_cast<const char*>(s2) : "";
        m.timestamp = s3 ? reinterpret_cast<const char*>(s3) : "";
        results.push_back(std::move(m));
    }

        if (rc != SQLITE_DONE) {
        std::cerr << "getAllMessages: step error: "
                  << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
    return results;
}