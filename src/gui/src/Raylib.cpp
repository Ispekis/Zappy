/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Raylib
*/

#include "Raylib.hpp"

Zappy::Raylib::Raylib(int screenWidth, int screenHeight, std::string title)
{
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), title.c_str());
    if (!IsWindowReady())
        throw Error("RayLib", "Error Init Window");
    SetTargetFPS(60);
}

void Zappy::Raylib::run(bool &isRunning)
{
    while (!WindowShouldClose()) {
        event();
        draw();
    }
    isRunning = false;
}

void Zappy::Raylib::event()
{

}

void Zappy::Raylib::draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
}

Zappy::Raylib::~Raylib()
{
    CloseWindow();
}
