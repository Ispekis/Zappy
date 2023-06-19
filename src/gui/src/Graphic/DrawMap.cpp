/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawMap
*/

#include "DrawMap.hpp"

Zappy::DrawMap::DrawMap()
{
    setTexture();
    setCube();
}

Zappy::DrawMap::~DrawMap()
{
}

void Zappy::DrawMap::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
    _items.setData(tmp);
}

void Zappy::DrawMap::setTexture()
{
    _texture.insert({"grassSide", raylib::Texture("src/gui/assets/grass_block_side.png")});
    _texture.insert({"grassTop", raylib::Texture("src/gui/assets/grass_block_top.png")});
    _texture.insert({"water", raylib::Texture("src/gui/assets/water_flow.png")});
    _texture.insert({"dirt", raylib::Texture("src/gui/assets/dirt.png")});
    _texture.insert({"clearbackground", raylib::Texture("src/gui/assets/clearbackground.png")});

    _shader.insert({"waterWave", LoadShader(0, TextFormat("src/gui/assets/shaders/wave.fs"))});

}

void Zappy::DrawMap::setCube()
{
    _cube.insert({"water", Cube(_texture["water"].GetId(), _texture["clearbackground"].GetId(), _texture["water"].GetId(), _shader["waterWave"])});
    _cube.insert({"grass", Cube(_texture["grassTop"].GetId(), _texture["grassSide"].GetId(), _texture["dirt"].GetId())});
}

void Zappy::DrawMap::draw()
{
    drawMap();
}

void Zappy::DrawMap::drawMap()
{
   auto mapSize = _data->_gameData._mapSize;
    for (std::size_t x = 0; x != mapSize.first; x++)
        for (std::size_t y = 0; y != mapSize.second; y++) {
            drawTile(x, y, mapSize);
        }
    _cube["water"].drawWaterTexture((Vector3){0, 0.9, 0}, (Vector3){200, 0.9, 200}, GRAY);

}

void Zappy::DrawMap::drawTile(std::size_t x, std::size_t y, std::pair<std::size_t, std::size_t> map)
{
    RayCollision collision;
    Ray ray;

    float size = 3.0f;
    int midX = map.first / 2;
    int midY = map.second / 2;
    float posX = size * x - (midX * size);
    float posY = size * y - (midY * size);
    float posZ = size / 2;

    // tilehover(posX, posY, posZ, size);
    _cube["grass"].drawBlockTexture((Vector3){posX, posZ, posY}, (Vector3){size, size, size}, WHITE);
    _items.drawItems((Vector3){posX, posY, posZ}, size, _data->_gameData._map[x][y].getRessources());

}
