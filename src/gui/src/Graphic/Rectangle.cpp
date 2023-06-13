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

void Zappy::Rect::drawRect(float width, float height, float x, float y)
{
    Rectangle src;
    src.width = _text.width;
    src.height = _text.height;

    Rectangle dest;
    dest.width = width;
    dest.height = height;

    DrawTexturePro(_text, src, dest, Vector2{x, y}, 0, WHITE);
}

Zappy::Rect::~Rect()
{
}
