#include "commands/CommandNames.h"

namespace CommandNames {
    CommandMap g_commandMap;

    void CommandRegister(const dpp::slashcommand& command, const CommandFunction& function)
    {
        g_commandMap[command.name] = function;
    }

    const CommandMap& GetCommandMap()
    {
        return g_commandMap;
    }
}