/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Data
*/

#include "Data.hpp"

Data::Data(std::string machine, int port) : _socket(machine, port)
{
    _machine = machine;
}

Data::~Data()
{
}

void Data::readFromServer()
{
    char tmp[1024];
    read(_socket._socket ,tmp, sizeof(tmp));
    std::cout << tmp << std::endl;
}