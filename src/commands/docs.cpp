#include "commands/docs.h"
#include "commands/CommandNames.h"
#include <dpp/dpp.h>
#include <curl/curl.h>

#include "dotenv.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void command_docs_run(const dpp::slashcommand_t &event, const dpp::cluster &bot)
{
    // constuindo embed
    dpp::embed embed = dpp::embed()
    .set_title("Catalago")
    .set_color(dpp::colors::light_green)
    .add_field("NodeJS - https://nodejs.org/en/docs",
     "Nodejs para desenvolvimento Web-front e backend multiplataforma", true)
    .add_field("Python - https://docs.python.org/3/",
     "Python para machine learning, desenvolvimento Web-front e backend", true)
    .add_field("C++ - https://learn.microsoft.com/pt-br/cpp/?view=msvc-170",
     "C++ para construção de sistemas simples ao complexo, desenvolvimento de jogos e API's ou Web API", false)
    .add_field("C# - https://learn.microsoft.com/en-us/dotnet/csharp/", "C# para desenvolvimento Web-front e backend" \
     "aplicativos WinForms ou wpf para Windows e desenvolvimento de jogos", false)
    .set_footer("Tenha um bom estudo!", event.command.usr.get_avatar_url());

    // referencia https://dpp.dev/structdpp_1_1interaction__create__t.html#a34f374b358f8d2d49fa93bfe5a2c0493
    // criar uma mensagem dpp::message com o paremtro snowflake de channel_id 
    event.reply(dpp::message(event.command.channel_id, embed));
}

void CommandNames::RegisterCInfosCommand(dpp::cluster &bot)
{
    dpp::slashcommand command("documentacoes", "Retorna vários links das documentações das linguagens", bot.me.id);

    CommandNames::CommandRegister(command, [](const dpp::slashcommand_t &event, const dpp::cluster &bot)
                                  { command_docs_run(event, bot); });

    bot.global_command_create(command);
}