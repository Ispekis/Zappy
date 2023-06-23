/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** GameData
*/

#include "GameData.hpp"

// Zappy::GameData::GameData()
// {
// }l

Zappy::GameData::~GameData()
{
}

template <typename T>
static std::pair<std::vector<T>, std::vector<T>> separateVectorByIndex(std::vector<T> &content, std::size_t index)
{
    std::vector<T> begin(content.begin(), content.begin() + index);
    std::vector<T> end(content.begin() + index, content.end());
    return std::make_pair(begin, end);
}

static void checkInt(std::vector<std::string> &content)
{
    for (auto element : content)
        for (std::size_t i = 0; i != element.size(); i++)
            if (!std::isdigit(element[i]))
                throw Error("Error server response, element is not an int", content[i]);
}

void Zappy::GameData::msz(std::vector<std::string> &content)
{
    checkInt(content);
    if (content.size() != 2)
        throw Error("Error server response MSZ args", "Expected: 2, Got: " + std::to_string(content.size()));
    _mapSize = std::make_pair(std::stoi(content[0]), std::stoi(content[1]));
    for (std::size_t x = 0; x != _mapSize.first; x++) {
        std::vector<Tile> tmp;
        for (std::size_t y = 0; y != _mapSize.second; y++)
            tmp.push_back(Tile(x, y, _factory));
        _map.push_back(tmp);
    }
    _dataSet = true;
}

void Zappy::GameData::bct(std::vector<std::string> &content)
{
    checkInt(content);
    if (content.size() != 9)
        throw Error("Error server response MSZ args", "Expected: 9, Got: " + std::to_string(content.size()));
    int x = std::stoi(content[0]);
    int y = std::stoi(content[1]);
    content.erase(content.begin());
    content.erase(content.begin());
    _map[x][y].setRessources(content);

}

void Zappy::GameData::tna(std::vector<std::string> &content)
{
    if (content.size() != 1)
        throw Error("Error server response MSZ args", "Expected: 1, Got: " + std::to_string(content.size()));
    std::shared_ptr<Team> team = std::make_shared<Team>(content[0]);
    if (_teams.count(content[0]) > 0)
        return;
    _teams.insert({content[0], team});
}

void Zappy::GameData::pnw(std::vector<std::string> &content)
{
    std::vector<std::string> tmp = content;
    tmp.erase(tmp.end());
    checkInt(tmp);
    if (content.size() != 6)
        throw Error("Error server response MSZ args", "Expected: 6, Got: " + std::to_string(content.size()));
    std::cout << "pnw" << std::endl;

    if (_teams.count(content[5]) == 0)
        throw Error("team don't exist", content[5]);
    std::shared_ptr<Team> team = _teams[content[5]];
    std::shared_ptr<Player> player = std::make_shared<Player>(content, team);
    team->addPlayer(std::stoul(content[0]));
    player->setCurrentPosition(_tileSize, _mapSize);
    _player.insert({std::stoul(content[0]), player});
}

void Zappy::GameData::ppo(std::vector<std::string> &content)
{
    // std::cout << "ppo" << std::endl;
    checkInt(content);
    if (content.size() != 4)
        throw Error("Error server response PPO args", "Expected: 4, Got: " + std::to_string(content.size()));

    std::size_t id = std::stoul(content[0]);
    std::pair<std::size_t, std::size_t> newPosition = std::make_pair(std::stoul(content[1]), std::stoul(content[2]));
    Orientation newOrientation = static_cast<Orientation>(std::stoi(content[3]));

    if (_player.count(id) == 0)
        throw Error("player id don't exist", content[0]);
    printf("player %ld : [%ld:%ld] -> [%ld:%ld]", id, _player[id]->_position.first, _player[id]->_position.second, newPosition.first, newPosition.second);
    // std::cout << "player id:" << id << "moved to" << newPosition.first << ":" << newPosition.second << std::endl;

    _player[id]->setCurrentPosition(_tileSize, _mapSize);
    _player[id]->setPosition(newPosition);
    _player[id]->setOrientation(newOrientation);
}

