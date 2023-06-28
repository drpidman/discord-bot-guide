#include <dpp/dpp.h>
#include <iostream>
#include <functional>
#include <map>

namespace CommandNames {

    using CommandFunction = std::function<void(const dpp::slashcommand_t&, const dpp::cluster&)>;
    using CommandMap = std::map<std::string, CommandFunction>;

    void CommandRegister(const dpp::slashcommand& command, const CommandFunction& function);

    const CommandMap& GetCommandMap();
}