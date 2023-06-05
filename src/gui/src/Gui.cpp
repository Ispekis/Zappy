/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Gui
*/

#include "Gui.hpp"

Zappy::Gui::Gui(int port, std::string machine) : _graphic(SCREEN_WIDTH, SCREEN_HEIGHT, "Zappy")
{
    std::cout << "Port = " << port << std::endl;
    std::cout << "Machine = " << machine << std::endl;
}

Zappy::Gui::~Gui()
{
}

void Zappy::Gui::run()
{
    _graphic.run();
}