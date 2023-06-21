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

static float getRotationAngle(Zappy::Orientation orientation)
{
    // return orientation * 90 - 90;
    if (orientation == 1)
        return 0;
    if (orientation == 2)
        return 90;
    if (orientation == 3)
        return 180;
    if (orientation == 4)
        return 270;
}

void Zappy::MyModel::draw(Vector3 pose, Orientation orientation)
{
    auto orientationAngle = getRotationAngle(orientation);
    std::cout << "Orientation:" <<orientation << std::endl;
    // moveAnimation(1);
    Vector3 scale = {1.0f, 1.0f, 1.0f};
    _model.Draw(pose, (Vector3){0, 1, 0}, orientationAngle, scale, WHITE);
}

void Zappy::MyModel::moveAnimation(int i)
{
    UpdateModelAnimation(_model, _animation[i], _animFrameCounter);
    _animFrameCounter += 3;
	if (_animFrameCounter >= _animation[i].frameCount)
        _animFrameCounter = 0;
}
