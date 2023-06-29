#pragma once

#include <iostream>
#include <dpp/dpp.h>
#include "CommandNames.h"


enum Langs {
    NodeJS,
    Python,
    Cpp,
    Csharp
};

Langs resolveLang(const std::string& lang);

void command_docs_run(const dpp::slashcommand_t& event, const dpp::cluster& bot);

namespace CommandNames {
    void RegisterCInfosCommand(dpp::cluster& bot);
}