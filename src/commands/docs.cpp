#include "commands/docs.h"
#include "dotenv.h"


Languages resolve_lang(const std::string& lang)
{
    // nodejs
    // python
    // cpp
    // csharp
  if (lang == "nodejs") {
      return Languages::NodeJS;
  } else if (lang == "python")
  {
      return Languages::Python;
  } else if (lang == "cpp")
  {
      return Languages::Cpp;
  } else if (lang == "csharp")
  {
      return Languages::Csharp;
  } else {
      throw std::invalid_argument("Ops, parece não ter nada aqui");
  }
}

void command_docs_run(const dpp::slashcommand_t &event, const dpp::cluster &bot)
{
    // constuindo embed
    dpp::embed embed = dpp::embed();

    std::variant<std::monostate, std::basic_string<char>, int64_t, bool, dpp::snowflake, double> param = event.get_parameter("linguagem");

    if (std::holds_alternative<std::string>(param))
    {
        std::string option = std::get<std::string>(param);
        Languages lang = resolve_lang(option);

        embed.set_title(option);
        embed.set_color(dpp::colors::acid_green);
        embed.set_description(languages_description.at(lang).begin());
        embed.set_footer(bot.me.username, bot.me.get_default_avatar_url());
    }

    // referencia https://dpp.dev/structdpp_1_1interaction__create__t.html#a34f374b358f8d2d49fa93bfe5a2c0493
    // criar uma mensagem dpp::message com o paremtro snowflake de channel_id
    event.reply(dpp::message(event.command.channel_id, embed));
}

void CommandNames::RegisterCInfosCommand(dpp::cluster &bot)
{
    dpp::slashcommand command("documentacoes", "Retorna vários links das documentações das linguagens", bot.me.id);

    command.add_option(
            dpp::command_option(dpp::co_string, "linguagem", "Retorna informações sobre a linguagem selecionada e a documentação", true).
                    add_choice(dpp::command_option_choice("NodeJS", std::string("nodejs"))).
                    add_choice(dpp::command_option_choice("Python", std::string("python"))).
                    add_choice(dpp::command_option_choice("C++", std::string("cpp"))).
                    add_choice(dpp::command_option_choice("C#", std::string("csharp")))
            );

    CommandNames::CommandRegister(command, [](const dpp::slashcommand_t &event, const dpp::cluster &bot)
                                  { command_docs_run(event, bot); });

    bot.global_command_create(command);
}