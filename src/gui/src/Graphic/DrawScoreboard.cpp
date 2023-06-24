/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawScoreboard
*/

#include "DrawScoreboard.hpp"

Zappy::DrawScoreboard::DrawScoreboard()
{
}

Zappy::DrawScoreboard::~DrawScoreboard()
{
}

void Zappy::DrawScoreboard::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
}

