/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** DrawScoreboard
*/

#include "DrawScoreboard.hpp"

Zappy::DrawScoreboard::DrawScoreboard()
{
}

Zappy::DrawScoreboard::~DrawScoreboard()
{
}

void Zappy::DrawScoreboard::getTeam()
{
    std::cout << "Number of teams: " << _gameData->_teams.size();
    // for (const auto &pair : _gameData._teams) {
    //     std::cout << "Team: " << pair.first << std::endl;
    //     // _teamNameString = pair.first;
    //     // _teamName.push_back(_teamNameString);
    // }

    // for (const std::string &team : _teamName)
    //     std::cout << "Team: " << team << std::endl;
}

void Zappy::DrawScoreboard::setData(std::shared_ptr<Data> data, std::shared_ptr<GameData> gameData)
{
    std::shared_ptr<Data> tmp(data, data.get());
    std::shared_ptr<GameData> tmp2(gameData, gameData.get());
    _data = tmp;
    _gameData = tmp2;
}

void Zappy::DrawScoreboard::drawScoreboard()
{
    getTeam();
    Rectangle rec = {400, 0, 1100, 250};
    DrawRectangleRec(rec, Fade(SKYBLUE, 0.5f));
    DrawRectangleLinesEx(rec, 5, BLACK);
}