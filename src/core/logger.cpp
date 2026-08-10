#include "logger.h"
#include <fstream>
#include <ctime>

namespace Allia {
    namespace Logger {

        void log(std::string message) {
            time_t now = time(0);
            std::string timeStr = ctime(&now);
            timeStr.erase(timeStr.length() - 1);

            std::ofstream file("allia.log", std::ios::app);
            file << "[" << timeStr << "] " << message << std::endl;
        }

    }
}
