/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Team
*/

#include "Team.hpp"

Zappy::Team::Team(std::string name)
{
    _name = name;
    std::cout << "Team :[" << name << "]Created" << std::endl;
}

Zappy::Team::~Team()
{
}

void Zappy::Team::addPlayer(std::size_t player)
{
    _playerList.push_back(player);
    std::cout << player << " added from the team:" << _name << std::endl;
}

void Zappy::Team::deletePlayer(std::size_t player)
{
    for (std::size_t i = 0; i != _playerList.size(); i++)
        if (_playerList[i] == player) {
            _playerList.erase(_playerList.begin() + i);
            break;
        }
    std::cout << player << " deleted from the team:" << _name << std::endl;
}