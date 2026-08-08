#include <string>
#include "assistant.h"

namespace Allia {
namespace AI {

    std::string respond(std::string input) {
        if (input == "hello") {
            return "Hi! I'm Allia.";
        }
        return "I don't understand that yet.";
    }

}
}