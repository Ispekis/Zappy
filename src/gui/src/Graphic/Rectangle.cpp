/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

Zappy::Rect::Rect(Texture2D text)
{
    _text = text;
}

void Zappy::Rect::drawRect(float width, float height, Vector2 position)
{
    Rectangle src;
    src.x = 0;
    src.y = 0;
    src.width = _text.width;
    src.height = _text.height;

    Rectangle dest;
    dest.x = position.x;
    dest.y = position.y;
    dest.width = width;
    dest.height = height;

    DrawTexturePro(_text, src, dest,  Vector2{0, 0}, 0, WHITE);
}

Zappy::Rect::~Rect()
{
}
