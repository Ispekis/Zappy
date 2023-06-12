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
    _camera.position = (Vector3){ 0.0f, 40.0f, 10.0f };  // Camera position
    _camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    _camera.up = (Vector3){ 0.0f, 10.0f, 0.0f };          // Camera up vector (rotation towards target)
    _camera.fovy = 45.0f;                                // Camera field-of-view Y
    _camera.projection = CAMERA_PERSPECTIVE; 
    _cameraMode = CAMERA_ORBITAL;                       // Camera mode type
    _cameraSpeed = 0.2f;                                // Camera speed
    SetTargetFPS(60);                                   // Set our game to run at 60 frames-per-second
}

void Zappy::Raylib::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
    std::cout << "Data 1:" << &data << std::endl;
    std::cout << "Data 2:" << &_data << std::endl;
}

void Zappy::Raylib::run(bool &isRunning)
{
    while (!WindowShouldClose()) {
        event();
        draw();
    }
    isRunning = false;
}

void Zappy::Raylib::cameraEvent()
{
    if (IsKeyDown(KEY_SPACE))
        _cameraMode = CAMERA_THIRD_PERSON;
    if (IsKeyDown(KEY_RIGHT))
        _camera.position.x += _cameraSpeed;
    else if (IsKeyDown(KEY_LEFT))
        _camera.position.x -= _cameraSpeed;

    if (IsKeyDown(KEY_UP))
        _camera.position.z -= _cameraSpeed;
    else if (IsKeyDown(KEY_DOWN))
        _camera.position.z += _cameraSpeed;

    if (IsKeyPressed(KEY_KP_SUBTRACT))
        _camera.fovy += 3.0f;
    else if (IsKeyPressed(KEY_KP_ADD))
        _camera.fovy -= 3.0f;
}

void Zappy::Raylib::event()
{
    cameraEvent();
}

void Zappy::Raylib::drawTile(std::size_t x, std::size_t y, std::pair<std::size_t, std::size_t> map)
{
    float size = 2.0f;
    int midX = map.first / 2;
    int midY = map.second / 2;

    float posX = size * x - (midX * size) + 1;
    float posY = size * y - (midY * size) + 1;
    float posZ = size / 2;
    DrawCubeWires((Vector3){posX, posZ, posY}, size, size, size, GREEN);
}

void Zappy::Raylib::drawMap()
{
    auto mapSize = _data->_gameData._mapSize;
    for (std::size_t x = 0; x != mapSize.first; x++)
        for (std::size_t y = 0; y != mapSize.second; y++)
            drawTile(x, y, mapSize);
    // std::cout << "X:" << mapSize.first << std::endl;
    // std::cout << "Y:" << mapSize.second << std::endl;
    // DrawCube((Vector3){ 1.0f, 1.0f, 1.0f}, 2.0f, 2.0f, 2.0f, RED);
    // DrawCube((Vector3){ 1.0f, 3.0f, 1.0f}, 2.0f, 2.0f, 2.0f, RED);
    DrawGrid(10, 2.0f);
}

void Zappy::Raylib::draw()
{
    UpdateCamera(&_camera, _cameraMode);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(_camera);
    if (_data->_gameData._dataSet == true)
        drawMap();
    EndMode3D();
    EndDrawing();
}

Zappy::Raylib::~Raylib()
{
    CloseWindow();
}
