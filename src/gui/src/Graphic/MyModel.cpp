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

void Zappy::MyModel::draw(Vector3 pose, float size)
{
    DrawModel(_model, pose, size, WHITE);
}

void Zappy::MyModel::moveAnimation(int animation)
{
    UpdateModelAnimation(_model, _animation[i], _animFrameCounter);
    _animFrameCounter += 3;
	if (_animFrameCounter >= _animation[i].frameCount)
        _animFrameCounter = 0;
}