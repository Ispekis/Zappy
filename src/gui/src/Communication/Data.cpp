/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Data
*/

#include "Data.hpp"

Data::Data(std::string machine, int port) : _socket(machine, port)
{
}

Data::~Data()
{
}
