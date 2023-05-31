/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Parser
*/

#include "Parser.hpp"
#include <iostream>
#include <cstring>

Zappy::Parser::Parser(const int ac, char *const *av)
{
    if (ac > 5)
        throw Error("Error on argument length", "Parser");

    if (std::strcmp(av[1], "-p") == 0) {
        try {
            _port = std::stoi(av[2]);
        } catch (const std::exception &) {
            throw Error("Use a number for the port", "Parser");
        }
    } else {
        throw Error("Provide a port", "Parser");
    }

    if (ac > 3) {
        if (std::strcmp(av[3], "-h") == 0) {
            if (ac != 5)
                throw Error("Provide a name", "Parser");
            _machine = av[4];
        } else {
            throw Error("Unknown option", "Parser");
        }
    }
}

Zappy::Parser::~Parser()
{
}

int Zappy::Parser::getPort()
{
    return _port;
}

std::string Zappy::Parser::getMachine()
{
    return _machine;
}
