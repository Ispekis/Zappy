/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Player
*/


#ifndef PLAYER_HPP_
#define PLAYER_HPP_
    #include <string>
    #include <unordered_map>
    #include <memory>
    #include <vector>

    #include "IRessource.hpp"
    #include "Team.hpp"

namespace Zappy {
    enum Orientation
    {
        N = 1,
        E,
        S,
        W
    };

    class Player
    {
    public:
        Player(std::vector<std::string> &content, std::shared_ptr<Zappy::Team>);
        ~Player();

        /**
         * @brief Get the Id of the player
         * 
         * @return std::size_t 
         */
        std::size_t getId() const;

        /**
         * @brief Get the Position of the player
         * 
         * @return std::pair<std::size_t, std::size_t> 
         */
        std::pair<std::size_t, std::size_t> getPosition() const;

        /**
         * @brief Get the Ressources of the player
         * 
         * @return std::unordered_map<std::string, std::shared_ptr<IRessource>> 
         */
        std::unordered_map<std::string, std::size_t> getInventory() const;

        /**
         * @brief Get the Orientation of the player
         * 
         * @return Orientation 
         */
        Orientation getOrientation() const;

        /**
         * @brief Get the Team of the player
         * 
         * @return std::shared_ptr<Team> 
         */
        std::shared_ptr<Team> getTeam() const;

        /**
         * @brief Get the Level of the player
         * 
         * @return std::size_t 
         */
        std::size_t getLevel() const;


        /**
         * @brief Set the Position of the player
         * 
         */
        void setPosition(std::pair<std::size_t, std::size_t>);

        /**
         * @brief Set the Inventory of the player
         * 
         */
        void setInventory(std::vector<std::string>);

        /**
         * @brief Set the Orientation of the player
         * 
         */
        void setOrientation(Orientation);

        /**
         * @brief Set the Level of the player
         * 
         * @param level 
         */
        void setLevel(std::size_t level);

        /**
         * @brief Set the Incantation state of the player
         * 
         */
        void setIncantation(bool);

        void setDropAnimation(bool);
        void setPickAnimation(bool);

    protected:
    private:
        std::pair<std::size_t, std::size_t> _position;
        std::unordered_map<std::string, std::size_t> _inventory;
        Orientation _orientation;
        std::shared_ptr<Team> _team;
        std::size_t _level;
        std::size_t _id;
        std::vector<std::string> ressource = {"Food", "Linemate", "Deraumere", "Sibur", "Mendiane", "Phiras", "Thystame"};
        bool _incantation;

        bool _drop;
        bool _pick;
    };
}

#endif /* !PLAYER_HPP_ */
