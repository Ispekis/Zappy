/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** GameData
*/

#include "GameData.hpp"

// Zappy::GameData::GameData()
// {
// }

Zappy::GameData::~GameData()
{
}

static void checkInt(std::vector<std::string> &content)
{
    for (auto element : content)
        for (int i = 0; i != element.size(); i++)
            if (!std::isdigit(element[i]))
                throw Error("Error server response, element is not an int", content[i]);
}

void Zappy::GameData::msz(std::vector<std::string> &content)
{
    checkInt(content);
    if (content.size() != 2)
        throw Error("Error server response MSZ args", "Expected: 2, Got: " + std::to_string(content.size()));

    _mapSize = std::make_pair(std::stoi(content[0]), std::stoi(content[1]));
    for (std::size_t x = 0; x != _mapSize.first; x++) {
        std::vector<Tile> tmp;
        for (std::size_t y = 0; y != _mapSize.second; y++)
            tmp.push_back(Tile(x, y, _factory));
        _map.push_back(tmp);
    }
}

void Zappy::GameData::bct(std::vector<std::string> &content)
{
    checkInt(content);
    if (content.size() != 9)
        throw Error("Error server response MSZ args", "Expected: 9, Got: " + std::to_string(content.size()));

    int x = std::stoi(content[0]);
    int y = std::stoi(content[1]);

    content.erase(content.begin());
    content.erase(content.begin());
    _map[x][y].setRessources(content);
    
}

void Zappy::GameData::tna(std::vector<std::string> &content)
{
    std::cout << "tna" << std::endl;
}

void Zappy::GameData::pnw(std::vector<std::string> &content)
{
    std::cout << "pnw" << std::endl;
}

void Zappy::GameData::ppo(std::vector<std::string> &content)
{
    std::cout << "ppo" << std::endl;
}

void Zappy::GameData::plv(std::vector<std::string> &content)
{
    std::cout << "plv" << std::endl;
}

void Zappy::GameData::pin(std::vector<std::string> &content)
{
    std::cout << "pin" << std::endl;
}

void Zappy::GameData::pex(std::vector<std::string> &content)
{
    std::cout << "pex" << std::endl;
}

void Zappy::GameData::pbc(std::vector<std::string> &content)
{
    std::cout << "pbc" << std::endl;
}

void Zappy::GameData::pic(std::vector<std::string> &content)
{
    std::cout << "pic" << std::endl;
}

void Zappy::GameData::pie(std::vector<std::string> &content)
{
    std::cout << "pie" << std::endl;
}

void Zappy::GameData::pfk(std::vector<std::string> &content)
{
    std::cout << "pfk" << std::endl;
}

void Zappy::GameData::pdr(std::vector<std::string> &content)
{
    std::cout << "pdr" << std::endl;
}

void Zappy::GameData::pgt(std::vector<std::string> &content)
{
    std::cout << "pgt" << std::endl;
}

void Zappy::GameData::pdi(std::vector<std::string> &content)
{
    std::cout << "pdi" << std::endl;
}

void Zappy::GameData::enw(std::vector<std::string> &content)
{
    std::cout << "enw" << std::endl;
}

void Zappy::GameData::ebo(std::vector<std::string> &content)
{
    std::cout << "ebo" << std::endl;
}

void Zappy::GameData::edi(std::vector<std::string> &content)
{
    std::cout << "edi" << std::endl;
}

void Zappy::GameData::sgt(std::vector<std::string> &content)
{
    std::cout << "sgt" << std::endl;
    checkInt(content);
    if (content.size() != 1)
        throw Error("Error server response SGT args", "Expected: 1, Got: " + std::to_string(content.size()));
    int time = std::stoi(content[0]);
    if (time < 2)
        time = 2;
    if (time > 1000)
        time = 1000;
    _timeUnit.setTimeUnit(time);
}

void Zappy::GameData::sst(std::vector<std::string> &content)
{
    std::cout << "sst" << std::endl;
}

void Zappy::GameData::seg(std::vector<std::string> &content)
{
    std::cout << "seg" << std::endl;
}

void Zappy::GameData::smg(std::vector<std::string> &content)
{
    std::cout << "smg" << std::endl;
}

void Zappy::GameData::suc(std::vector<std::string> &content)
{
    std::cout << "suc: unknow command" << std::endl;
}

void Zappy::GameData::sbp(std::vector<std::string> &content)
{
    std::cout << "sbp" << std::endl;
}
