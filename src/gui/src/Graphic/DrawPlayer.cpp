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

void Zappy::DrawPlayer::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
}

void Zappy::DrawPlayer::setModel()
{
    _model.insert({"babyking", std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/babyking.png")});
    _model.insert({"brennsou", std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/brennsou.png")});
    _model.insert({"girl", std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/girl.png")});
    _model.insert({"girl1", std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/girl1.png")});
    _model.insert({"kdd", std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/kdd.png")});
    _model.insert({"nezuko", std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/nezuko.png")});
    _model.insert({"nweak", std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/nweak.png")});
    _model.insert({"spiderman", std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/spiderman.png")});    
    _model.insert({"steve", std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/steve.png")});    
    _model.insert({"zirnox", std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/zirnox.png")});    
}

void Zappy::DrawPlayer::draw()
{
    auto players = _data->_gameData._player;
    auto size = _data->_gameData._tileSize;
    auto map = _data->_gameData._mapSize;
    for (const auto &element : players)
    {
        // auto id = element.first; // id
        auto player = element.second; // player class
        auto Orientation = player->getOrientation();
        player->_rotation = movePlayerRotation(Orientation, player->_rotation);
        auto pos = player->getPosition();
        auto team = player->getTeam()->getName();
        float posX = size * pos.first - (map.first / 2 * size);
        float posY = size * pos.second - (map.second / 2 * size);
        float posZ = size;
        _model["kdd"]->draw((Vector3){posX, posZ, posY},  player->_rotation, size);

        drawTeamText((Vector3){posX, posZ, posY}, player, size, team);
    }
}

void Zappy::DrawPlayer::drawTeamText(Vector3 pos, std::shared_ptr<Player> player, float size, std::string team)
{
    unsigned char tmpcolorR = (player->getTeam()->getId()) % 255;
    unsigned char tmpcolorG = tmpcolorR * 4 % 150;
    Color textColor = Color{30, tmpcolorR, 30, 255};
    if (tmpcolorR % 3 == 1)
        textColor = Color{tmpcolorR, 30, tmpcolorG, 255};
    if (tmpcolorR % 3 == 2)
        textColor = Color{30, tmpcolorR, 30, 255};
    if (tmpcolorR % 3 == 3)
        textColor = Color{tmpcolorR, 30, tmpcolorG, 255};
    _drawText3d.DrawText3D(GetFontDefault(), team.c_str(), (Vector3){pos.x - size / 6, pos.y + size * 1.2, pos.z}, textColor, size);
    _drawText3d.DrawText3D(GetFontDefault(), std::to_string(player->getId()).c_str(), (Vector3){pos.x - size / 6 + 1, pos.y + size * 1.1, pos.z}, textColor, size);
}

static float getRotationAngle(Zappy::Orientation orientation, float actualRotation)
{
    // return orientation * 90 - 90;
    if (orientation == 1 && actualRotation >= 270)
        return 360;
    if (orientation == 1)
        return 0;
    if (orientation == 2)
        return 270;
    if (orientation == 3)
        return 180;
    if (orientation == 4)
        return 90;
    return 0;
}

float Zappy::DrawPlayer::movePlayerRotation(Zappy::Orientation orientation, float actualRotation)
{
    float nextOrientation = getRotationAngle(orientation, actualRotation);
    float nbrframe = _data->_gameData._timeUnit.getActionTime(7) / _data->_gameData._timeUnit.getSecondPerFrame();
    float movement = 90 / nbrframe;
    if (movement < 1)
        movement = 1;
    if (movement > 90)
        movement = 90;
    if (nextOrientation == actualRotation)
        return actualRotation;
    if (actualRotation == 0 || actualRotation == 360)
    {
        if (nextOrientation == 270 && actualRotation == 0)
            actualRotation = 360;
        if (nextOrientation == 90 && actualRotation == 360)
            actualRotation = 0;
    }
    if (nextOrientation > actualRotation) {
        actualRotation += movement;
        if (actualRotation > nextOrientation)
            actualRotation = nextOrientation;
    }
    if (nextOrientation < actualRotation) {
        actualRotation -= movement;
        if (actualRotation < nextOrientation)
            actualRotation = nextOrientation;
    }
    return actualRotation;
}