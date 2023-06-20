/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawMap
*/

#include "DrawMap.hpp"

Zappy::DrawMap::DrawMap() : _camera()
{
    setTexture();
    setCube();
    std::cout << "----------------" << GetCurrentMonitor() << std::endl;
    _windowSize = {GetMonitorWidth(0), GetMonitorHeight(0)};
}

Zappy::DrawMap::~DrawMap()
{
    UnloadShader(_shader["waterWave"]);
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

void Zappy::DrawMap::draw(raylib::Camera3D &camera)
{
    _camera = camera;
    _camera.BeginMode();
    drawMap();
    drawSelectedTile();
    _camera.EndMode();
    drawBlockInformation();
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

    int ret = tilehover(posX, posY, posZ, size);
    tileSelection(x, y, ret);
    _cube["grass"].drawBlockTexture((Vector3){posX, posZ, posY}, (Vector3){size, size, size}, WHITE);
    _items.drawItems((Vector3){posX, posY, posZ}, size, _data->_gameData._map[x][y].getRessources());
}

void Zappy::DrawMap::drawSelectedTile()
{
    if (_lastTile.first == 2000)
        return;
    auto map = _data->_gameData._mapSize;
    float size = 3.0f;
    int midX = map.first / 2;
    int midY = map.second / 2;
    float posX = size * _lastTile.first - (midX * size);
    float posY = size * _lastTile.second - (midY * size);
    float posZ = size / 2;
    if (_data->_gameData._map[_lastTile.first][_lastTile.second]._selected == true)
        DrawCubeWiresV((Vector3){posX, posZ + size / 2 + 1, posY}, (Vector3){size,  2, size}, GREEN);
}

void Zappy::DrawMap::drawBlockInformation()
{
    if (_lastTile.first == 2000)
        return;
    int rectWidth = 250;
    int rectHeight = 113;
    int x = _windowSize.first / 2 - rectWidth / 2;
    int y = _windowSize.second  - rectHeight - 113;
    
    DrawRectangle(x, y, rectWidth, rectHeight, Fade(SKYBLUE, 0.5f));
    // DrawRectangleLines( 10, 10, 250, 113, BLUE);
}

void Zappy::DrawMap::tileSelection(std::size_t x, std::size_t y, int ret)
{
    if (ret == 1)
    {
        if (_data->_gameData._map[x][y]._selected == true) {
            _data->_gameData._map[x][y]._selected = false;
            _lastTile = {2000, 2000};
        } else {
            _data->_gameData._map[x][y]._selected = true;
            if (_lastTile.first != 2000)
                _data->_gameData._map[_lastTile.first][_lastTile.second]._selected = false;
            _lastTile = {x, y};
        }
    }
}

int Zappy::DrawMap::tilehover(float posX, float posY, float posZ, float size)
{
    RayCollision collision;
    Ray ray;
    ray = GetMouseRay(GetMousePosition(), _camera);
    collision = GetRayCollisionBox(ray, (BoundingBox){(Vector3){ posX - size/2, posZ + size/2, posY - size/2 },
                                                      (Vector3){ posX + size/2, posZ + size/2, posY + size/2 }});
    if (collision.hit)
        DrawCubeWiresV((Vector3){posX, posZ + size / 2, posY}, (Vector3){size,  0.5, size}, RED);
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && collision.hit)
        return 1;
    return 0;
}
