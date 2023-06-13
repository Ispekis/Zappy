/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Player
*/

#include "Player.hpp"

Zappy::Player::Player(std::vector<std::string> &content, std::shared_ptr<Team> team)
{
    _id = std::stoi(content[0]);
    _incantation = false;
    _level = std::stoi(content[4]);
    _orientation = static_cast<Orientation>(std::stoi(content[3]));
    _position = {std::stoi(content[1]), std::stoi(content[2])};
    _team = team;
    std::cout << "Set" << std::endl;
    for (auto &element : ressource)
        _inventory.insert({element, 0});
}

Zappy::Player::~Player()
{
}

std::size_t Zappy::Player::getId() const
{
    return _id;
}

std::pair<std::size_t, std::size_t> Zappy::Player::getPosition() const
{
    return _position;
}

std::unordered_map<std::string, std::size_t> Zappy::Player::getInventory() const
{
    return _inventory;
}

Zappy::Orientation Zappy::Player::getOrientation() const
{
    return _orientation;
}

std::shared_ptr<Zappy::Team> Zappy::Player::getTeam() const
{
    return _team;
}

std::size_t Zappy::Player::getLevel() const
{
    return _level;
}

void Zappy::Player::setPosition(std::pair<std::size_t, std::size_t> newPosition)
{
    _position = newPosition;
}

void Zappy::Player::setInventory(std::vector<std::string> newInventory)
{
    // std::vector<std::string> ressource = {"Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame"};
    for (std::size_t i = 0; i != newInventory.size() - 1; i++)
        _inventory[ressource[i]] = std::stoul(newInventory[i]);
}

void Zappy::Player::setOrientation(Orientation newOrientation)
{
    _orientation = newOrientation;
}

void Zappy::Player::setLevel(std::size_t newLevel)
{
    _level = newLevel;
}

void Zappy::Player::setIncantation(bool state)
{
    _incantation = state;
}
