/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawScoreboard
*/

#include "DrawScoreboard.hpp"

Zappy::DrawScoreboard::DrawScoreboard()
{
    // getPlayer();
}

Zappy::DrawScoreboard::~DrawScoreboard()
{
}

void Zappy::DrawScoreboard::getTeam()
{
    _teamSize = _data->_gameData._teams.size();
    for (const auto &pair : _data->_gameData._teams) {
        _teamNameString = pair.first;
        _teamName.push_back(_teamNameString);
    }
}

void Zappy::DrawScoreboard::getPlayer()
{
    _playerSize = _data->_gameData._player.size();
    for (const auto &pair : _data->_gameData._player) {
        _playerIdSize = pair.first;
        _playerId.push_back(_playerIdSize);
    }
}

void Zappy::DrawScoreboard::setData(std::shared_ptr<Data> data)
{
    std::shared_ptr<Data> tmp(data, data.get());
    _data = tmp;
}

void Zappy::DrawScoreboard::drawScoreboard()
{
    getTeam();
    getPlayer();
    DrawRectangleRec(_scoreboardRec, Fade(SKYBLUE, 0.5f));
    DrawRectangleLinesEx(_scoreboardRec, 5, BLACK);

    // for (size_t i = 0; i < _teamSize; i++) {
    //     DrawText(_teamName[i].c_str(), 300 + (i * 200), 50, 20, BLACK);
    // }
    for (size_t i = 0; i < _teamSize; i++) {
        DrawText(_teamName[i].c_str(), 350 + (i * 150), 50, 20, RED);
        for (size_t i = 0; i < _playerSize; i++) {
            // std::shared_ptr<Player> player = _data->_gameData._player[i];
            // _data->_gameData._player[i]->getTeam();
            // if (player->_team->getName() == _teamName[i]) {
            //     std::string test = std::to_string(_playerId[i]);
            //     DrawText(test, 300, 100 + (i * 50), 20, BLACK);
            // }
        }
    }
}