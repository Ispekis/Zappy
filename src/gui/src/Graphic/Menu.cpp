/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Menu
*/

#include "Menu.hpp"

Zappy::Menu::Menu()
{
    setCamera();
    setTexture();
    setCube();
    setRectangle();
    setMusic();
}

Zappy::Menu::~Menu()
{
    std::cout << "Menu Destroyed" << std::endl;
    UnloadMusicStream(_music);
    UnloadSound(_click);
}

void Zappy::Menu::setCamera()
{
    _cameraMenu.position = (Vector3){1.0f, 1.0f, 1.0f };  // Camera position
    _cameraMenu.target = (Vector3){1.0f, 1.0f, 1.0f + 2};      // Camera looking at point
    _cameraMenu.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    _cameraMenu.fovy = 70.0f;                                // Camera field-of-view Y
    _cameraMenu.projection = CAMERA_PERSPECTIVE;
}

void Zappy::Menu::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
}

void Zappy::Menu::setMusic()
{
    _music = LoadMusicStream("src/gui/assets/Minecraft-Theme Song {Extended for 30 Minutes}.mp3");
    _click = LoadSound("src/gui/assets/click.ogg");
    PlayMusicStream(_music);
    SetMusicVolume(_music, _volume);
    SetSoundVolume(_click, 0.2);
}

void Zappy::Menu::setTexture()
{
    _texture.insert({"Pano0", raylib::Texture("src/gui/assets/panorama_0.png")});
    _texture.insert({"Pano1", raylib::Texture("src/gui/assets/panorama_1.png")});
    _texture.insert({"Pano2", raylib::Texture("src/gui/assets/panorama_2.png")});
    _texture.insert({"Pano3", raylib::Texture("src/gui/assets/panorama_3.png")});
    _texture.insert({"Pano4", raylib::Texture("src/gui/assets/panorama_4.png")});
    _texture.insert({"Pano5", raylib::Texture("src/gui/assets/panorama_5.png")});
    _texture.insert({"Logo", raylib::Texture("src/gui/assets/ZAPPy.png")});
    _texture.insert({"basicButton", raylib::Texture("src/gui/assets/basic_button.png")});
    _texture.insert({"hoverButton", raylib::Texture("src/gui/assets/hover_button.png")});
    _texture.insert({"sidebar", raylib::Texture("src/gui/assets/sidebar.png")});

    _texture.insert({"level1", raylib::Texture("src/gui/assets/levelSkin/1.png")});
    _texture.insert({"level2", raylib::Texture("src/gui/assets/levelSkin/2.png")});
    _texture.insert({"level3", raylib::Texture("src/gui/assets/levelSkin/3.png")});
    _texture.insert({"level4", raylib::Texture("src/gui/assets/levelSkin/4.png")});
    _texture.insert({"level5", raylib::Texture("src/gui/assets/levelSkin/5.png")});
    _texture.insert({"level6", raylib::Texture("src/gui/assets/levelSkin/6.png")});
    _texture.insert({"level7", raylib::Texture("src/gui/assets/levelSkin/7.png")});
    _texture.insert({"level8", raylib::Texture("src/gui/assets/levelSkin/8.png")});
}

void Zappy::Menu::setRectangle()
{
    _rectangle.insert({"menuLogo", std::make_shared<Rect>(_texture["Logo"])});
    _rectangle.insert({"menuPlayButton", std::make_shared<Rect>(_texture["basicButton"])});
    _rectangle.insert({"menuSettingsButton", std::make_shared<Rect>(_texture["basicButton"])});
    _rectangle.insert({"menuQuitButton", std::make_shared<Rect>(_texture["basicButton"])});
    _rectangle.insert({"menuHowToPlayButton", std::make_shared<Rect>(_texture["basicButton"])});
    _rectangle.insert({"returnButton", std::make_shared<Rect>(_texture["basicButton"])});
    _rectangle.insert({"menuHoverButton", std::make_shared<Rect>(_texture["hoverButton"])});
    _rectangle.insert({"volumeSidebar", std::make_shared<Rect>(_texture["sidebar"])});
    _rectangle.insert({"framerateSidebar", std::make_shared<Rect>(_texture["sidebar"])});
    _rectangle.insert({"howToPlayBackGround", std::make_shared<Rect>(_texture["basicButton"])});
}

