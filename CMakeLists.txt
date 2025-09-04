cmake_minimum_required(VERSION 3.15)

project(really-simple-msg-system)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Websocket)
add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(shared)
