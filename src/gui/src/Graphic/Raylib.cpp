/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Raylib
*/

#include "Raylib.hpp"

Zappy::Raylib::Raylib(std::string title) : _window(GetMonitorWidth(0), GetMonitorHeight(0), title.c_str())
{
    _window.SetTargetFPS(60);
}

void Zappy::Raylib::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
    _gameplay.setData(tmp);
    _menu.setData(tmp);
}

void Zappy::Raylib::run()
{
    while (_exitWindow != true && _data->_gameData._end != true) {
        event();
        draw();
    }
    _data->_gameData._end = true;
}

void Zappy::Raylib::event()
{
    if(IsKeyPressed(KEY_T))
        _data->_gameData._menu = !_data->_gameData._menu;
    if (IsKeyPressed(KEY_ESCAPE))
        _exitWindow = true;
    if (IsKeyPressed(KEY_KP_ADD))
        _data->_gameData._tileSize++;
    if (IsKeyPressed(KEY_KP_SUBTRACT))
        _data->_gameData._tileSize--;
        
}

void Zappy::Raylib::draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (_data->_gameData._menu == true)
        _menu.run();
    else {
        if (_data->_gameData._dataSet == true) {
            _gameplay.run();
        }
    }
    EndDrawing();
}

Zappy::Raylib::~Raylib()
{
    std::cout << "Raylib Destroyed" << std::endl;
}