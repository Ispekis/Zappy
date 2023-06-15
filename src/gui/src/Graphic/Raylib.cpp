/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Raylib
*/

#include "Raylib.hpp"

Zappy::Raylib::Raylib(std::string title)
{
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), title.c_str());
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

Texture2D LoadTextureFromFile(std::string path)
{
    return LoadTexture(path.c_str());
}

void Zappy::Raylib::setTexture()
{
    _shader.insert({"waterWave", LoadShader(0, TextFormat("src/gui/assets/shaders/wave.fs"))});

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
    _texture.insert({"dirt", LoadTextureFromFile("src/gui/assets/dirt.png")});
    _texture.insert({"Logo", LoadTextureFromFile("src/gui/assets/ZAPPy.png")});
    _texture.insert({"clearbackground", LoadTextureFromFile("src/gui/assets/clearbackground.png")});
    _texture.insert({"basicButton", LoadTextureFromFile("src/gui/assets/basic_button.png")});
    _texture.insert({"hoverButton", LoadTextureFromFile("src/gui/assets/hover_button.png")});

    _texture.insert({"beef", LoadTextureFromFile("src/gui/assets/beef_cooked.png")});
    _texture.insert({"carrot", LoadTextureFromFile("src/gui/assets/carrot_golden.png")});
    _texture.insert({"coal", LoadTextureFromFile("src/gui/assets/coal.png")});
    _texture.insert({"diamond", LoadTextureFromFile("src/gui/assets/diamond.png")});
    _texture.insert({"emerald", LoadTextureFromFile("src/gui/assets/emerald.png")});
    _texture.insert({"gold", LoadTextureFromFile("src/gui/assets/gold_ingot.png")});
    _texture.insert({"iron", LoadTextureFromFile("src/gui/assets/iron_ingot.png")});
    _texture.insert({"netherStar", LoadTextureFromFile("src/gui/assets/nether_star.png")});
    _texture.insert({"quartz", LoadTextureFromFile("src/gui/assets/quartz.png")});

    _sprite.insert({"water", std::make_shared<Sprite>(_texture["water"], _texture["clearbackground"], _texture["water"], _shader["waterWave"])});
    _sprite.insert({"grass", std::make_shared<Sprite>(_texture["grassTop"], _texture["grassSide"], _texture["dirt"])});
    _sprite.insert({"menuTop", std::make_shared<Sprite>(_texture["Pano4"], _texture["Pano4"], _texture["Pano4"])});
    _sprite.insert({"menuBot", std::make_shared<Sprite>(_texture["Pano5"], _texture["Pano5"], _texture["Pano5"])});
    _sprite.insert({"menuFront", std::make_shared<Sprite>(_texture["Pano0"], _texture["Pano0"], _texture["Pano0"])});
    _sprite.insert({"menuRight", std::make_shared<Sprite>(_texture["Pano1"], _texture["Pano1"], _texture["Pano1"])});
    _sprite.insert({"menuBack", std::make_shared<Sprite>(_texture["Pano2"], _texture["Pano2"], _texture["Pano2"])});
    _sprite.insert({"menuLeft", std::make_shared<Sprite>(_texture["Pano3"], _texture["Pano3"], _texture["Pano3"])});

    _sprite.insert({"beef", std::make_shared<Sprite>(_texture["beef"])});
    _sprite.insert({"carrot", std::make_shared<Sprite>(_texture["carrot"])});
    _sprite.insert({"coal", std::make_shared<Sprite>(_texture["coal"])});
    _sprite.insert({"diamond", std::make_shared<Sprite>(_texture["diamond"])});
    _sprite.insert({"emerald", std::make_shared<Sprite>(_texture["emerald"])});
    _sprite.insert({"gold", std::make_shared<Sprite>(_texture["gold"])});
    _sprite.insert({"iron", std::make_shared<Sprite>(_texture["iron"])});
    _sprite.insert({"netherStar", std::make_shared<Sprite>(_texture["netherStar"])});
    _sprite.insert({"quartz", std::make_shared<Sprite>(_texture["quartz"])});

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
    _sprite["grass"]->drawBlockTexture((Vector3){posX, posZ, posY}, (Vector3){size, size, size}, WHITE);
}

void Zappy::Raylib::drawWater()
{
    _sprite["water"]->drawWaterTexture((Vector3){0, 0.9, 0}, (Vector3){200, 0.9, 200}, GRAY);
}


void Zappy::Raylib::drawItem(std::size_t x, std::size_t y, std::pair<std::size_t, std::size_t> map)
{
    float size = 2.0f;
    int midX = map.first / 2;
    int midY = map.second / 2;

    float posX = size * x - (midX * size) + 1;
    float posY = size * y - (midY * size) + 1;
    float posZ = size / 2;
    _sprite["netherStar"]->drawItemTexture((Vector3){0, posZ + size, 0}, (Vector3){size, size, size}, WHITE);
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
    // UpdateCamera(&_cameraMenu, CAMERA_FIRST_PERSON);
    UpdateCameraPro(&_cameraMenu, Vector3 {0.0f,0.0f,0.0f}, Vector3{0.005f, 0.0000f, 0.0f}, 0.0);
    BeginMode3D(_cameraMenu);
    float size = 2;
    _sprite["menuBack"]->drawBlockTexture(Vector3{1.0f, 1.0f, 1.0f - size}, Vector3{size, size, size}, WHITE);
    _sprite["menuLeft"]->drawBlockTexture(Vector3{1.0f - size, 1.0f, 1.0f}, Vector3 {size, size, size}, WHITE);
    _sprite["menuFront"]->drawBlockTexture(Vector3{1.0f, 1.0f, 1.0f + size}, Vector3{size, size, size}, WHITE);
    _sprite["menuRight"]->drawBlockTexture(Vector3{1.0f + size, 1.0f, 1.0f}, Vector3 {size, size, size}, WHITE);
    _sprite["menuTop"]->drawBlockTexture(Vector3{1.0f, 1.0f + size, 1.0f}, Vector3 {size, size, size}, WHITE);
    _sprite["menuBot"]->drawBlockTexture(Vector3{1.0f, 1.0f - size, 1.0f}, Vector3 {size, size, size}, WHITE);
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
    std::map<std::string, Texture2D>::iterator it;
    for (it = _texture.begin(); it != _texture.end(); ++it)
            UnloadTexture(it->second);
    CloseAudioDevice();
    CloseWindow();
}
