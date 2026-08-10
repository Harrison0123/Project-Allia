#include "config.h"
#include <fstream>
#include <iostream>

namespace Allia {
    namespace Config {

        std::map<std::string, std::string> settings;

        bool loadConfig() {
            std::string filepath = "config.txt";
            std::ifstream file(filepath);

            if (!file.is_open()) {
                std::cout << "[ALLIA CORE] Config file not found: " << filepath << std::endl;
                return false;
            }

            std::string line;
            while (std::getline(file, line)) {
                size_t equalsPos = line.find('=');
                if (equalsPos == std::string::npos) {
                    continue;
                }

                std::string key = line.substr(0, equalsPos);
                std::string value = line.substr(equalsPos + 1);

                settings[key] = value;
            }

            std::cout << "[ALLIA CORE] Config loaded from " << filepath << std::endl;
            return true;
        }

        std::string get(std::string key) {
            if (settings.count(key)) {
                return settings[key];
            }
            return "";
        }

    }
}
