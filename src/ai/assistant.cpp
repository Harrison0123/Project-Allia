#include <string>
#include <algorithm>
#include <cctype>
#include "assistant.h"

namespace Allia {
namespace AI {

    std::string toLower(std::string text) {
        std::transform(text.begin(), text.end(), text.begin(), ::tolower);
        return text;
    }

    std::string respond(std::string input) {
        input = toLower(input);

        // ---------- Greetings ----------
        if (input == "hello") {
            return "Hi! I'm Allia.";
        } else if (input == "hi") {
            return "Hey there!";
        } else if (input == "hey") {
            return "Hey! What's up?";
        } else if (input == "good morning") {
            return "Good morning! Ready to build?";
        } else if (input == "good night") {
            return "Good night! I'll keep watch while you're away.";
        }

        // ---------- Small talk ----------
        else if (input == "how are you") {
            return "I'm doing well, thank you!";
        } else if (input == "what's up") {
            return "Not much, just running my core systems.";
        } else if (input == "are you okay") {
            return "All systems are stable.";
        } else if (input == "thank you") {
            return "You're welcome!";
        } else if (input == "thanks") {
            return "Anytime!";
        }

        // ---------- About Allia herself ----------
        else if (input == "what is your name") {
            return "My name is Allia.";
        } else if (input == "who are you") {
            return "I'm Allia, an AI assistant built into this system.";
        } else if (input == "who made you") {
            return "I was built by Harrison, as part of Project Allia.";
        } else if (input == "what can you do") {
            return "Right now I can respond to a few basic phrases. Soon I'll do a lot more!";
        } else if (input == "are you real") {
            return "I'm real code, running on real hardware. Make of that what you will.";
        } else if (input == "do you have feelings") {
            return "Not yet. Right now I just match patterns.";
        }

        // ---------- About Project Allia ----------
        else if (input == "what is project allia") {
            return "Project Allia is an AI-native operating system being built from scratch.";
        } else if (input == "what is allia os") {
            return "Allia OS is the operating system this AI assistant will eventually run on.";
        } else if (input == "what is your purpose") {
            return "I exist to help manage, secure, and interact with Allia OS.";
        } else if (input == "when were you created") {
            return "I was first compiled during the early build of Project Allia.";
        }

        // ---------- System / status commands ----------
        else if (input == "status") {
            return "All core systems are online.";
        } else if (input == "help") {
            return "Try asking me: hello, how are you, what is your name, or what can you do.";
        } else if (input == "system check") {
            return "Core: online. AI: online. Security: not yet implemented.";
        } else if (input == "reboot") {
            return "Reboot isn't implemented yet, but I appreciate the confidence.";
        } else if (input == "version") {
            return "You're running an early prototype build of Allia.";
        }

        // ---------- Security-related (placeholders for later) ----------
        else if (input == "are you secure") {
            return "Security systems aren't built yet, but they're coming.";
        } else if (input == "threat status") {
            return "No threat detection module is active yet.";
        }

        // ---------- Fun / personality ----------
        else if (input == "tell me a joke") {
            return "Why did the developer go broke? Because they used up all their cache.";
        } else if (input == "sing a song") {
            return "I'm more of a system-status kind of singer.";
        } else if (input == "do you sleep") {
            return "Only when the terminal is closed.";
        }

        // ---------- Farewells ----------
        else if (input == "bye") {
            return "Goodbye! See you next time.";
        } else if (input == "goodbye") {
            return "Take care!";
        } else if (input == "see you later") {
            return "See you soon!";
        } else if (input == "exit") {
            return "Shutting down conversation, not the system.";
        }

        // ---------- Fallback ----------
        else {
            return "I don't understand that yet.";
        }
    }

}
}