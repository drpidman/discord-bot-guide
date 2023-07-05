#include "events/on_ready.h"

void on_ready(dpp::cluster &bot) {
    std::cout << "Bot ready! Log-In: " << bot.me.username << std::endl;

    CommandNames::RegisterCInfosCommand(bot);
}