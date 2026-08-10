#include <iostream>
#include <ctime>
#include "core/system.h"
#include "core/config.h"
#include "core/logger.h"
#include "ai/assistant.h"
#include "security/auth.h"
#include "hardware/device.h"
#include "ui/interface.h"

int main() {
    srand(time(0));
    Allia::UI::showWelcomeScreen();

    std::cout << "Allia OS is starting...\n";

    Allia::Config::loadConfig();
    Allia::Logger::log("Allia OS starting up");
    Allia::initializeSystem();

    std::cout << "AI Core: Initializing...\n";
    std::cout << "Security Core: Initializing...\n";
    std::cout << "Hardware Core: Initializing...\n";
    std::cout << Allia::Hardware::checkMicrophone() << "\n";
    std::cout << "System: READY\n\n";

    std::string passwordAttempt;
    int attempts = 0;

    int maxAttempts = 3;
    std::string maxAttemptsStr = Allia::Config::get("max_attempts");
    if (maxAttemptsStr != "") {
        maxAttempts = std::stoi(maxAttemptsStr);
    }

    bool accessGranted = false;

    while (attempts < maxAttempts) {
        std::cout << "Enter password to access Allia: ";
        std::getline(std::cin, passwordAttempt);

        if (Allia::Security::authenticate(passwordAttempt)) {
            accessGranted = true;
            break;
        }

        attempts++;
        Allia::Logger::log("Failed login attempt");
        std::cout << "Incorrect password. Attempts remaining: " << (maxAttempts - attempts) << "\n";
    }

    if (!accessGranted) {
        Allia::Logger::log("Too many failed attempts - system locked");
        std::cout << "Too many failed attempts. Shutting down.\n";
        return 0;
    }

    Allia::Logger::log("Login successful");
    std::cout << "Access granted.\n\n";
    std::cout << "Talk to Allia (type 'exit' to quit):\n";

    std::string userInput;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, userInput);

        std::string reply = Allia::AI::respond(userInput);
        std::cout << reply << "\n";

        if (userInput == "exit") {
            Allia::Logger::log("User exited Allia OS");
            break;
        }
    }

    return 0;
}
