/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawBroadCast
*/

#include "DrawBroadCast.hpp"

Zappy::DrawBroadCast::DrawBroadCast()
{
    _windowSize = {GetMonitorWidth(0), GetMonitorHeight(0)};
}

Zappy::DrawBroadCast::~DrawBroadCast()
{
}

void Zappy::DrawBroadCast::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
}

void Zappy::DrawBroadCast::event()
{
    if (IsKeyPressed(KEY_ENTER))
        _drawChatBox = !_drawChatBox;
    if (_drawChatBox)
        boxHover();
}

void Zappy::DrawBroadCast::boxHover()
{
    int rectWidth = _windowSize.first * 0.2;
    int rectHeight = _windowSize.second * 0.6;
    float x = _windowSize.first - _windowSize.first * 0.005 - rectWidth;
    float y = _windowSize.second * 0.2;
    raylib::Rectangle rect(x, y, x + rectWidth, y +rectHeight);
    if (CheckCollisionPointRec(GetMousePosition(), rect)) {
        DrawRectangle(x, y, rectWidth, rectHeight, Fade(SKYBLUE, 0.5f));
        _scrollIndex -= GetMouseWheelMove();
        // if (_scrollIndex > _data->_gameData._broadCast._All.size())
            // _scrollIndex = _data->_gameData._broadCast._All.size() - 1;
        // if (_scrollIndex < 0)
        //     _scrollIndex = 0;
    }
}

void Zappy::DrawBroadCast::draw()
{
    event();
    if (_drawChatBox)
        drawChatBox();
    drawAnimation();
}

static Color getTeamColor(std::size_t id)
{
    unsigned char tmpcolorR = (id) % 255;
    unsigned char tmpcolorG = tmpcolorR * 4 % 150;
    Color textColor = Color{30, tmpcolorR, 30, 255};
    if (tmpcolorR % 3 == 1)
        textColor = Color{tmpcolorR, 30, tmpcolorG, 255};
    if (tmpcolorR % 3 == 2)
        textColor = Color{30, tmpcolorR, 30, 255};
    if (tmpcolorR % 3 == 3)
        textColor = Color{tmpcolorR, 30, tmpcolorG, 255};
    return textColor;
}
void Zappy::DrawBroadCast::drawChatBox()
{
    int rectWidth = _windowSize.first * 0.2;
    int rectHeight = _windowSize.second * 0.6;
    float x = _windowSize.first - _windowSize.first * 0.005 - rectWidth;
    float y = _windowSize.second * 0.2;
    DrawRectangle(x, y, rectWidth, rectHeight, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines( x, y, rectWidth, rectHeight, BLACK);
    auto players = _data->_gameData._player;
    std::vector<broadcast_t> message = _data->_gameData._broadCast._All;
    for (std::size_t i = 0; i != message.size(); i++)
    {
        // int tmp = _scrollIndex;
        // if (_scrollIndex > message.size() - i - 1)
            // tmp = message.size() - i - 1;
        std::size_t index = message.size() - i - 1;
        std::size_t id = message[index]._playerId;
        std::string player = "[" + std::to_string(index) +  "]" + "Player " + std::to_string(id) + ":";
        if (y + rectHeight * 0.90 - _windowSize.second * 0.05 * i <= y)
                break;
        if (players.count(id) != 0) {
            std::size_t teamid = players[id]->getTeam()->getId();
            Color color = getTeamColor(teamid);
            DrawText(player.c_str(), x + rectWidth * 0.05, y + rectHeight * 0.90 - _windowSize.second * 0.05 * i, 20, color);
            DrawText(message[index]._message.c_str(), x + rectWidth * 0.05, y + rectHeight * 0.90 - _windowSize.second * 0.05 * i + 20, 20, BLACK);
        }
        else {
            player.append(" (Dead)");
            DrawText(player.c_str(), x + rectWidth * 0.05, y + rectHeight * 0.90 - _windowSize.second * 0.05 * i, 20, DARKGRAY);
            DrawText(message[index]._message.c_str(), x + rectWidth * 0.05, y + rectHeight * 0.90 - _windowSize.second * 0.05 * i + 20 , 20, BLACK);
        }
    }
}

void Zappy::DrawBroadCast::drawAnimation()
{

}