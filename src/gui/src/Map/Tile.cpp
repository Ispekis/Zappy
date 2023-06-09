/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Tile
*/

#include "Tile.hpp"

static std::vector<std::string> splitStringIntoWords(std::string &content)
{
    std::vector<std::string> words;
    std::istringstream iss(content);
    std::string word;

    while (iss >> word)
        words.push_back(word);
    return words;
}

Zappy::Tile::Tile()
{

}

Zappy::Tile::Tile(std::size_t x, std::size_t y)
{
    _position = std::make_pair(x, y);
}

Zappy::Tile::Tile(std::string &content)
{
    auto tile = splitStringIntoWords(content);
    const char *ressource[] = {"Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame"};
    int x = std::stoi(tile[0]);
    int y = std::stoi(tile[1]);

    tile.erase(tile.begin());
    tile.erase(tile.begin());
}

Zappy::Tile::~Tile()
{
}

std::pair<std::size_t, std::size_t> Zappy::Tile::getPosition() const
{
    return _position;
}
std::vector<std::shared_ptr<Zappy::IRessource>> Zappy::Tile::getRessources() const
{
    return _ressources;
}