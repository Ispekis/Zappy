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
    std::memset(tmp, 0, sizeof(tmp));
    read(_socket._socket, tmp, sizeof(tmp));
    std::cout << tmp << std::endl;
}

void Data::writeToServer(std::string &cmd)
{
    char tmp[1024] = "msz";
    // std::string ttt = "msz";
    // int end = cmd.copy(tmp, sizeof(tmp));
    // ttt[ttt.size() - 1] = '\n';
    // tmp[end] = '\n';
    // std::cout << ttt;
    strcat(tmp, "\n");
    printf("[%s]\n", tmp);
    write(_socket._socket, tmp, sizeof(tmp));
}