/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Data
*/

#include "Data.hpp"

Data::Data(std::string machine, int port) : _socket(machine, port), _select(_socket._socket)
{
    _machine = machine;
    char graphic[] = "GRAPHIC\n";
    std::cout << "Message Graphic send to server" << std::endl;
    writeToServer(graphic);
}

Data::~Data()
{

}

void Data::updateGame()
{
    try {
        _select.doSelect();
        if (FD_ISSET(_socket._socket, &(_select._readfds)))
        {
            readFromServer();
        }
    } catch (const Error &e) {
        std::cout << e.what() << std::endl;
    }
}

void Data::readFromServer()
{
    char tmp[10];
    int x = read(_socket._socket, &tmp, sizeof(tmp));
    buffer.append(tmp, x);
    std::memset(tmp, 0, sizeof(tmp));
    validResponse();
}

void Data::validResponse()
{
    int pos = buffer.find('\n');
    std::string response;
    std::string tmp;
    while (pos != std::string::npos)
    {
        response = buffer.substr(0, pos);
        printf("[%s]\n", response.c_str());
        buffer = buffer.substr(pos + 1);
        pos = buffer.find('\n');
    }
}

void Data::writeToServer(char *str)
{
    printf("[%s]\n", str);
    write(_socket._socket, str, sizeof(str));
}