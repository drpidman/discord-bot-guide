#pragma once

#include <iostream>
#include <dpp/dpp.h>
#include <unordered_map>
#include "CommandNames.h"


enum class Languages {
    NodeJS,
    Python,
    Cpp,
    Csharp
};

const auto languages_description = std::unordered_map<Languages, std::string_view>{
        {Languages::NodeJS, "Node.js é um ambiente de execução JavaScript baseado no motor JavaScript V8 do Chrome. Ele usa um modelo de I/O (input/output) orientado a eventos e não-bloqueante, o que o torna leve e eficiente. Node.js é ideal para aplicações em tempo real com intensa troca de dados em dispositivos distribuídos."
                            "Você pode implementar várias coisas com Node.js, desde servidores web até ferramentas de linha de comando e até interfaces de desktop."
                            "O Link para a documentação oficial do Node.js pode ser encontrado aqui: https://nodejs.org/pt-br/docs"},
        {Languages::Python, "Python é uma linguagem de programação de alto nível, interpretada e de propósito geral. Sua filosofia de design enfatiza o código legível, e sua sintaxe permite que os programadores expressem conceitos em menos linhas de código do que seria possível em outras linguagens, como C++ ou Java."
                            "Python fornece suporte para vários paradigmas de programação, incluindo programação orientada a objetos, imperativa e funcional. Ele possui uma grande biblioteca padrão que suporta muitas tarefas comuns de programação, como conexões de rede, manipulação de texto, interfaces gráficas, entre outros."
                            "Python é comumente usado em áreas diversas como scripting, automação, análise de dados, aprendizado de máquina, desenvolvimento web, desenvolvimento de aplicações desktop e muito mais."
                            "O link para a documentação oficial do Python pode ser encontrado aqui: https://docs.python.org/3/"},
        {Languages::Cpp,"C++ é uma linguagem de programação de propósito geral que oferece um alto grau de controle sobre o sistema e os recursos de hardware. É uma linguagem estática, de livre-forma e compilada."
                            "C++ é conhecido por sua eficiência e desempenho. Ele permite a abstração procedural e também facilita a orientação a objetos e a programação genérica."
                            "C++ é comumente usado para desenvolver jogos (onde o uso dos recursos é crítico), sistemas em tempo real, navegadores, sistemas operacionais, e muito mais. É uma das linguagens de programação mais populares e é utilizado por milhões de desenvolvedores."
                            "O C++ combinado com o ambiente de desenvolvimento integrado (IDE) CLion 2023.2 EAP fornece uma experiência de desenvolvimento poderosa e altamente personalizável."
                            "O Link para a documentação oficial do C++ pode ser encontrado aqui: https://learn.microsoft.com/en-us/dotnet/csharp/"},
        {Languages::Csharp, "C# é uma linguagem de programação moderna, orientada a objetos e de propósitos gerais, desenvolvida pela Microsoft como parte da plataforma .NET. C# é fortemente tipada, de gerenciamento automático de memória e suporta funcionalidades de programação como classes, interfaces e herança."
                            "C# é usado comumente em uma variedade de aplicações que abrangem desde desenvolvimento de UI (user interface), acesso a bancos de dados, até a programação de jogos (o que é facilitado pela integração com a plataforma de desenvolvimento de jogos Unity). Avalia-se que é intuitiva e fácil de começar, especialmente para aqueles que já têm familiaridade com a sintaxe do Java ou do C++.\\n\"\n"
                            "O ambiente de desenvolvimento integrado (IDE) oficial para o C# é o Visual Studio, que oferece um poderoso conjunto de ferramentas para desenvolvimento em C#."
                            "O link para a documentação oficial do C# pode ser encontrado aqui: https://en.cppreference.com/w/"}
};


Languages resolve_lang(const std::string& lang);

void command_docs_run(const dpp::slashcommand_t& event, const dpp::cluster& bot);

namespace CommandNames {
    void RegisterCInfosCommand(dpp::cluster& bot);
}