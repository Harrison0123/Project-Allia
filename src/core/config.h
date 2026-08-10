#ifndef ALLIA_CORE_CONFIG_H
#define ALLIA_CORE_CONFIG_H

#include <string>
#include <map>

namespace Allia {
    namespace Config {

        bool loadConfig();
        std::string get(std::string key);

    }
}

#endif
