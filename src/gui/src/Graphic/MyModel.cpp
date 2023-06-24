/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** MyModel
*/

#include "MyModel.hpp"

Zappy::MyModel::MyModel(std::string path, unsigned int animsCount, std::string texture): _animation(LoadModelAnimations(path.c_str(), &animsCount)), _model(path.c_str()), _texture(texture.c_str())
{
    SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
}

Zappy::MyModel::~MyModel()
{
}

void Zappy::MyModel::setCamera(raylib::Camera3D camera)
{
    _camera = camera;
}

static double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

bool Zappy::MyModel::drawSelectedPlayer(Vector3 position, float size, float rotation)
{
    _boundingBox = {(Vector3){ (position.x - size * 0.235), position.y, (position.z - size * 0.235)},
                        (Vector3){ (position.x + size * 0.235), position.y + size, (position.z + size * 0.235)}};

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        if (GetRayCollisionBox(GetMouseRay(GetMousePosition(), _camera), _boundingBox).hit)
            return true;
        else
            return false;
    }
}

void Zappy::MyModel::draw(Vector3 pose, float orientation, std::size_t size, bool selected)
{
    if (selected)
        DrawBoundingBox(_boundingBox, RED);
    Vector3 scale = {0.3f * size, 0.3f * size, 0.3f * size};
    _model.Draw(pose, (Vector3){0, 1, 0}, orientation, scale, WHITE);
}

void Zappy::MyModel::moveAnimation(int i, int frame)
{
    UpdateModelAnimation(_model, _animation[i], _animFrameCounter);
    _animFrameCounter += frame;

    if (_animFrameCounter >= _animation[i].frameCount) {
        UpdateModelAnimation(_model, _animation[i], _animation[i].frameCount);
        _animFrameCounter = 0;
    }
}

void Zappy::MyModel::moveAnimation(int i)
{
    UpdateModelAnimation(_model, _animation[i], _animFrameCounter);
    _animFrameCounter += 3;
	if (_animFrameCounter >= _animation[i].frameCount)
        _animFrameCounter = 0;
}

void Zappy::MyModel::moveAnimationToStart(int i)
{
    UpdateModelAnimation(_model, _animation[i], 0);
    _animFrameCounter = 0;
}

void Zappy::MyModel::changeSkin(std::string skin)
{
    _texture.Unload();
    _texture.Load(skin);
    SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
}