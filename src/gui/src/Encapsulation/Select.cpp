/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Select
*/

#include "Select.hpp"

Select::Select(std::vector<int> Fds)
{
    _maxFd = 0;
    _timeout.tv_sec = 5;
    _timeout.tv_usec = 0;
    setFd(Fds);
}

Select::Select(int fd)
{
    _maxFd = fd;
    _timeout.tv_sec = 1;
    _timeout.tv_usec = 0;
    FD_ZERO(&_readfds);
    FD_SET(fd, &_readfds);
}

Select::~Select()
{
    FD_ZERO(&_readfds);
}

void Select::setFd(std::vector<int> Fds)
{
    FD_ZERO(&_readfds);
    for (auto i : Fds) {
        if (i > _maxFd)
            _maxFd = i;
        FD_SET(i, &_readfds);
    }
}

void Select::doSelect()
{
    int ready = select(_maxFd + 1, &_readfds, nullptr, nullptr, &_timeout);

    if (ready == -1)
        throw Error("Select", "Select Failed");
}