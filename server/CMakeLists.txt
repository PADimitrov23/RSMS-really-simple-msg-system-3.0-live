add_executable(server
    server.cpp
)
target_link_libraries(server PRIVATE simple-websocket-server shared)
