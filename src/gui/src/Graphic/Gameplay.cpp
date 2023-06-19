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
    setModel();
    _animated = false;
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
    _camera.position = (Vector3){0.0f, 40.0f, 20.0f};    // Camera position
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

    _texture.insert({"Thystame", raylib::Texture("src/gui/assets/items/texture/nether_star.png")});
    _texture.insert({"Phiras", raylib::Texture("src/gui/assets/items/texture/emerald.png")});
    _texture.insert({"Mendiane", raylib::Texture("src/gui/assets/items/texture/diamond.png")});
    _texture.insert({"Sibur", raylib::Texture("src/gui/assets/items/texture/gold.png")});
    _texture.insert({"Deraumere", raylib::Texture("src/gui/assets/items/texture/iron.png")});
    _texture.insert({"Linemate", raylib::Texture("src/gui/assets/items/texture/coal.png")});
    _texture.insert({"Food", raylib::Texture("src/gui/assets/items/texture/carrot.png")});
}

void Zappy::Gameplay::setCube()
{
    _cube.insert({"water", Cube(_texture["water"].GetId(), _texture["clearbackground"].GetId(), _texture["water"].GetId(), _shader["waterWave"])});
    _cube.insert({"grass", Cube(_texture["grassTop"].GetId(), _texture["grassSide"].GetId(), _texture["dirt"].GetId())});
    _cube.insert({"Thystame", Cube(_texture["Thystame"].GetId())});
    _cube.insert({"Phiras", Cube(_texture["Phiras"].GetId())});
    _cube.insert({"Mendiane", Cube(_texture["Mendiane"].GetId())});
    _cube.insert({"Sibur", Cube(_texture["Sibur"].GetId())});
    _cube.insert({"Deraumere", Cube(_texture["Deraumere"].GetId())});
    _cube.insert({"Linemate", Cube(_texture["Linemate"].GetId())});
    _cube.insert({"Food", Cube(_texture["Food"].GetId())});

}

void Zappy::Gameplay::setModel()
{
    std::vector<std::string> ressource = {"Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame"};

    _model.insert({"Thystame", raylib::Model("src/gui/assets/items/obj/nether_star.obj")});
    _model.insert({"Phiras", raylib::Model("src/gui/assets/items/obj/emerald.obj")});
    _model.insert({"Mendiane", raylib::Model("src/gui/assets/items/obj/diamond.obj")});
    _model.insert({"Sibur", raylib::Model("src/gui/assets/items/obj/gold.obj")});
    _model.insert({"Deraumere", raylib::Model("src/gui/assets/items/obj/iron.obj")});
    _model.insert({"Linemate", raylib::Model("src/gui/assets/items/obj/coal.obj")});
    _model.insert({"Food", raylib::Model("src/gui/assets/items/obj/carrot.obj")});

    for (int i = 0; ressource.size() != i; ++i)
        SetMaterialTexture(&_model[ressource[i]].materials[0], MATERIAL_MAP_DIFFUSE, _texture[ressource[i]]);
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
    if (IsKeyPressed(KEY_SPACE)) {
        _cameraMove = !_cameraMove;
    }
    if (IsKeyPressed(KEY_R)) {
        _camera.position = (Vector3){0.0f, 60.0f, 20.0f};    // Camera position
        _camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    }
    if (IsKeyPressed(KEY_F)) {
        _animated = !_animated;
    }
    if (_cameraMove == true) {
        _camera.Update(CAMERA_ORBITAL);
        return;
    }
    Vector3 position = {0.0, 0.0, 0.0};
    if (IsKeyDown(KEY_LEFT)) {
        position.y = -0.5f;
        _camera.target = (Vector3){0.0f, 0.0f, 0.0f}; // Camera looking at point
    }
    if (IsKeyDown(KEY_RIGHT)) {
        position.y = 0.5f;
        _camera.target = (Vector3){0.0f, 0.0f, 0.0f}; // Camera looking at point
    }
    if (IsKeyDown(KEY_UP)) {
        position.z = 0.5f;
        _camera.target = (Vector3){0.0f, 0.0f, 0.0f}; // Camera looking at point
    }
    if (IsKeyDown(KEY_DOWN)) {
        position.z = -0.5f;
        _camera.target = (Vector3){0.0f, 0.0f, 0.0f}; // Camera looking at point
    }
    if (IsKeyDown(KEY_W))
        position.x = 0.5f;
    if (IsKeyDown(KEY_S))
        position.x = -0.5f;
    if (IsKeyDown(KEY_A))
        position.y = -0.5f;
    if (IsKeyDown(KEY_D))
        position.y = 0.5f;
    _camera.Update(position, Vector3{0.0f, 0.0000f, 0.0f}, 0.0);
}

