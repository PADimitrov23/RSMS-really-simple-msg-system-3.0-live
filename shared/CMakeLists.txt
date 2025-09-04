add_library(shared
    database.cpp
)
target_include_directories(shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(SQLite3 REQUIRED)

target_link_libraries(shared PRIVATE SQLite::SQLite3)