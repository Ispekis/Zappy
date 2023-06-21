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
        auto id = element.first; // id
        auto player = element.second; // player class
        auto Orientation = player->getOrientation();
        auto pos = player->getPosition();
        float posX = size * pos.first - (map.first / 2 * size);
        float posY = size * pos.second - (map.second / 2 * size);
        float posZ = size;
        _model["kdd"]->draw((Vector3){posX, posZ, posY}, Orientation, size);
    }
}