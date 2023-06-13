/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Raylib
*/

#include "Raylib.hpp"

Zappy::Raylib::Raylib(int screenWidth, int screenHeight, std::string title)
{
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), title.c_str());
    if (!IsWindowReady())
        throw Error("RayLib", "Error Init Window");
    _menu = true;
    _cameraMove = false;
    setCamera();
    setTexture();

}

void Zappy::Raylib::setCamera()
{
    _camera.position = (Vector3){ 0.0f, 40.0f, 10.0f };  // Camera position
    _camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    _camera.up = (Vector3){ 0.0f, 10.0f, 0.0f };          // Camera up vector (rotation towards target)
    _camera.fovy = 45.0f;                                // Camera field-of-view Y
    _camera.projection = CAMERA_PERSPECTIVE; 
    _cameraMode = CAMERA_ORBITAL;                       // Camera mode type
    _cameraSpeed = 0.2f;            
  
    _cameraMenu.position = (Vector3){1.0f, 1.0f, 1.0f };  // Camera position
    _cameraMenu.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    _cameraMenu.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    _cameraMenu.fovy = 70.0f;                                // Camera field-of-view Y
    _cameraMenu.projection = CAMERA_PERSPECTIVE;
    pos = {0, 0, 0};
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
}

Texture2D LoadTextureFromFile(std::string path)
{
    return LoadTexture(path.c_str());
}

void Zappy::Raylib::setTexture()
{
    _texture.insert({"Background", LoadTextureFromFile("src/gui/assets/background.png")});
    _texture.insert({"Pano0", LoadTextureFromFile("src/gui/assets/panorama_0.png")});
    _texture.insert({"Pano1", LoadTextureFromFile("src/gui/assets/panorama_1.png")});
    _texture.insert({"Pano2", LoadTextureFromFile("src/gui/assets/panorama_2.png")});
    _texture.insert({"Pano3", LoadTextureFromFile("src/gui/assets/panorama_3.png")});
    _texture.insert({"Pano4", LoadTextureFromFile("src/gui/assets/panorama_4.png")});
    _texture.insert({"Pano5", LoadTextureFromFile("src/gui/assets/panorama_5.png")});
    _texture.insert({"grassSide", LoadTextureFromFile("src/gui/assets/grass_block_side.png")});
    _texture.insert({"grassTop", LoadTextureFromFile("src/gui/assets/grass_block_top.png")});
    _texture.insert({"water", LoadTextureFromFile("src/gui/assets/water_flow.png")});
    _sprite.insert({"grass", Sprite(_texture["grassTop"], _texture["grassSide"])});
}

void Zappy::Raylib::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
}

void Zappy::Raylib::run(bool &isRunning)
{
    while (!WindowShouldClose()) {
        event();
        draw();
    }
    isRunning = false;
}

void Zappy::Raylib::cameraEvent()
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
    printf("{%2.f,%2.f,%2.f}\n", _camera.position.x, _camera.position.y, _camera.position.z);
}

void Zappy::Raylib::menuEvent()
{
}

void Zappy::Raylib::event()
{
    if (_menu == true)
        menuEvent();
    // drawMenu();;
    else
        cameraEvent();
    if(IsKeyPressed(KEY_T))
        _menu = !_menu;
}

void Zappy::Raylib::drawTile(std::size_t x, std::size_t y, std::pair<std::size_t, std::size_t> map)
{
    float size = 2.0f;
    int midX = map.first / 2;
    int midY = map.second / 2;

    float posX = size * x - (midX * size) + 1;
    float posY = size * y - (midY * size) + 1;
    float posZ = size / 2;
    DrawCubeWires((Vector3){posX, posZ, posY}, size, size, size, GREEN);
}

void Zappy::Raylib::drawMap()
{
    auto mapSize = _data->_gameData._mapSize;
    for (std::size_t x = 0; x != mapSize.first; x++)
        for (std::size_t y = 0; y != mapSize.second; y++)
            drawTile(x, y, mapSize);
    DrawGrid(10, 2.0f);
}

void Zappy::Raylib::draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (_menu == true)
        drawMenu();
    else {
        if (_data->_gameData._dataSet == true) {
            UpdateCamera(&_camera, _cameraMode);
            BeginMode3D(_camera);
            drawMap();
            EndMode3D();
        }
    }
    EndDrawing();
}

void Zappy::Raylib::drawMenu()
{
    // UpdateCamera(&_cameraMenu, CAMERA_CUSTOM);
    UpdateCameraPro(&_cameraMenu, Vector3 {0.0f,0.0f,0.0f}, Vector3{0.0f, 1.0f, 0.00f}, 0.0);
    printf("{%2.f %2.f %2.f\n}", _cameraMenu.up.x, _cameraMenu.up.y, _cameraMenu.up.z);
    BeginMode3D(_cameraMenu);
    // DrawCube(Vector3{1.0f, 1.0f, 3.0f}, 2.0f, 2.0f, 2.0f, RED);
    _sprite["grass"].drawBlockTexture(Vector3{1.0f, 1.0f, 3.0f}, Vector3{2.0f, 2.0f, 2.0f}, WHITE);
    DrawCube(Vector3{3.0f, 1.0f, 1.0f}, 2.0f, 2.0f, 2.0f, GREEN);
    DrawCube(Vector3{-1.0f, 1.0f, 1.0f}, 2.0f, 2.0f, 2.0f, BLUE);
    DrawCube(Vector3{1.0f, 1.0f, -1.0f}, 2.0f, 2.0f, 2.0f, BLACK);
    DrawCube(Vector3{1.0f, 3.0f, 1.0f}, 2.0f, 2.0f, 2.0f, YELLOW);
    DrawCube(Vector3{1.0f, -1.0f, 1.0f}, 2.0f, 2.0f, 2.0f, YELLOW);
    DrawGrid(10, 2.0f);

    EndMode3D();

}

void Zappy::Raylib::drawBackground()
{

}

Zappy::Raylib::~Raylib()
{
    std::map<std::string, Texture2D>::iterator it;
    for (it = _texture.begin(); it != _texture.end(); ++it)
            UnloadTexture(it->second);
    CloseWindow();
}
