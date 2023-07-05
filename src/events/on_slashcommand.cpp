#include <dpp/dpp.h>
#include "events/on_slashcommand.h"

void on_slashcommand(const dpp::slashcommand_t& event, const dpp::cluster& bot)
{
    std::cout << event.command.get_command_name() << " Foi executado" << std::endl;

    const CommandNames::CommandMap &commandMap = CommandNames::GetCommandMap();

    auto items = commandMap.find(event.command.get_command_name());
    if (items != commandMap.end())
    {
        const CommandNames::CommandFunction &commandFunction = items->second;
        commandFunction(event, bot);
    }
}