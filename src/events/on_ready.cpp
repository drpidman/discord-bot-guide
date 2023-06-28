#include <dpp/dpp.h>

#include "commands/CommandNames.h"
#include "commands/docs.h"

#include "events/on_ready.h"

void onReady(dpp::cluster &bot) {
    std::cout << "Bot ready! Log-In: " << bot.me.username << std::endl;

    CommandNames::RegisterCInfosCommand(bot);
}