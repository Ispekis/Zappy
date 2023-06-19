/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Gameplay
*/

#include "Gameplay.hpp"

Zappy::Gameplay::Gameplay()
{
    setCamera();
}

Zappy::Gameplay::~Gameplay()
{
    std::cout << "Gameplay Destroyed" << std::endl;
}

void Zappy::Gameplay::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
    _worldMap.setData(tmp);
}

void Zappy::Gameplay::setCamera()
{
    _camera.position = (Vector3){0.0f, 40.0f, 20.0f};    // Camera position
    _camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    _camera.up = (Vector3){ 0.0f, 10.0f, 0.0f };          // Camera up vector (rotation towards target)
    _camera.fovy = 45.0f;                                // Camera field-of-view Y
    _camera.projection = CAMERA_PERSPECTIVE;
    _cameraMove = false;
    _cameraMode = CAMERA_ORBITAL;
}

void Zappy::Gameplay::run()
{
    event();
    draw();
}

void Zappy::Gameplay::event()
{
    cameraEvent();
}

void Zappy::Gameplay::cameraEvent()
{
    if (IsKeyPressed(KEY_SPACE)) {
        _cameraMove = !_cameraMove;
    }
    if (IsKeyPressed(KEY_R)) {
        _camera.position = (Vector3){0.0f, 60.0f, 20.0f};    // Camera position
        _camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    }
    if (_cameraMove == true) {
        _camera.Update(CAMERA_ORBITAL);
        return;
    }
    Vector3 position = {0.0, 0.0, 0.0};
    if (IsKeyDown(KEY_LEFT)) {
        position.y = -0.5f;
        _camera.target = (Vector3){0.0f, 0.0f, 0.0f}; // Camera looking at point
    }
    if (IsKeyDown(KEY_RIGHT)) {
        position.y = 0.5f;
        _camera.target = (Vector3){0.0f, 0.0f, 0.0f}; // Camera looking at point
    }
    if (IsKeyDown(KEY_UP)) {
        position.z = 0.5f;
        _camera.target = (Vector3){0.0f, 0.0f, 0.0f}; // Camera looking at point
    }
    if (IsKeyDown(KEY_DOWN)) {
        position.z = -0.5f;
        _camera.target = (Vector3){0.0f, 0.0f, 0.0f}; // Camera looking at point
    }
    if (IsKeyDown(KEY_W))
        position.x = 0.5f;
    if (IsKeyDown(KEY_S))
        position.x = -0.5f;
    if (IsKeyDown(KEY_A))
        position.y = -0.5f;
    if (IsKeyDown(KEY_D))
        position.y = 0.5f;
    _camera.Update(position, Vector3{0.0f, 0.0000f, 0.0f}, 0.0);
}

void Zappy::Gameplay::draw()
{
    _camera.BeginMode();
    _worldMap.draw();
    _camera.EndMode();
}

bool Zappy::Gameplay::tilehover(float posX, float posY, float posZ, float size)
{
    RayCollision collision;
    Ray ray;
    ray = GetMouseRay(GetMousePosition(), _camera);
    collision = GetRayCollisionBox(ray, (BoundingBox){(Vector3){ posX - size/2, posZ + size/2, posY - size/2 },
                                                      (Vector3){ posX + size/2, posZ + size/2, posY + size/2 }});
    if (collision.hit)
        DrawCubeWiresV((Vector3){posX, posZ + size / 2, posY}, (Vector3){size,  0.5, size}, RED);
}