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

static float getRotationAngle(Zappy::Orientation orientation, float actualRotation)
{
    if (orientation == 3 && actualRotation <= -270)
        return -360;
    if (orientation == 1)
        return -180;
    if (orientation == 2)
        return -270;
    if (orientation == 3)
        return 0;
    if (orientation == 4)
        return -90;
    return 0;
}

void Zappy::DrawPlayer::setModel()
{
    // _model.insert({1, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/nezuko.png")});
    // _model.insert({2, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/nweak.png")});
    // _model.insert({3, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/kdd.png")});
    // _model.insert({4, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/babyking.png")});
    // _model.insert({5, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/brennsou.png")});
    // _model.insert({6, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/spiderman.png")});    
    // _model.insert({7, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/steve.png")});    
    // _model.insert({8, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, "src/gui/assets/skin/zirnox.png")});    
}

void Zappy::DrawPlayer::checkPlayerModel(std::shared_ptr<Player> player)
{
    std::map<std::size_t, std::string> skinLevel = {
        {1, "src/gui/assets/skin/nezuko.png"},
        {2, "src/gui/assets/skin/nweak.png"},
        {3, "src/gui/assets/skin/kdd.png"},
        {4, "src/gui/assets/skin/babyking.png"},
        {5, "src/gui/assets/skin/brennsou.png"},
        {6, "src/gui/assets/skin/spiderman.png"},
        {7, "src/gui/assets/skin/steve.png"},
        {8, "src/gui/assets/skin/zirnox.png"},
    };
    std::size_t id = player->getId();
    std::size_t actualLevel = player->getLevel();
    if (_model.count(id) == 0)
    {
        _model.insert({id, std::make_shared<MyModel>("src/gui/assets/skin/player_model.glb", 3, skinLevel[actualLevel])});
    } else {
        if (_model[id]->level != actualLevel)
            _model[id]->changeSkin(skinLevel[actualLevel]);
    }
}

