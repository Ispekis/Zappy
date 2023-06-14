/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** BroadCast
*/

#include "BroadCast.hpp"

Zappy::BroadCast::BroadCast(std::size_t playerId, std::pair<std::size_t, std::size_t> position, std::string message)
{
    _playerId = playerId;
    _position = position;
    _message = message;
}

Zappy::BroadCast::~BroadCast()
{
}
