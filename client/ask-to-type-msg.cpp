#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int askToTypeMessage() {
    std::string input;

    // Define the ASCII art lines
    const std::vector<std::string> asciiArt = {
        "⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣤⣤⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⢀⣠⣶⣾⡿⠿⢛⣛⣛⣛⡛⠻⠿⣿⣷⣦⡀⠀⠀⠀⠀⠀",
        "⠀⠀⢀⣴⣿⡿⠛⠁⠀⣴⣿⣿⣿⣿⣿⣷⡄⠀⠉⠻⣿⣷⡀⠀⠀⠀",
        "⠀⢀⣾⡿⠋⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⡧⠀⠀⠀⠈⠻⣿⣦⠀⠀",
        "⢀⣿⡿⢁⣠⣤⣤⣤⣈⢿⣿⣿⣿⣿⣿⣿⠇⣠⣤⣤⣤⣀⠹⣿⣧⠀",
        "⣼⣿⢳⣿⣿⣿⣿⣿⣿⣧⠙⢻⣿⣿⠛⢡⣾⣿⣿⣿⣿⣿⣷⣻⣿⡀",
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸⣿⣿⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇",
        "⣿⣿⠘⣿⣿⣿⣿⣿⣿⣿⡀⢸⣿⣿⠀⣸⣿⣿⣿⣿⣿⣿⡿⢹⣿⡇",
        "⢿⣿⡄⠈⠙⠛⠟⠛⠙⢿⣿⣾⣿⣿⣾⣿⠟⠙⠛⠟⠛⠉⠀⣸⣿⠁",
        "⠈⣿⣷⡀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⡟⠃⠀⠀⠀⠀⠀⠀⣰⣿⡟⠀",
        "⠀⠘⢿⣷⣄⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⢀⣴⣿⠟⠀⠀",
        "⠀⠀⠈⠻⣿⣷⣄⡀⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⢀⣴⣿⡿⠃⠀⠀⠀",
        "⠀⠀⠀⠀⠈⠙⠿⣿⣷⣶⣤⣼⣛⣻⣤⣤⣶⣾⡿⠟⠋⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠛⠛⠛⠛⠛⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀"
    };

    // Define the menu box lines
    const std::vector<std::string> menuBox = {
        "╔══════════════════════════════════╗",
        "║          CHOOSE OPTION           ║",
        "╠══════════════════════════════════╣",
        "║ Y - Write a message              ║",
        "║ H - View chat history            ║",
        "║ N - Exit chat                    ║",
        "╚══════════════════════════════════╝"
    };

    while (true) {
        // Find the maximum number of lines
        size_t maxLines = std::max(asciiArt.size(), menuBox.size());

        // Print side by side
        for (size_t i = 0; i < maxLines; i++) {
            // Print ASCII art line (if exists)
            if (i < asciiArt.size()) {
                std::cout << asciiArt[i];
            } else {
                // Print spaces if no ASCII art line
                std::cout << std::string(asciiArt[0].size(), ' ');
            }
            
            // Add some spacing between
            std::cout << "   "; // 3 spaces between
            
            // Print menu box line (if exists)
            if (i < menuBox.size()) {
                std::cout << "\033[1;36m" << menuBox[i] << "\033[0m";
            }
            
            std::cout << std::endl;
        }

        std::cout << "\033[0m"; // Reset color

        std::cout << "> Enter your choice (Y/H/N): ";
        std::getline(std::cin, input);

        if (!input.empty()) {
            char choice = toupper(input[0]);
            if (choice == 'Y') return 1; // Write message
            if (choice == 'H') return 2; // View history
            if (choice == 'N') return 3; // Exit
        }

        // Invalid input
        std::cout << "\033[1;31m" 
                  << "Invalid input! Please type Y, H, or N.\n"
                  << "\033[0m"; 
        
        std::cout << "\n\n";
    }

}

// this is deepseek's work im not even gonna lie
