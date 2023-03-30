/* Usando Json:
====================================== */
#include <iostream>
#include <fstream>
#include "json.hpp" // Adicione o arquivo para teste, caso for preciso, edite o nome no código
#include "pugixml.hpp" // Adicione o arquivo para teste, caso for preciso, edite o nome no código

using json = nlohmann::json;

int main()
{
    // abrir o arquivo JSON
    std::ifstream ifs("dados.json");
    if (!ifs.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo.\n";
        return 1;
    }

    // ler o conteúdo do arquivo JSON
    json j;
    try
    {
        j = json::parse(ifs);
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Erro ao fazer o parse do JSON: " << ex.what() << "\n";
        return 1;
    }

    // acessar os dados do JSON
    int menor = j[0];
    int maior = j[0];
    int soma = 0;
    int count = 0;
    for (auto& valor : j)
    {
        if (valor < menor)
        {
            menor = valor;
        }
        if (valor > maior)
        {
            maior = valor;
        }
        soma += valor;
        count++;
    }
    double media = static_cast<double>(soma) / static_cast<double>(count);

    // imprimir os resultados
    std::cout << "Menor valor: " << menor << "\n";
    std::cout << "Maior valor: " << maior << "\n";
    std::cout << "Média mensal: " << media << "\n";
    int acima_media = 0;
    for (auto& valor : j)
    {
        if (valor > media)
        {
            acima_media++;
        }
    }
    std::cout << "Dias com faturamento acima da média: " << acima_media << "\n";

    return 0;
}




/* ====================================================
Usando XML:
==================================================== */
// Usei Outra função main por questões de erro ao usar o json e XML junto, por isso o código abaixo está comentado.

/* int main()
{
    // abrir o arquivo XML
    std::ifstream ifs("dados.xml");
    if (!ifs.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo.\n";
        return 1;
    }

    // ler o conteúdo do arquivo XML
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load(ifs);
    if (!result)
    {
        std::cerr << "Erro ao fazer o parse do XML: " << result.description() << "\n";
        return 1;
    }
    // acessar os dados
} */