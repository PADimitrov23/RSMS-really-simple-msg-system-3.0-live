#include <iostream>
#include <string>

bool askToTypeMessage() {
    std::string input;

    while (true) {

        std::cout << "\033[1;36m"; // Cyan color
        std::cout << "╔════════════════════════╗\n";
        std::cout << "║  Do you want to write  ║\n";
        std::cout << "║      a message?        ║\n";
        std::cout << "╠════════════════════════╣\n";
        std::cout << "\033[0m"; // Reset color

        std::cout << "> Type Y for Yes or N for No: ";
        std::getline(std::cin, input);


        if (!input.empty()) {
            char choice = toupper(input[0]);
            if (choice == 'Y') return true;
            if (choice == 'N') return false;
        }

        // Invalid input
        std::cout << "\033[1;31m" // Red color
                  << "Invalid input! Please type Y or N.\n"
                  << "\033[0m"; // Reset color
    }
}