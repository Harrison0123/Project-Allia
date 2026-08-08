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
    std::cout << Allia::AI::respond("hello") << "\n";

    std::cout << "Security Core: Initializing...\n";
    std::cout << "Hardware Core: Initializing...\n";
    std::cout << "System: READY\n";

    return 0;
}