void Zappy::Gameplay::draw()
{
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
}


bool Zappy::Gameplay::tilehover(float posX, float posY, float posZ, float size)
{
    RayCollision collision;
    Ray ray;
    ray = GetMouseRay(GetMousePosition(), _camera);
    collision = GetRayCollisionBox(ray, (BoundingBox){(Vector3){ posX - size/2, posZ + size/2, posY - size/2 },
                                                      (Vector3){ posX + size/2, posZ + size/2, posY + size/2 }});
    if (collision.hit)
    {
        // printf("[%d][%d]\n", x, y);
        DrawCubeWiresV((Vector3){posX, posZ + size / 2, posY}, (Vector3){size,  0.5, size}, RED);
    }
}
void Zappy::Gameplay::drawTile(std::size_t x, std::size_t y, std::pair<std::size_t, std::size_t> map)
{
    RayCollision collision;
    Ray ray;

    float size = 3.0f;
    int midX = map.first / 2;
    int midY = map.second / 2;
    float posX = size * x - (midX * size);
    float posY = size * y - (midY * size);
    float posZ = size / 2;

    // ray = GetMouseRay(GetMousePosition(), _camera);
    // collision = GetRayCollisionBox(ray, (BoundingBox){(Vector3){ posX - size/2, posZ + size/2, posY - size/2 },
    //                                                   (Vector3){ posX + size/2, posZ + size/2, posY + size/2 }});
    // if (collision.hit)
    // {
    //     printf("[%d][%d]\n", x, y);
    //     DrawCubeWiresV((Vector3){posX, posZ + size, posY}, (Vector3){size,  0.5, size}, RED);
    // }
    tilehover(posX, posY, posZ, size);
    _cube["grass"].drawBlockTexture((Vector3){posX, posZ, posY}, (Vector3){size, size, size}, WHITE);
    drawItem((Vector3){posX, posY, posZ}, size, _data->_gameData._map[x][y].getRessources());
}

void Zappy::Gameplay::drawItem(Vector3 pos, std::size_t size, std::vector<std::shared_ptr<IRessource>> rss)
{
    std::vector<std::string> ressource = {"Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame"};
    for (std::size_t i = 0; i != rss.size(); i++) {
        auto qty = rss[i]->getQuantity();
        if (qty > 0)
            drawSpacedItem(qty, pos, ressource[i], size, i);
        _cube[ressource[i]].AnimateItem((Vector3){1.2, 1.2, 1.2});
    }
}

void Zappy::Gameplay::drawSpacedItem(std::size_t qty, Vector3 pos, std::string ressource, std::size_t size, std::size_t i)
{
    int x = i;
    int y = 0;

    if (i > 2) {
        x = i - 2;
        y++;
    }
    if (i > 4) {
        x = i - 4;
        y++;
    }
    if (i > 6) {
        x = i - 6;
        y++;
    }
    
    _rotation -= 0.01f;;
    if (_itemBounce < size && _ret == false) {
        _itemBounce += 0.01f;
        if (_itemBounce > size / 2)
            _ret = true;
    }
    if (_itemBounce > size / 2 && _ret == true) {
        _itemBounce -= 0.01f;
       if (_itemBounce < -size / 2)
            _ret = false;
    }

    for (std::size_t a = 0; a != qty; a++) {
        DrawModelEx(_model[ressource], (Vector3){pos.x - (size / 2) + x * 0.8, (pos.z + size - 0.2 + a * 0.01) + _itemBounce, pos.y - (size / 2) + a * 0.2 + y * 1}, (Vector3) {0, 1, 0}, _rotation, (Vector3) {1.5, 1.5, 1.5}, WHITE);
        // if (_animated) {
        //     _cube[ressource].drawItemTextureAnimated((Vector3){pos.x - (size / 2) + x * 0.8, pos.z + size - 0.2 + a * 0.01, pos.y - (size / 2) + a * 0.2 + y * 1}, (Vector3){1.2, 1.2, 1.2}, LIGHTGRAY);
        // }
        // else
        //     _cube[ressource].drawItemTextureFloor((Vector3){pos.x - (size / 2) + x * 0.8, pos.z + size / 2 + 0.2 + a * 0.01, pos.y - (size / 2) + a * 0.2 + y * 1}, (Vector3){1.2, 1.2, 1.2}, LIGHTGRAY);
    }
}