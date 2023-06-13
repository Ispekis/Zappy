/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Sprite
*/

#include "Sprite.hpp"

Zappy::Sprite::Sprite(Texture2D top, Texture2D side, Texture2D bot)
{
    _top = top;
    _side = side;
    _bot = bot;
}

void Zappy::Sprite::setTexture()
{
}

void Zappy::Sprite::setPosition()
{
}

void Zappy::Sprite::setScale()
{
}

Zappy::Sprite::~Sprite()
{
    // UnloadTexture(sideTexture.grass);
    // UnloadTexture(topTexture.grass);
    // UnloadTexture(sideTexture.water);
    // UnloadTexture(topTexture.water);
    // // UnloadTexture(sprite.button);
}

void Zappy::Sprite::drawBlockTexture(Vector3 position, Vector3 size, Color color)
{
    float x = position.x;
    float y = position.y;
    float z = position.z;

    float width = size.x;
    float height = size.y;
    float length = size.z;

    rlSetTexture(_side.id);
        rlBegin(RL_QUADS);
            rlColor4ub(color.r, color.g, color.b, color.a);

            // rlNormal3f(0.0f, 0.0f, 1.0f);
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width/2, y + height/2, z + length/2);
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width/2, y + height/2, z + length/2);
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width/2, y - height/2, z + length/2);
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width/2, y - height/2, z + length/2);
            
            // rlNormal3f(0.0f, 0.0f, - 1.0f);
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width/2, y + height/2, z - length/2);
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width/2, y - height/2, z - length/2);
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width/2, y - height/2, z - length/2);
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width/2, y + height/2, z - length/2);

            // rlNormal3f(1.0f, 0.0f, 0.0f);
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width/2, y + height/2, z - length/2);
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width/2, y - height/2, z - length/2);
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width/2, y - height/2, z + length/2);
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width/2, y + height/2, z + length/2);

            // rlNormal3f( - 1.0f, 0.0f, 0.0f);
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width/2, y + height/2, z - length/2);
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width/2, y + height/2, z + length/2);
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width/2, y - height/2, z + length/2);
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width/2, y - height/2, z - length/2);
        rlEnd();

    rlSetTexture(_top.id);
        rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width/2, y + height/2, z - length/2);
        rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width/2, y + height/2, z + length/2);
        rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width/2, y + height/2, z + length/2);
        rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width/2, y + height/2, z - length/2);
    rlEnd();

    rlSetTexture(_bot.id);
        rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width/2, y - height/2, z - length/2);
        rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width/2, y - height/2, z - length/2);
        rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width/2, y - height/2, z + length/2);
        rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width/2, y - height/2, z + length/2);
    rlEnd();

    rlSetTexture(0);
}
