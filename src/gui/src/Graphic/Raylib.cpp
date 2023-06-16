/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Raylib
*/

#include "Raylib.hpp"

Zappy::Raylib::Raylib(std::string title) : _window(GetMonitorWidth(0), GetMonitorHeight(0), title.c_str())
{
    InitAudioDevice();
    if (!IsWindowReady())
        throw Error("RayLib", "Error Init Window");
    _menu = true;
    _cameraMove = false;
    setCamera();
    setTexture();
    setMusic();
}

void Zappy::Raylib::setMusic()
{
    _music = LoadMusicStream("src/gui/assets/Minecraft-Theme Song {Extended for 30 Minutes}.mp3");
    _click = LoadSound("src/gui/assets/ButtonPlate Click (Minecraft Sound) - Sound Effect for editing.wav");
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
    _cameraMenu.target = (Vector3){1.0f, 1.0f, 1.0f + 2};      // Camera looking at point
    _cameraMenu.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    _cameraMenu.fovy = 70.0f;                                // Camera field-of-view Y
    _cameraMenu.projection = CAMERA_PERSPECTIVE;
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
}

// Texture2D raylib::Texture(std::string path)
// {
//     return LoadTexture(path.c_str());
// }

void Zappy::Raylib::setTexture()
{

    _shader.insert({"waterWave", LoadShader(0, TextFormat("src/gui/assets/shaders/wave.fs"))});

    _texture.insert({"Pano0", raylib::Texture("src/gui/assets/panorama_0.png")});
    _texture.insert({"Pano1", raylib::Texture("src/gui/assets/panorama_1.png")});
    _texture.insert({"Pano2", raylib::Texture("src/gui/assets/panorama_2.png")});
    _texture.insert({"Pano3", raylib::Texture("src/gui/assets/panorama_3.png")});
    _texture.insert({"Pano4", raylib::Texture("src/gui/assets/panorama_4.png")});
    _texture.insert({"Pano5", raylib::Texture("src/gui/assets/panorama_5.png")});

    _texture.insert({"grassSide", raylib::Texture("src/gui/assets/grass_block_side.png")});
    _texture.insert({"grassTop", raylib::Texture("src/gui/assets/grass_block_top.png")});
    _texture.insert({"water", raylib::Texture("src/gui/assets/water_flow.png")});
    _texture.insert({"dirt", raylib::Texture("src/gui/assets/dirt.png")});
    _texture.insert({"Logo", raylib::Texture("src/gui/assets/ZAPPy.png")});
    _texture.insert({"clearbackground", raylib::Texture("src/gui/assets/clearbackground.png")});
    _texture.insert({"basicButton", raylib::Texture("src/gui/assets/basic_button.png")});
    _texture.insert({"hoverButton", raylib::Texture("src/gui/assets/hover_button.png")});

    _texture.insert({"beef", raylib::Texture("src/gui/assets/beef_cooked.png")});
    _texture.insert({"carrot", raylib::Texture("src/gui/assets/carrot_golden.png")});
    _texture.insert({"coal", raylib::Texture("src/gui/assets/coal.png")});
    _texture.insert({"diamond", raylib::Texture("src/gui/assets/diamond.png")});
    _texture.insert({"emerald", raylib::Texture("src/gui/assets/emerald.png")});
    _texture.insert({"gold", raylib::Texture("src/gui/assets/gold_ingot.png")});
    _texture.insert({"iron", raylib::Texture("src/gui/assets/iron_ingot.png")});
    _texture.insert({"netherStar", raylib::Texture("src/gui/assets/nether_star.png")});
    _texture.insert({"quartz", raylib::Texture("src/gui/assets/quartz.png")});

    _cube.insert({"water", Cube(_texture["water"].GetId(), _texture["clearbackground"].GetId(), _texture["water"].GetId(), _shader["waterWave"])});
    _cube.insert({"grass", Cube(_texture["grassTop"].GetId(), _texture["grassSide"].GetId(), _texture["dirt"].GetId())});
    _cube.insert({"menuTop", Cube(_texture["Pano4"].GetId(), _texture["Pano4"].GetId(), _texture["Pano4"].GetId())});
    _cube.insert({"menuBot", Cube(_texture["Pano5"].GetId(), _texture["Pano5"].GetId(), _texture["Pano5"].GetId())});
    _cube.insert({"menuFront", Cube(_texture["Pano0"].GetId(), _texture["Pano0"].GetId(), _texture["Pano0"].GetId())});
    _cube.insert({"menuRight", Cube(_texture["Pano1"].GetId(), _texture["Pano1"].GetId(), _texture["Pano1"].GetId())});
    _cube.insert({"menuBack", Cube(_texture["Pano2"].GetId(), _texture["Pano2"].GetId(), _texture["Pano2"].GetId())});
    _cube.insert({"menuLeft", Cube(_texture["Pano3"].GetId(), _texture["Pano3"].GetId(), _texture["Pano3"].GetId())});

    _cube.insert({"beef", Cube(_texture["beef"].GetId())});
    _cube.insert({"carrot", Cube(_texture["carrot"].GetId())});
    _cube.insert({"coal", Cube(_texture["coal"].GetId())});
    _cube.insert({"diamond", Cube(_texture["diamond"].GetId())});
    _cube.insert({"emerald", Cube(_texture["emerald"].GetId())});
    _cube.insert({"gold", Cube(_texture["gold"].GetId())});
    _cube.insert({"iron", Cube(_texture["iron"].GetId())});
    _cube.insert({"netherStar", Cube(_texture["netherStar"].GetId())});
    _cube.insert({"quartz", Cube(_texture["quartz"].GetId())});

    _rectangle.insert({"menuLogo", std::make_shared<Rect>(_texture["Logo"])});
    _rectangle.insert({"menuPlayButton", std::make_shared<Rect>(_texture["basicButton"])});
    _rectangle.insert({"menuSettingsButton", std::make_shared<Rect>(_texture["basicButton"])});
    _rectangle.insert({"menuQuitButton", std::make_shared<Rect>(_texture["basicButton"])});
    _rectangle.insert({"menuHoverButton", std::make_shared<Rect>(_texture["hoverButton"])});
}

