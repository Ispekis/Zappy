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

    std::cout << "Message Graphic send to server" << std::endl;
    writeToServer("GRAPHIC\n");
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
            std::cout << "before" << std::endl;
            readFromServer();
            std::cout << "AFTEE" << std::endl;
        }
    } catch (const Error &e) {
        std::cout << e.what() << std::endl;
    }
}

void Data::readFromServer()
{
    int byteRead = -1;

    char tmp[15];
    while (byteRead != 0)
    {
        byteRead = read(_socket._socket, tmp, sizeof(tmp));
        if (byteRead == -1)
            break;
        printf("[%s] ", tmp);
        std::memset(tmp, 0, sizeof(tmp));
    }
    printf("\nend of Reading\n", tmp);

}

void Data::writeToServer(char *str)
{
    printf("[%s]\n", str);
    write(_socket._socket, str, sizeof(str));
}