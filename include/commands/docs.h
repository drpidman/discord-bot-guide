#pragma once

#include <iostream>
#include <dpp/dpp.h>
#include "CommandNames.h"


extern void command_docs_run(const dpp::slashcommand_t& event, const dpp::cluster& bot);

namespace CommandNames {
    void RegisterCInfosCommand(dpp::cluster& bot);
}