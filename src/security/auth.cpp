#include <string>
#include "auth.h"

namespace Allia {
namespace Security {

    bool authenticate(std::string password) {
        if (password == "allia123") {
            return true;
        }
        return false;
    }

}
}
