/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** DrawEggs
*/

#include "DrawEggs.hpp"

Zappy::DrawEggs::DrawEggs()
{
    setTexture();
    setModel();
}

Zappy::DrawEggs::~DrawEggs()
{
}

void Zappy::DrawEggs::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
}

void Zappy::DrawEggs::setTexture()
{
    _texture = raylib::Texture("src/gui/assets/items/texture/turtle_egg.png");
}

void Zappy::DrawEggs::setModel()
{
    _model = raylib::Model("src/gui/assets/items/obj/turtle_eggs.obj");
    SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
}

void Zappy::DrawEggs::draw()
{
    
}

void Zappy::DrawEggs::drawEggs()
{

}