void Zappy::GameData::plv(std::vector<std::string> &content)
{
    // std::cout << "plv" << std::endl;
    checkInt(content);
    if (content.size() != 2)
        throw Error("Error server response PLV args", "Expected: 2, Got: " + std::to_string(content.size()));

    std::size_t id = std::stoul(content[0]);
    std::size_t newLevel = std::stoul(content[1]);
    
    if (_player.count(id) == 0)
        throw Error("player id don't exist", content[0]);
    _player[id]->setLevel(newLevel);
    std::cout << "player id:" << id << "level is:" << newLevel << std::endl;

}

void Zappy::GameData::pin(std::vector<std::string> &content)
{
    std::cout << "pin" << std::endl;
    checkInt(content);
    if (content.size() != 10)
        throw Error("Error server response PIN args", "Expected: 10, Got: " + std::to_string(content.size()));

    std::size_t id = std::stoul(content[0]);
    if (_player.count(id) == 0)
        throw Error("player id don't exist", content[0]);

    auto newPosition = std::make_pair(std::stoul(content[1]), std::stoul(content[2]));
    _player[id]->setCurrentPosition(_tileSize, _mapSize);
    _player[id]->setPosition(newPosition);
    auto split = separateVectorByIndex(content, 2);
    _player[id]->setInventory(split.second);
    std::cout << "player id:" << id << "inventory set:" << std::endl;
}

void Zappy::GameData::pex(std::vector<std::string> &content)
{
    std::cout << "pex" << std::endl;
    if (content.size() != 1)
        throw Error("Error server response PEX args", "Expected: 1, Got: " + std::to_string(content.size()));
    checkInt(content);

    std::size_t id = std::stoul(content[0]);
    if (_player.count(id) == 0)
        throw Error("player id don't exist", content[0]);
    _player[id]->setEjectAnimation(true);
    // expulsion
}

void Zappy::GameData::pbc(std::vector<std::string> &content)
{
    std::cout << "pbc";
    std::size_t id = std::stoul(content[0]);
    if (content.size() != 2)
        throw Error("Error server response PIN args", "Expected: 2, Got: " + std::to_string(content.size()));
    checkInt(content);
    if (_player.count(id) == 0)
        throw Error("player id don't exist", content[0]);
    auto position = _player[id]->getPosition();

    broadcast_t e = {id, position, content[1]};
    _broadCast.addBroadCast(e);
    std::cout << ": New broadcast by player" << content[0] << ":" << content[1] << std::endl;
}

void Zappy::GameData::pic(std::vector<std::string> &content)
{
    std::cout << "pic:";
 
    std::cout << std::endl;
    checkInt(content);
    if (content.size() < 4)
        throw Error("Error server response PIC args", "Expected: >= 4, Got: " + std::to_string(content.size()));
    _incantationList.addIncantation(content);
    // Incantation start
}

void Zappy::GameData::pie(std::vector<std::string> &content)
{
    std::cout << "pie" << std::endl;
    // std::pair<std::size_t, std::size_t> position = std::make_pair(std::stoul(content[0]), std::stoul(content[1]));
    if (content.size() != 3)
        throw Error("Error server response PIN args", "Expected: 3, Got: " + std::to_string(content.size()));
    checkInt(content);

    _incantationList.endIncantation(content);
    // for (auto element : content)
    // {
        // printf("[%s] ", element.c_str());
    // };
}

void Zappy::GameData::pfk(std::vector<std::string> &content)
{
    std::cout << "pfk" << std::endl;
    // egg pond un oeuf
    if (content.size() != 1)
        throw Error("Error server response PFK args", "Expected: 1, Got: " + std::to_string(content.size()));
    checkInt(content);

    std::size_t id = std::stoul(content[0]);
    if (_player.count(id) == 0)
        throw Error("player id don't exist", content[0]);
    _player[id]->setEggLayingAnimation(true);
    printf("player :%ld is laying an egg\n", id);
}

void Zappy::GameData::pdr(std::vector<std::string> &content)
{
    std::cout << "pdr:";
    checkInt(content);
    if (content.size() != 2)
        throw Error("Error server response PIN args", "Expected: 2, Got: " + std::to_string(content.size()));
    std::size_t id = std::stoul(content[0]);
    if (_player.count(id) == 0)
        throw Error("player id don't exist", content[0]);
    _player[id]->setDropAnimation(true);
    std::cout << "Drop Animation added" << std::endl;
}

