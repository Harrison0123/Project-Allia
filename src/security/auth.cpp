#include <string>
#include "auth.h"
#include "../core/config.h"

namespace Allia {
namespace Security {

    bool authenticate(std::string password) {
        std::string correctPassword = Allia::Config::get("password");
        if (correctPassword == "") {
            correctPassword = "allia123"; // fallback default
        }

        if (password == correctPassword) {
            return true;
        }
        return false;
    }

}
}
