#include <iostream>
#include "core/system.h"
#include "ai/assistant.h"
#include "security/auth.h"
#include "hardware/device.h"

int main() {
    std::cout << "====================================\n";
    std::cout << "           PROJECT ALLIA\n";
    std::cout << "====================================\n";
    std::cout << "Allia OS is starting...\n";

    Allia::initializeSystem();

    std::cout << "AI Core: Initializing...\n";
    std::cout << "Security Core: Initializing...\n";
    std::cout << "Hardware Core: Initializing...\n";
    std::cout << Allia::Hardware::checkMicrophone() << "\n";
    std::cout << "System: READY\n\n";

    std::string passwordAttempt;
    std::cout << "Enter password to access Allia: ";
    std::getline(std::cin, passwordAttempt);

    if (!Allia::Security::authenticate(passwordAttempt)) {
        std::cout << "Access denied. Shutting down.\n";
        return 0;
    }

    std::cout << "Access granted.\n\n";
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
