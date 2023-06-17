/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Gameplay
*/

#include "Gameplay.hpp"

Zappy::Gameplay::Gameplay()
{
    setCamera();
    setTexture();
    setCube();
}

Zappy::Gameplay::~Gameplay()
{
    std::cout << "Gameplay Destroyed" << std::endl;
}

void Zappy::Gameplay::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
}

void Zappy::Gameplay::setCamera()
{
    _camera.position = (Vector3){0.0f, 40.0f, 10.0f};    // Camera position
    _camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    _camera.up = (Vector3){ 0.0f, 10.0f, 0.0f };          // Camera up vector (rotation towards target)
    _camera.fovy = 45.0f;                                // Camera field-of-view Y
    _camera.projection = CAMERA_PERSPECTIVE;
    _cameraMove = false;
    _cameraMode = CAMERA_ORBITAL;
}

void Zappy::Gameplay::setTexture()
{
    _shader.insert({"waterWave", LoadShader(0, TextFormat("src/gui/assets/shaders/wave.fs"))});

    _texture.insert({"grassSide", raylib::Texture("src/gui/assets/grass_block_side.png")});
    _texture.insert({"grassTop", raylib::Texture("src/gui/assets/grass_block_top.png")});
    _texture.insert({"water", raylib::Texture("src/gui/assets/water_flow.png")});
    _texture.insert({"dirt", raylib::Texture("src/gui/assets/dirt.png")});
    _texture.insert({"clearbackground", raylib::Texture("src/gui/assets/clearbackground.png")});

    _texture.insert({"beef", raylib::Texture("src/gui/assets/beef_cooked.png")});
    _texture.insert({"carrot", raylib::Texture("src/gui/assets/carrot_golden.png")});
    _texture.insert({"coal", raylib::Texture("src/gui/assets/coal.png")});
    _texture.insert({"diamond", raylib::Texture("src/gui/assets/diamond.png")});
    _texture.insert({"emerald", raylib::Texture("src/gui/assets/emerald.png")});
    _texture.insert({"gold", raylib::Texture("src/gui/assets/gold_ingot.png")});
    _texture.insert({"iron", raylib::Texture("src/gui/assets/iron_ingot.png")});
    _texture.insert({"netherStar", raylib::Texture("src/gui/assets/nether_star.png")});
    _texture.insert({"quartz", raylib::Texture("src/gui/assets/quartz.png")});
}

void Zappy::Gameplay::setCube()
{
    _cube.insert({"water", Cube(_texture["water"].GetId(), _texture["clearbackground"].GetId(), _texture["water"].GetId(), _shader["waterWave"])});
    _cube.insert({"grass", Cube(_texture["grassTop"].GetId(), _texture["grassSide"].GetId(), _texture["dirt"].GetId())});
    _cube.insert({"beef", Cube(_texture["beef"].GetId())});
    _cube.insert({"carrot", Cube(_texture["carrot"].GetId())});
    _cube.insert({"coal", Cube(_texture["coal"].GetId())});
    _cube.insert({"diamond", Cube(_texture["diamond"].GetId())});
    _cube.insert({"emerald", Cube(_texture["emerald"].GetId())});
    _cube.insert({"gold", Cube(_texture["gold"].GetId())});
    _cube.insert({"iron", Cube(_texture["iron"].GetId())});
    _cube.insert({"netherStar", Cube(_texture["netherStar"].GetId())});
    _cube.insert({"quartz", Cube(_texture["quartz"].GetId())});
}

void Zappy::Gameplay::run()
{
    event();
    draw();
}

void Zappy::Gameplay::event()
{
    cameraEvent();
}

void Zappy::Gameplay::cameraEvent()
{
    if (IsKeyPressed(KEY_SPACE))
        _cameraMove = !_cameraMove;
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT)) {
        _cameraMode = CAMERA_THIRD_PERSON;
        return;
    }
    if (_cameraMove == true)
        _cameraMode = CAMERA_ORBITAL;
    else 
        _cameraMode = CAMERA_THIRD_PERSON;
}

void Zappy::Gameplay::draw()
{
    _camera.Update(_cameraMode);
    _camera.BeginMode();
    drawMap();
     _camera.EndMode();
}

void Zappy::Gameplay::drawMap()
{
    auto mapSize = _data->_gameData._mapSize;
    for (std::size_t x = 0; x != mapSize.first; x++)
        for (std::size_t y = 0; y != mapSize.second; y++) {
            drawTile(x, y, mapSize);
        }

    _cube["water"].drawWaterTexture((Vector3){0, 0.9, 0}, (Vector3){200, 0.9, 200}, GRAY);
    for (std::size_t x = 0; x != mapSize.first; x++)
        for (std::size_t y = 0; y != mapSize.second; y++) {
            drawItem(x, y, mapSize);
        }
    DrawGrid(10, 2.0f);
    // DrawFPS(10, 10);
}

void Zappy::Gameplay::drawTile(std::size_t x, std::size_t y, std::pair<std::size_t, std::size_t> map)
{
    float size = 2.0f;
    int midX = map.first / 2;
    int midY = map.second / 2;

    float posX = size * x - (midX * size) + 1;
    float posY = size * y - (midY * size) + 1;
    float posZ = size / 2;
    DrawCubeWiresV((Vector3){posX, posZ, posY}, (Vector3){size, size, size}, BLACK);
    _cube["grass"].drawBlockTexture((Vector3){posX, posZ, posY}, (Vector3){size, size, size}, WHITE);
}

void Zappy::Gameplay::drawItem(std::size_t x, std::size_t y, std::pair<std::size_t, std::size_t> map)
{
    float size = 2.0f;
    int midX = map.first / 2;
    int midY = map.second / 2;

    float posX = size * x - (midX * size) + 1;
    float posY = size * y - (midY * size) + 1;
    float posZ = size / 2;
    _cube["netherStar"].drawItemTexture((Vector3){0, posZ + size, 0}, (Vector3){size, size, size}, WHITE);
}