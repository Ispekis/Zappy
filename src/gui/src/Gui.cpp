/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Gui
*/

#include "Gui.hpp"

Zappy::Gui::Gui(int port, std::string machine) : _graphic(SCREEN_WIDTH, SCREEN_HEIGHT, "Zappy"), _socket(machine, port)
{
    std::cout << "Port = " << port << std::endl;
    std::cout << "Machine = " << machine << std::endl;
}

Zappy::Gui::~Gui()
{
    if (_dataReceiver.joinable())
        _dataReceiver.join();
}

void Zappy::Gui::run()
{
    _dataReceiver = std::thread(&Zappy::Gui::receiveServerData, std::ref(*this));
    _graphic.run();
}

void Zappy::Gui::receiveServerData()
{

}