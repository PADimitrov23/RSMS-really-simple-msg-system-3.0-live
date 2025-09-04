cmake_minimum_required(VERSION 3.15)

project(really-simple-msg-system)

add_subdirectory(Websocket)

find_package(SQLite3 REQUIRED)

add_executable(really-simple-msg-system 
    client.cpp
    #server.cpp
    database.cpp
    chat-history-ui.cpp
    ask-to-type-msg.cpp
)

target_link_libraries(really-simple-msg-system 
    PRIVATE 
    simple-websocket-server
    SQLite::SQLite3
)