void Zappy::Menu::setCube()
{
    _cube.insert({"menuTop", Cube(_texture["Pano4"].GetId(), _texture["Pano4"].GetId(), _texture["Pano4"].GetId())});
    _cube.insert({"menuBot", Cube(_texture["Pano5"].GetId(), _texture["Pano5"].GetId(), _texture["Pano5"].GetId())});
    _cube.insert({"menuFront", Cube(_texture["Pano0"].GetId(), _texture["Pano0"].GetId(), _texture["Pano0"].GetId())});
    _cube.insert({"menuRight", Cube(_texture["Pano1"].GetId(), _texture["Pano1"].GetId(), _texture["Pano1"].GetId())});
    _cube.insert({"menuBack", Cube(_texture["Pano2"].GetId(), _texture["Pano2"].GetId(), _texture["Pano2"].GetId())});
    _cube.insert({"menuLeft", Cube(_texture["Pano3"].GetId(), _texture["Pano3"].GetId(), _texture["Pano3"].GetId())});
}

void Zappy::Menu::run()
{
    UpdateMusicStream(_music);
    event();
    if (_settings == true)
        settingsEvent();
    if (_howToPlay == true) {
        howToPlayEvent();
    }
    draw();
}

void Zappy::Menu::event()
{
    mouseHovering();
    mouseClicking();
}

void Zappy::Menu::settingsEvent()
{
    if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_ENTER)) {
        _principalMenu = true;
        _settings = false;
    }
    settingsButtonEvent();
}

void Zappy::Menu::volumeEvent(std::string volume)
{
    if (volume == "volumeUp") {
        if (_volume < 1.0f)
            _volume -= 0.1f;
    } else if (volume == "volumeDown") {
        if (_volume > 0.0f)
            _volume += 0.1f;
    }
    SetMusicVolume(_music, _volume);
}

void Zappy::Menu::settingsButtonEvent()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (CheckCollisionPointRec(GetMousePosition(), _rect2)) {
            _isFramerate = true;
        }
        if (CheckCollisionPointRec(GetMousePosition(), _rect)) {
            _isVolume = true;
        }
    }

    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        _isFramerate = false;
    }

    if (_isFramerate) {
        float minX = _rectangle["framerateSidebar"]->getRect().x;
        float maxX = _rectangle["framerateSidebar"]->getRect().x + _rectangle["framerateSidebar"]->getRect().width - _rect2.width;

        _rect2.x = Clamp(GetMouseX() - _rect2.width / 2, minX, maxX);

        float fpsRange = _maxFps - _minFps;
        float rectRange = maxX - minX;
        float fpsIncrement = fpsRange / rectRange;
        _fps = _minFps + static_cast<int>(fpsIncrement * (_rect2.x - minX));
        _data->_gameData._timeUnit.setFps(_fps);
        SetTargetFPS(_fps);
    }


    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        _isVolume = false;
    }

    if (_isVolume) {
        float minX = _rectangle["volumeSidebar"]->getRect().x;
        float maxX = _rectangle["volumeSidebar"]->getRect().x + _rectangle["volumeSidebar"]->getRect().width - _rect.width;

        _rect.x = Clamp(GetMouseX() - _rect.width / 2, minX, maxX);

        float volumeRange = 1.0f - 0.0f;
        float rectRange = maxX - minX;
        float volumeIncrement = volumeRange / rectRange;
        _volume = volumeIncrement * (_rect.x - minX);
        _volumePercentage = static_cast<int>(_volume * 100);
        SetMusicVolume(_music, _volume);
    }
}

void Zappy::Menu::howToPlayEvent()
{
    if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_ENTER)) {
        _principalMenu = true;
        _howToPlay = false;
    }
}

void Zappy::Menu::drawBackground()
{
    float size = 2;

    _cameraMenu.Update(Vector3 {0.0f,0.0f,0.0f}, Vector3{0.005f, 0.0000f, 0.0f}, 0.0);
    _cameraMenu.BeginMode();
    _cube["menuBack"].drawBlockTexture(Vector3{1.0f, 1.0f, 1.0f - size}, Vector3{size, size, size}, WHITE);
    _cube["menuLeft"].drawBlockTexture(Vector3{1.0f - size, 1.0f, 1.0f}, Vector3 {size, size, size}, WHITE);
    _cube["menuFront"].drawBlockTexture(Vector3{1.0f, 1.0f, 1.0f + size}, Vector3{size, size, size}, WHITE);
    _cube["menuRight"].drawBlockTexture(Vector3{1.0f + size, 1.0f, 1.0f}, Vector3 {size, size, size}, WHITE);
    _cube["menuTop"].drawBlockTexture(Vector3{1.0f, 1.0f + size, 1.0f}, Vector3 {size, size, size}, WHITE);
    _cube["menuBot"].drawBlockTexture(Vector3{1.0f, 1.0f - size, 1.0f}, Vector3 {size, size, size}, WHITE);
    _cameraMenu.EndMode();
}

void Zappy::Menu::draw()
{
    drawBackground();
    if (!_settings && !_howToPlay && _data->_gameData._menu == true) {
        drawLogo();
        drawButton();
        drawText();
    } else if (_settings && !_howToPlay)
        drawSettings();
    else if (!_settings && _howToPlay)
        drawHowToPlay();
}

