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
    std::cout << "Team :" << name << "Added" << std::endl;
}

Zappy::Team::~Team()
{
}
