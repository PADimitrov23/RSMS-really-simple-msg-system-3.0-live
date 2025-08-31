#include <iostream>
#include <vector>
#include "database.hpp"

void displayMessagesUi(const std::vector<Message>& msgs) {
    std::cout << "\033[1;35m"; // purple-ish header color
    std::cout << "╔══════════════════════════════════════════════════════════╗\n";
    std::cout << "║                      CHAT HISTORY                        ║\n";
    std::cout << "╠══════════════════════════════════════════════════════════╣\n";
    std::cout << "\033[0m";

    for (const auto& m : msgs) {
    std::cout << "║ [" << m.timestamp << "] "
              << "\033[1;36m" << m.sender << "\033[0m"
              << ": " << m.message << "\n";
    }

    std::cout << "╚══════════════════════════════════════════════════════════╝\n";
}