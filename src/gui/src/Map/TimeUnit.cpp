/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** TimeUnit
*/

#include "TimeUnit.hpp"

Zappy::TimeUnit::TimeUnit()
{
    _timeUnit = 2;
}

Zappy::TimeUnit::~TimeUnit()
{
}

int Zappy::TimeUnit::getTimeUnit() const
{
    return _timeUnit;
}

void Zappy::TimeUnit::setTimeUnit(int time)
{
    std::cout << "TimeUnit set to " << time << std::endl;
    _timeUnit = time;
}