void Zappy::GameData::pgt(std::vector<std::string> &content)
{
    std::cout << "pgt:";
    checkInt(content);
    if (content.size() != 2)
        throw Error("Error server response PIN args", "Expected: 2, Got: " + std::to_string(content.size()));
    std::size_t id = std::stoul(content[0]);
    if (_player.count(id) == 0)
        throw Error("player id don't exist", content[0]);
    _player[id]->setPickAnimation(true);
    std::cout << "Pick Animation added" << std::endl;
}

void Zappy::GameData::pdi(std::vector<std::string> &content)
{
    std::cout << "pdi" << std::endl;
    checkInt(content);
    if (content.size() != 1)
        throw Error("Error server response PDI args", "Expected: 1, Got: " + std::to_string(content.size()));
    std::size_t playerId = std::stoul(content[0]);
    if (_player.count(playerId) == 0)
        throw Error("Error player don't exist", std::to_string(playerId));
    std::shared_ptr<Team> team = _player[playerId]->getTeam();
    team->deletePlayer(playerId);

    _player.erase(_player.find(playerId));
    std::cout << "Player : " << playerId << " died" << std::endl;
}

void Zappy::GameData::enw(std::vector<std::string> &content)
{
    checkInt(content);
    if (content.size() != 4)
        throw Error("Error server response ENW args", "Expected: 4, Got: " + std::to_string(content.size()));
    std::size_t playerId = std::stoul(content[1]);
    if (_player.count(playerId) == 0)
        throw Error("Error player don't exist", std::to_string(playerId));
    std::cout << "enw" << std::endl;
    _player[playerId]->setEggLayingAnimation(false);
    std::size_t eggId = std::stoul(content[0]);
    std::pair<std::size_t, std::size_t> position = {std::stoul(content[2]), std::stoul(content[3])};
    _egg.addEgg(eggId, position,_player[playerId]->getTeam()->getName(), playerId);
    printf("EGG id:%d [%d:%d]\n", eggId, position.first, position.second);
}

void Zappy::GameData::ebo(std::vector<std::string> &content)
{
    std::cout << "ebo" << std::endl;
    checkInt(content);
    if (content.size() != 1)
        throw Error("Error server response ebo args", "Expected: 1, Got: " + std::to_string(content.size()));
    size_t eggId = std::stoul(content[0]);
    if (_egg._eggList.count(eggId) == 0)
        throw Error("Error egg don't exist", std::to_string(eggId));
    _egg.connexionEgg(eggId);
    printf("player connected to egg id :%d\n", eggId);
}

void Zappy::GameData::edi(std::vector<std::string> &content)
{
    std::cout << "edi" << std::endl;
    checkInt(content);
    if (content.size() != 1)
        throw Error("Error server response EDI args", "Expected: 1, Got: " + std::to_string(content.size()));
    size_t eggId = std::stoul(content[0]);
    if (_egg._eggList.count(eggId) == 0)
        throw Error("Error egg don't exist", std::to_string(eggId));
    _egg.failedEgg(eggId);
    printf("egg id :%d destroyed\n", eggId);
}

void Zappy::GameData::sgt(std::vector<std::string> &content)
{
    // std::cout << "sgt" << std::endl;
    checkInt(content);
    if (content.size() != 1)
        throw Error("Error server response SGT args", "Expected: 1, Got: " + std::to_string(content.size()));
    int time = std::stoi(content[0]);
    if (time < 2)
        time = 2;
    if (time > 1000)
        time = 1000;
    _timeUnit.setTimeUnit(time);
}

void Zappy::GameData::sst(std::vector<std::string> &content)
{
    std::cout << "sst: Time Unit updated:" << content[0] << std::endl;
    _timeUnit.setTimeUnit(std::stof(content[0]));
}

void Zappy::GameData::seg([[maybe_unused]] std::vector<std::string> &content)
{
    std::cout << "seg: end game" << std::endl;
    _end = true;
}

void Zappy::GameData::smg([[maybe_unused]] std::vector<std::string> &content)
{
    std::cout << "smg:"<< content[0] << std::endl;
}

void Zappy::GameData::suc([[maybe_unused]] std::vector<std::string> &content)
{
    std::cout << "suc: unknow command" << std::endl;
}

void Zappy::GameData::sbp([[maybe_unused]] std::vector<std::string> &content)
{
    std::cout << "sbp" << std::endl;
}