void Zappy::DrawPlayer::draw(raylib::Camera &camera)
{
    _camera = camera;
    auto players = _data->_gameData._player;
    auto size = _data->_gameData._tileSize;
    auto map = _data->_gameData._mapSize;
    for (const auto &element : players)
    {
        
        // auto id = element.first; // id
        auto player = element.second; // player class
        Orientation Orientation = player->getOrientation();
        float rotation = movePlayerRotation(Orientation, player->_rotation);
        // auto pos = player->getPosition();
        std::string team = player->getTeam()->getName();
        // std::size_t level = player->getLevel();
        std::size_t id = player->getId();
        checkPlayerModel(player);
        if (rotation != 10)
            drawRotatePlayer(player);
        drawMovementPlayer(player);
        _model[id]->draw(player->_actualPosition, player->_rotation, size, player->_selected);
        drawTeamText(player->_actualPosition, player, size, team);
        _model[id]->setCamera(_camera);
        bool tmp = _model[id]->drawSelectedPlayer(player->_actualPosition, size, player->_rotation);
        if (tmp == true && player->_selected == false) {
            for (const auto &element1 : players)
                element1.second->_selected = false;
            player->_selected = true;
        } else if (tmp == true && player->_selected == true)
            player->_selected = false;
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

float Zappy::DrawPlayer::movePlayerRotation(Zappy::Orientation orientation, float actualRotation)
{
    float nextOrientation = getRotationAngle(orientation, actualRotation);
    if (nextOrientation == actualRotation)
        return 10;
        if (nextOrientation == -270 && actualRotation == 0)
            actualRotation = -360;
        if (nextOrientation == -90 && actualRotation == -360)
            actualRotation = 0;
        if (nextOrientation == -90 && actualRotation == -360)
            actualRotation = 0;
    if (nextOrientation > actualRotation) {
        actualRotation++;
        if (actualRotation > nextOrientation)
            actualRotation = nextOrientation;
    return actualRotation;
    }
    if (nextOrientation < actualRotation) {
        actualRotation--;
        if (actualRotation < nextOrientation)
            actualRotation = nextOrientation;
    return actualRotation;
    }
    return actualRotation;
}

void Zappy::DrawPlayer::drawRotatePlayer(std::shared_ptr<Player> player)
{
    float nbrframe = _data->_gameData._timeUnit.getActionTime(7) / _data->_gameData._timeUnit.getSecondPerFrame();
    float movement = 90 / nbrframe;
    int movement1 = ceil(movement);
    float size = _data->_gameData._tileSize;
    std::size_t level = player->getId();
    for (int i = 0; i != movement1; i++)
    {
        float tmp = movePlayerRotation(player->getOrientation(), player->_rotation);
        if (tmp == 10)
            break;
        player->_rotation = tmp;
        _model[level]->draw(player->_actualPosition, player->_rotation, size, player->_selected);
    }
}

static bool isEqual(float a, float b)
{
    return std::abs(a - b) < 0.01;
}

void Zappy::DrawPlayer::drawMovementPlayer(std::shared_ptr<Player> player)
{
    auto next = player->getPosition();
    auto size = _data->_gameData._tileSize;
    auto map = _data->_gameData._mapSize;
    float posX = size * next.first - (map.first / 2 * size);
    float posY = -(size * next.second - (map.second / 2 * size));
    float posZ = size;

    if (isEqual(player->_actualPosition.x, posX) == false)
        movePlayerPositionX(player,(Vector3){posX, posZ, posY});
    else if (isEqual(player->_actualPosition.z, posY) == false)
        movePlayerPositionY(player,(Vector3){posX, posZ, posY});
    else
        _model[player->getId()]->moveAnimationToStart(Animation::marche);
}

void Zappy::DrawPlayer::movePlayerPositionX(std::shared_ptr<Player> player, Vector3 target)
{
    float distance = target.x - (player->_LastPosition.x);
    float nbrframe = _data->_gameData._timeUnit.getActionTime(7) / _data->_gameData._timeUnit.getSecondPerFrame();
    float moveFrame = distance * 10 / nbrframe;
    int moveFramePerLoop = std::abs(ceil(moveFrame));
    float animFrame = 120 / nbrframe;
    int animFramePerLoop = std::abs(ceil(animFrame));
    std::size_t level = player->getLevel();
    float size = _data->_gameData._tileSize;
    float increment;

    if (distance > 0)
        increment = 0.1;
    else
        increment = -0.1;
    std::cout << "Anim per loop" << animFramePerLoop << std::endl;
    for (int i = 0; i != moveFramePerLoop  + 1; i++)
    {
        if (isEqual(player->_actualPosition.x, target.x)) {
            player->_actualPosition.x = target.x;
            // _model[level]->moveAnimationToStart(Animation::marche);
            return;
        }
        player->_actualPosition.x = player->_actualPosition.x + increment;
        _model[player->getId()]->moveAnimation(Animation::marche, animFramePerLoop);
        // _model[level]->draw(player->_actualPosition, player->_rotation, size);
    }
}

void Zappy::DrawPlayer::movePlayerPositionY(std::shared_ptr<Player> player, Vector3 target)
{
    float distance = target.z - (player->_LastPosition.z);
    float nbrframe = _data->_gameData._timeUnit.getActionTime(7) / _data->_gameData._timeUnit.getSecondPerFrame();
    float moveFrame = distance * 10 / nbrframe;
    int moveFramePerLoop = std::abs(ceil(moveFrame));
    float animFrame = 120 / nbrframe;
    int animFramePerLoop = std::abs(ceil(animFrame));
    std::size_t level = player->getLevel();
    float size = _data->_gameData._tileSize;
    float increment;

    if (distance > 0)
        increment = 0.1;
    else
        increment = -0.1;
    std::cout << "Anim per loop" << animFramePerLoop << std::endl;

    for (int i = 0; i != moveFramePerLoop + 1; i++) {
        if (isEqual(player->_actualPosition.z, target.z)) {
            // _model[level]->moveAnimationToStart(Animation::marche);
            player->_actualPosition.z = target.z;
            return;
        }
        player->_actualPosition.z = player->_actualPosition.z + increment;
        _model[player->getId()]->moveAnimation(Animation::marche, animFramePerLoop);
        // _model[level]->draw(player->_actualPosition, player->_rotation, size);
    }
}