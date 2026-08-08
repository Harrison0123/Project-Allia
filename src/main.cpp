#include <iostream>
#include "core/system.h"
#include "ai/assistant.h"

int main() {
    std::cout << "====================================\n";
    std::cout << "           PROJECT ALLIA\n";
    std::cout << "====================================\n";
    std::cout << "Allia OS is starting...\n";

    Allia::initializeSystem();

    std::cout << "AI Core: Initializing...\n";
    std::cout << "Security Core: Initializing...\n";
    std::cout << "Hardware Core: Initializing...\n";
    std::cout << "System: READY\n\n";

    std::cout << "Talk to Allia (type 'exit' to quit):\n";

    std::string userInput;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, userInput);

        std::string reply = Allia::AI::respond(userInput);
        std::cout << reply << "\n";

        if (userInput == "exit") {
            break;
        }
    }

    return 0;
}