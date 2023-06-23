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
    _boundingBox = GetMeshBoundingBox(_model.meshes[0]);
    // setBoundingBox();
}

Zappy::MyModel::~MyModel()
{
}

void Zappy::MyModel::setCamera(raylib::Camera3D camera)
{
    _camera = camera;
}

void Zappy::MyModel::setSize(float size)
{
    _size = _size;
}

// void Zappy::MyModel::setBoundingBox()
// {
//     _boundingBox.min = Vector3 { _boundingBox.min.x * _size, _boundingBox.min.y * _size, _boundingBox.min.z * _size };
//     _boundingBox.max = Vector3 { _boundingBox.max.x * _size, _boundingBox.max.y * _size, _boundingBox.max.z * _size };
// }

void Zappy::MyModel::drawSelectedPlayer(float size)
{
    _boundingBox.min = Vector3 { _boundingBox.min.x * size, _boundingBox.min.y * size, _boundingBox.min.z * size };
    _boundingBox.max = Vector3 { _boundingBox.max.x * size, _boundingBox.max.y * size, _boundingBox.max.z * size };

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        if (GetRayCollisionBox(GetMouseRay(GetMousePosition(), _camera), _boundingBox).hit)
            _playerSelected = true;
        else
            _playerSelected = false;
    }
    if (_playerSelected)
        DrawBoundingBox(_boundingBox, RED);
}

void Zappy::MyModel::draw(Vector3 pose, float orientation, std::size_t size)
{
    // auto orientationAngle = getRotationAngle(orientation);
    // moveAnimation(1);
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