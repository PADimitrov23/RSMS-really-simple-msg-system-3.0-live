#pragma once
#include <vector>

using namespace std;

#include <sqlite3.h>

bool openDatabase(sqlite3** db);

bool createTable(sqlite3* db);

void closeDatabase(sqlite3* db);

struct Message {
    int id;
    string sender;
    string message;
    string timestamp;
};

bool insertSender(sqlite3* db, string sender, string message);

vector<Message> getAllMessages(sqlite3* db);