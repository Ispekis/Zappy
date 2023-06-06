/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Gui
*/

#include "Gui.hpp"

Zappy::Gui::Gui(int port, std::string machine) : _graphic(SCREEN_WIDTH, SCREEN_HEIGHT, "Zappy"), _data(machine, port)
{
    std::cout << "Port = " << port << std::endl;
    std::cout << "Machine = " << machine << std::endl;
    _isRunning = true;
}

Zappy::Gui::~Gui()
{
    if (_dataReceiver.joinable())
        _dataReceiver.join();
}

void Zappy::Gui::run()
{
    _dataReceiver = std::thread(&Zappy::Gui::receiveServerData, std::ref(*this));
    _graphic.run(_isRunning);
}

void Zappy::Gui::receiveServerData()
{
    std::string tes = "msz\n";
    while (_isRunning)
    {
        _data.readFromServer();
    }
}