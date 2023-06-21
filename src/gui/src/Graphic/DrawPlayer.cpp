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
    _model["kdd"]->draw(Vector3 { -10.0f, 3.0f, 0.0f}, 3);
    _model["nweak"]->draw(Vector3 { -5.0f, 3.0f, 0.0f}, 3);
    _model["nezuko"]->draw(Vector3 { 0.0f, 3.0f, 0.0f}, 3);
    _model["brennsou"]->draw(Vector3 { 10.0f, 3.0f, 0.0f}, 3);
    _model["girl1"]->draw(Vector3 { 15.0f, 3.0f, 0.0f}, 3);
    _model["girl"]->draw(Vector3 { 5.0f, 3.0f, 0.0f}, 3);

    // _drawText3d.DrawText3D(GetFontDefault(), "jeras", (Vector3){ -11.0f, 10.0f, 0}, 10, 1, 1, true, RED);
}
