#include "commands/docs.h"
#include "dotenv.h"


Langs resolveLang(const std::string& lang)
{
  if (lang == "nodejs") {
      return Langs::NodeJS;
  } else if (lang == "python")
  {
      return Langs::Python;
  } else if (lang == "cpp")
  {
      return Langs::Cpp;
  } else if (lang == "csharp")
  {
      return Langs::Csharp;
  }
};

void command_docs_run(const dpp::slashcommand_t &event, const dpp::cluster &bot)
{
    // constuindo embed

    std::variant<std::monostate, std::basic_string<char>, int64_t, bool, dpp::snowflake, double> param = event.get_parameter("linguagem");

    if (std::holds_alternative<std::string>(param))
    {

        std::string option = std::get<std::string>(param);

        std::cout << "Selected lang:" << option << std::endl;

        dpp::embed any_option = dpp::embed();
        any_option.set_title(option);
        any_option.set_footer("Textos gerados por IA do CLion", "");

        switch (resolveLang(option)) {
            case NodeJS:
                any_option.set_description("Node.js é um ambiente de execução JavaScript baseado no motor JavaScript V8 do Chrome. Ele usa um modelo de I/O (input/output) orientado a eventos e não-bloqueante, o que o torna leve e eficiente. Node.js é ideal para aplicações em tempo real com intensa troca de dados em dispositivos distribuídos.\n"
                                           "Você pode implementar várias coisas com Node.js, desde servidores web até ferramentas de linha de comando e até interfaces de desktop.\n"
                                           "O Link para a documentação oficial do Node.js pode ser encontrado aqui: https://nodejs.org/pt-br/docs");
                any_option.set_color(dpp::colors::acid_green);
                event.reply(dpp::message(event.command.channel_id, any_option));
                break;
            case Python:
                any_option.set_description("Python é uma linguagem de programação de alto nível, interpretada e de propósito geral. Sua filosofia de design enfatiza o código legível, e sua sintaxe permite que os programadores expressem conceitos em menos linhas de código do que seria possível em outras linguagens, como C++ ou Java.\n"
                                           "Python fornece suporte para vários paradigmas de programação, incluindo programação orientada a objetos, imperativa e funcional. Ele possui uma grande biblioteca padrão que suporta muitas tarefas comuns de programação, como conexões de rede, manipulação de texto, interfaces gráficas, entre outros.\n"
                                           "Python é comumente usado em áreas diversas como scripting, automação, análise de dados, aprendizado de máquina, desenvolvimento web, desenvolvimento de aplicações desktop e muito mais.\n"
                                           "O link para a documentação oficial do Python pode ser encontrado aqui: https://docs.python.org/3/");
                any_option.set_color(dpp::colors::aqua);
                event.reply(dpp::message(event.command.channel_id, any_option));
                break;
            case Cpp:
                any_option.set_description("C++ é uma linguagem de programação de propósito geral que oferece um alto grau de controle sobre o sistema e os recursos de hardware. É uma linguagem estática, de livre-forma e compilada.\n"
                                           "C++ é conhecido por sua eficiência e desempenho. Ele permite a abstração procedural e também facilita a orientação a objetos e a programação genérica.\n"
                                           "C++ é comumente usado para desenvolver jogos (onde o uso dos recursos é crítico), sistemas em tempo real, navegadores, sistemas operacionais, e muito mais. É uma das linguagens de programação mais populares e é utilizado por milhões de desenvolvedores.\n"
                                           "O C++ combinado com o ambiente de desenvolvimento integrado (IDE) CLion 2023.2 EAP fornece uma experiência de desenvolvimento poderosa e altamente personalizável.\n"
                                           "O Link para a documentação oficial do C++ pode ser encontrado aqui: https://learn.microsoft.com/en-us/dotnet/csharp/");
                any_option.set_color(dpp::colors::dark_blue);
                event.reply(dpp::message(event.command.channel_id, any_option));
                break;
            case Csharp:
                any_option.set_description("C# é uma linguagem de programação moderna, orientada a objetos e de propósitos gerais, desenvolvida pela Microsoft como parte da plataforma .NET. C# é fortemente tipada, de gerenciamento automático de memória e suporta funcionalidades de programação como classes, interfaces e herança.\n"
                                           "C# é usado comumente em uma variedade de aplicações que abrangem desde desenvolvimento de UI (user interface), acesso a bancos de dados, até a programação de jogos (o que é facilitado pela integração com a plataforma de desenvolvimento de jogos Unity). Avalia-se que é intuitiva e fácil de começar, especialmente para aqueles que já têm familiaridade com a sintaxe do Java ou do C++.\n"
                                           "O ambiente de desenvolvimento integrado (IDE) oficial para o C# é o Visual Studio, que oferece um poderoso conjunto de ferramentas para desenvolvimento em C#.\n"
                                           "O link para a documentação oficial do C# pode ser encontrado aqui: https://en.cppreference.com/w/");
                any_option.set_color(dpp::colors::light_blue);
                event.reply(dpp::message(event.command.channel_id, any_option));
                break;
        }
        
    } else {
        dpp::embed embed = dpp::embed()
                .set_title("Catalago")
                .set_color(dpp::colors::light_green)
                .add_field("NodeJS - https://nodejs.org/en/docs",
                           "Nodejs para desenvolvimento Web-front e backend multiplataforma", true)
                .add_field("Python - https://docs.python.org/3/",
                           "Python para machine learning, desenvolvimento Web-front e backend", true)
                .add_field("C++ - https://en.cppreference.com/w/",
                           "C++ para construção de sistemas simples ao complexo, desenvolvimento de jogos e API's ou Web API", false)
                .add_field("C# - https://learn.microsoft.com/en-us/dotnet/csharp/", "C# para desenvolvimento Web-front e backend" \
     "aplicativos WinForms ou wpf para Windows e desenvolvimento de jogos", false)
                .set_footer("Tenha otimos estudos!", event.command.usr.get_avatar_url());

        // referencia https://dpp.dev/structdpp_1_1interaction__create__t.html#a34f374b358f8d2d49fa93bfe5a2c0493
        // criar uma mensagem dpp::message com o paremtro snowflake de channel_id
        event.reply(dpp::message(event.command.channel_id, embed));
    }

}

void CommandNames::RegisterCInfosCommand(dpp::cluster &bot)
{
    dpp::slashcommand command("documentacoes", "Retorna vários links das documentações das linguagens", bot.me.id);

    command.add_option(
            dpp::command_option(dpp::co_string, "linguagem", "Retorna informações sobre a linguagem selecionada e a documentação", false).
                    add_choice(dpp::command_option_choice("NodeJS", std::string("nodejs"))).
                    add_choice(dpp::command_option_choice("Python", std::string("python"))).
                    add_choice(dpp::command_option_choice("C++", std::string("cpp"))).
                    add_choice(dpp::command_option_choice("C#", std::string("csharp")))
            );

    CommandNames::CommandRegister(command, [](const dpp::slashcommand_t &event, const dpp::cluster &bot)
                                  { command_docs_run(event, bot); });

    bot.global_command_create(command);
}