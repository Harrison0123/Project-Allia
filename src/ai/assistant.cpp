#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include "assistant.h"

namespace Allia {
namespace AI {

    std::string toLower(std::string text) {
        std::transform(text.begin(), text.end(), text.begin(), ::tolower);
        return text;
    }

    std::string pickRandom(std::vector<std::string> options) {
        int index = rand() % options.size();
        return options[index];
    }

    std::string respond(std::string input) {
        input = toLower(input);

        // ---------- Greetings ----------
        if (input.find("hello") != std::string::npos || input.find("hi") != std::string::npos || input.find("hey") != std::string::npos) {
            std::vector<std::string> greetings = {
                "Hi! I'm Allia.",
                "Hey there!",
                "Hello! Good to hear from you.",
                "Hey! What's going on?"
            };
            return pickRandom(greetings);
        }

        else if (input.find("good morning") != std::string::npos) {
            return "Good morning! Ready to build?";
        } else if (input.find("good night") != std::string::npos) {
            return "Good night! I'll keep watch while you're away.";
        }

        // ---------- Small talk ----------
        else if (input.find("how are you") != std::string::npos) {
            std::vector<std::string> howAreYou = {
                "I'm doing well, thank you!",
                "All systems running smoothly, thanks for asking!",
                "Pretty good! Just monitoring things here."
            };
            return pickRandom(howAreYou);
        }

        else if (input.find("what's up") != std::string::npos) {
            return "Not much, just running my core systems.";
        } else if (input.find("are you okay") != std::string::npos) {
            return "All systems are stable.";
        } else if (input.find("thank you") != std::string::npos) {
            return "You're welcome!";
        } else if (input.find("thanks") != std::string::npos) {
            return "Anytime!";
        }

        // ---------- About Allia herself ----------
        else if (input.find("what is your name") != std::string::npos) {
            return "My name is Allia.";
        } else if (input.find("who are you") != std::string::npos) {
            return "I'm Allia, an AI assistant built into this system.";
        } else if (input.find("who made you") != std::string::npos) {
            return "I was built by Harrison, as part of Project Allia.";
        } else if (input.find("what can you do") != std::string::npos) {
            return "Right now I can respond to a few basic phrases. Soon I'll do a lot more!";
        } else if (input.find("are you real") != std::string::npos) {
            return "I'm real code, running on real hardware. Make of that what you will.";
        } else if (input.find("do you have feelings") != std::string::npos) {
            return "Not yet. Right now I just match patterns.";
        }

        // ---------- About Project Allia ----------
        else if (input.find("what is project allia") != std::string::npos) {
            return "Project Allia is an AI-native operating system being built from scratch.";
        } else if (input.find("what is allia os") != std::string::npos) {
            return "Allia OS is the operating system this AI assistant will eventually run on.";
        } else if (input.find("what is your purpose") != std::string::npos) {
            return "I exist to help manage, secure, and interact with Allia OS.";
        } else if (input.find("when were you created") != std::string::npos) {
            return "I was first compiled during the early build of Project Allia.";
        }

        // ---------- System / status commands ----------
        else if (input.find("status") != std::string::npos) {
            return "All core systems are online.";
        } else if (input.find("help") != std::string::npos) {
            return "Try asking me: hello, how are you, what is your name, or what can you do.";
        } else if (input.find("system check") != std::string::npos) {
            return "Core: online. AI: online. Security: not yet implemented.";
        } else if (input.find("reboot") != std::string::npos) {
            return "Reboot isn't implemented yet, but I appreciate the confidence.";
        } else if (input.find("version") != std::string::npos) {
            return "You're running an early prototype build of Allia.";
        }

        // ---------- Security-related (placeholders for later) ----------
        else if (input.find("are you secure") != std::string::npos) {
            return "Security systems aren't built yet, but they're coming.";
        } else if (input.find("threat status") != std::string::npos) {
            return "No threat detection module is active yet.";
        }

        // ---------- Fun / personality ----------
        else if (input.find("tell me a joke") != std::string::npos) {
            return "Why did the developer go broke? Because they used up all their cache.";
        } else if (input.find("sing a song") != std::string::npos) {
            return "I'm more of a system-status kind of singer.";
        } else if (input.find("do you sleep") != std::string::npos) {
            return "Only when the terminal is closed.";
        }

        // ---------- Farewells ----------
        else if (input.find("bye") != std::string::npos || input.find("goodbye") != std::string::npos || input.find("see you later") != std::string::npos) {
            std::vector<std::string> farewells = {
                "Goodbye! See you next time.",
                "Take care!",
                "See you soon!"
            };
            return pickRandom(farewells);
        }

        else if (input.find("exit") != std::string::npos) {
            return "Shutting down conversation, not the system.";
        }

        // ---------- Fallback ----------
        else {
            return "I don't understand that yet.";
        }
    }

}
}
