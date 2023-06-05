/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Raylib
*/

#include "Raylib.hpp"

Zappy::Raylib::Raylib(int screenWidth, int screenHeight, std::string title)
{
    InitWindow(screenWidth, screenHeight, title.c_str());
    createWindow();
}

void Zappy::Raylib::createWindow()
{
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
}

Zappy::Raylib::~Raylib()
{
    CloseWindow();
}
