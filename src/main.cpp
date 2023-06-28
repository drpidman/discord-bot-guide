#include <dpp/dpp.h>
#include <string>
#include <iostream>
#include "events/on_ready.h"
#include "events/on_slashcommand.h"

#include "dotenv.h"

const std::string BOT_TOKEN = "MTA3MTI3NDA1MzQ5MjU0MzUwOA.G8Rcj1.V9ntJrrV43K738RLKYRxXgq5VUT4_JPTaNRPpg";


int main(int argc, char const *argv[])
{
	
    auto& dotenv = dotenv::env.load_dotenv();

	dpp::cluster bot(dotenv["BOT_TOKEN"]);

    
    bot.on_log(dpp::utility::cout_logger());

    bot.on_ready([&bot](const dpp::ready_t& event) {
        onReady(bot);
    });

    bot.on_slashcommand([&bot](const dpp::slashcommand_t & event) {
        onSlashcommand(event, bot);
    });

    bot.start(dpp::st_wait);
    return 0;
    
}
