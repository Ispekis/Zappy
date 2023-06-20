/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** DrawPlayer
*/

#include "DrawPlayer.hpp"

Zappy::DrawPlayer::DrawPlayer()
{
    setModel();
}

Zappy::DrawPlayer::~DrawPlayer()
{
}

void Zappy::DrawPlayer::setModel()
{
    _model.insert({"babyking", std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/babyking.png")});
}

void Zappy::DrawPlayer::draw()
{
    _model["babyking"]->draw(Vector3 { 0.0f, 3.0f, 0.0f}, 1.5f);    
}
