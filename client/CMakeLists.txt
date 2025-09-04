add_executable(client
    client.cpp
    ask-to-type-msg.cpp
    chat-history-ui.cpp
)
target_link_libraries(client PRIVATE simple-websocket-server shared)