void Zappy::Raylib::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
}

void Zappy::Raylib::run(bool &isRunning)
{
    PlayMusicStream(_music);
    while (_exitWindow != true) {
        UpdateMusicStream(_music);
        event();
        draw();
        if (_data->_gameData._end == true)
            break;
    }
    UnloadMusicStream(_music);
    UnloadSound(_click);
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
}

void Zappy::Raylib::mouseClicking()
{
    Vector2 mousePos = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        auto it = _rectangle.begin();
        std::advance(it, 2);
        for (; it != _rectangle.end(); ++it) {
            if (CheckCollisionPointRec(mousePos, it->second->getRect())) {
                PlaySound(_click);
                if (it->first == "menuPlayButton")
                    _menu = false;
                // else if (it->first == "menuSettingsButton")
                //     _menu = false;
                else if (it->first == "menuQuitButton")
                    _exitWindow = true;
            }
        }
    }
}

void Zappy::Raylib::mouseHovering()
{
    Vector2 mousePos = GetMousePosition();

    auto it = _rectangle.begin();
    std::advance(it, 2);

    for (; it != _rectangle.end(); ++it) {
        if (CheckCollisionPointRec(mousePos, it->second->getRect()))
            it->second->setTexture(_texture["hoverButton"]);
        else
            it->second->setTexture(_texture["basicButton"]);
    }
}

void Zappy::Raylib::menuEvent()
{
    mouseHovering();
    mouseClicking();
}

void Zappy::Raylib::event()
{
    if (_menu == true)
        menuEvent();
    else
        cameraEvent();
    if(IsKeyPressed(KEY_T))
        _menu = !_menu;
    if (IsKeyPressed(KEY_ESCAPE))
        _exitWindow = true;
}

void Zappy::Raylib::drawTile(std::size_t x, std::size_t y, std::pair<std::size_t, std::size_t> map)
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

void Zappy::Raylib::drawWater()
{
    _cube["water"].drawWaterTexture((Vector3){0, 0.9, 0}, (Vector3){200, 0.9, 200}, GRAY);
}


void Zappy::Raylib::drawItem(std::size_t x, std::size_t y, std::pair<std::size_t, std::size_t> map)
{
    float size = 2.0f;
    int midX = map.first / 2;
    int midY = map.second / 2;

    float posX = size * x - (midX * size) + 1;
    float posY = size * y - (midY * size) + 1;
    float posZ = size / 2;
    _cube["netherStar"].drawItemTexture((Vector3){0, posZ + size, 0}, (Vector3){size, size, size}, WHITE);
}

void Zappy::Raylib::drawMap()
{
    auto mapSize = _data->_gameData._mapSize;
    for (std::size_t x = 0; x != mapSize.first; x++)
        for (std::size_t y = 0; y != mapSize.second; y++) {
            drawTile(x, y, mapSize);
        }

    drawWater();
    for (std::size_t x = 0; x != mapSize.first; x++)
        for (std::size_t y = 0; y != mapSize.second; y++) {
            drawItem(x, y, mapSize);
        }
    DrawGrid(10, 2.0f);
    DrawFPS(10, 10);
}

void Zappy::Raylib::drawText()
{
    DrawText("Play", 900, 470, 50, WHITE);
    DrawText("Settings", 850, 670, 50, WHITE);
    DrawText("Quit", 900, 870, 50, WHITE);
}

void Zappy::Raylib::drawButton()
{
    _rectangle["menuPlayButton"]->drawRect(1000, 100, {470, 450});
    _rectangle["menuSettingsButton"]->drawRect(1000, 100, {470, 650});
    _rectangle["menuQuitButton"]->drawRect(1000, 100, {470, 850});
}

void Zappy::Raylib::drawLogo()
{
    _rectangle["menuLogo"]->drawRect(744, 212, {600, 150});
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
    UpdateCameraPro(&_cameraMenu, Vector3 {0.0f,0.0f,0.0f}, Vector3{0.005f, 0.0000f, 0.0f}, 0.0);
    BeginMode3D(_cameraMenu);
    float size = 2;
    _cube["menuBack"].drawBlockTexture(Vector3{1.0f, 1.0f, 1.0f - size}, Vector3{size, size, size}, WHITE);
    _cube["menuLeft"].drawBlockTexture(Vector3{1.0f - size, 1.0f, 1.0f}, Vector3 {size, size, size}, WHITE);
    _cube["menuFront"].drawBlockTexture(Vector3{1.0f, 1.0f, 1.0f + size}, Vector3{size, size, size}, WHITE);
    _cube["menuRight"].drawBlockTexture(Vector3{1.0f + size, 1.0f, 1.0f}, Vector3 {size, size, size}, WHITE);
    _cube["menuTop"].drawBlockTexture(Vector3{1.0f, 1.0f + size, 1.0f}, Vector3 {size, size, size}, WHITE);
    _cube["menuBot"].drawBlockTexture(Vector3{1.0f, 1.0f - size, 1.0f}, Vector3 {size, size, size}, WHITE);
    DrawGrid(10, 2.0f);

    EndMode3D();

    drawLogo();
    drawButton();
    drawText();
}

void Zappy::Raylib::drawBackground()
{

}

Zappy::Raylib::~Raylib()
{
    _texture.clear();
    CloseAudioDevice();
    CloseWindow();
}