void Zappy::Menu::drawLogo()
{
    _rectangle["menuLogo"]->drawRect(744, 212, {600, 150});
}

void Zappy::Menu::drawButton()
{
    _rectangle["menuPlayButton"]->drawRect(1000, 100, {470, 450});
    _rectangle["menuHowToPlayButton"]->drawRect(1000, 100, {470, 600});
    _rectangle["menuSettingsButton"]->drawRect(1000, 100, {470, 750});
    _rectangle["menuQuitButton"]->drawRect(1000, 100, {470, 900});
}

void Zappy::Menu::drawText()
{
    DrawText("Play", 900, 470, 50, WHITE);
    DrawText("How to play", 810, 620, 50, WHITE);
    DrawText("Settings", 850, 770, 50, WHITE);
    DrawText("Quit", 900, 920, 50, WHITE);
}

void Zappy::Menu::drawVolume()
{
    DrawText("Volume", 860, 200, 70, WHITE);
    _rectangle["volumeSidebar"]->drawRect(1000, 100, {470, 350});
    std::string volumeText = std::to_string(_volumePercentage) + "%";
    DrawRectangleRec(_rect, GRAY);
    DrawRectangleLinesEx(_rect, 5, BLACK);
    DrawText(volumeText.c_str(), 947, 370, 50, WHITE);
    DrawText("Press [Enter] to go back", 1200, 970, 50, WHITE);
}

void Zappy::Menu::drawFramerate()
{
    DrawText("FPS", 900, 500, 70, WHITE);
    _rectangle["framerateSidebar"]->drawRect(1000, 100, {470, 650});
    std::string fpsText = std::to_string(_fps);
    DrawRectangleRec(_rect2, GRAY);
    DrawRectangleLinesEx(_rect2, 5, BLACK);
    DrawText(fpsText.c_str(), 947, 670, 50, WHITE);
}

void Zappy::Menu::drawReturnButton()
{
    _rectangle["returnButton"]->drawRect(400, 100, {1500, 970});
    DrawText("Return", 1610, 995, 50, WHITE);
}

void Zappy::Menu::drawSettings()
{
    drawVolume();
    drawFramerate();
    drawReturnButton();
}

void Zappy::Menu::drawHowToPlay()
{
    std::vector<std::string> level = { "level1","level2", "level3", "level4", "level5", "level6", "level7", "level8" };
    float x = 180;
    Rectangle rec = {250, 100, 1400, 450};

    DrawRectangleRec(rec, GRAY);
    DrawRectangleLinesEx(rec, 5, BLACK);
    for (int i = 0; level.size() != i; ++i) {
        _texture[level[i]].Draw((Vector2) { x, 600 }, 0, 0.2, WHITE);
        DrawRectangle(x, 850, 140, 40, GRAY);
        DrawText(TextFormat("Level %d", i + 1), x + 15, 860, 30, BLACK);
        x += 200;
    }
    drawReturnButton();
}

void Zappy::Menu::mouseClicking()
{
    Vector2 mousePos = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        auto it = _rectangle.begin();
        std::advance(it, 2);
        for (; it != _rectangle.end(); ++it) {
            if (CheckCollisionPointRec(mousePos, it->second->getRect())) {
                PlaySound(_click);
                if (it->first == "menuPlayButton")
                    _data->_gameData._menu = false;
                else if (it->first == "menuHowToPlayButton") {
                    _howToPlay = true;
                    _principalMenu = false;
                } else if (it->first == "menuSettingsButton") {
                    _settings = true;
                    _principalMenu = false;
                } else if (it->first == "menuQuitButton")
                    _data->_gameData._end = true;
                else if (it->first == "returnButton") {
                    _principalMenu = true;
                    _settings = false;
                    _howToPlay = false;
                }
            }
        }
    }
}

void Zappy::Menu::mouseHovering()
{
    Vector2 mousePos = GetMousePosition();

    auto it = _rectangle.begin();
    std::advance(it, 2);

    if (_settings != true) {
        for (; it != _rectangle.end(); ++it) {
            if (CheckCollisionPointRec(mousePos, it->second->getRect()) && it->first != "menuLogo" && it->first != "volumeSidebar" && it->first != "framerateSidebar") {
                it->second->setTexture(_texture["hoverButton"]);
            } else if (it->first == "menuPlayButton" || it->first == "menuSettingsButton" || it->first == "menuQuitButton" || it->first == "menuHowToPlayButton" || it->first == "returnButton") { 
                if (it->first != "menuLogo")
                    it->second->setTexture(_texture["basicButton"]);
            
            }
        }
    }
}

bool Zappy::Menu::getPrincipaleMenu()
{
    return _principalMenu;
}
