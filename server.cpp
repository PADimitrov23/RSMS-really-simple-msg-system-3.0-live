#include <iostream>
#include <string>


#include "Websocket/server_ws.hpp"
#include "database.hpp"

using namespace std;
using namespace SimpleWeb;

using WsServer = SocketServer<WS>;
int main() {
    
sqlite3* db;
sqlite3_open("chatGlobal.db", &db);

    SocketServer<WS> server;
    server.config.port = 80085;
    auto &rsms = server.endpoint["/rsms/"];

    rsms.on_message = [&](shared_ptr<WsServer::Connection> connection, shared_ptr<WsServer::InMessage> msg) {

        string message = msg->string();
        string sender;

        size_t separatorPos = message.find_first_of(':');


        sender = message.substr(0, separatorPos);
        message = message.substr(separatorPos + 1);

        insertSender(db, sender, message);

        string concatMessage = sender + ':' + message;
        
        connection->send(concatMessage);

    };

    server.start();





    server.stop();

sqlite3_close(db);

}