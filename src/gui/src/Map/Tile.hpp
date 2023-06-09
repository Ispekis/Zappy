/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Tile
*/

#ifndef TILE_HPP_
#define TILE_HPP_
    #include <memory>
    #include <vector>
    #include <string>
    #include <sstream>
    #include <iostream>

    #include "IRessource.hpp"
    #include "RessourceFactory.hpp"

namespace Zappy {
    class Tile {
        public:
            Tile();
            Tile(std::size_t x, std::size_t y);
            Tile(std::string &content);
            ~Tile();

            /**
             * @brief Get the position of the Tile
             * 
             * @return std::pair<std::size_t, std::size_t> 
             */
            std::pair<std::size_t, std::size_t> getPosition() const;

            /**
             * @brief Get the ressources list on the Tile
             * 
             * @return std::vector<std::shared_ptr<IRessource>> 
             */
            std::vector<std::shared_ptr<IRessource>> getRessources() const;

        protected:
        private:
            std::vector<std::shared_ptr<IRessource>> _ressources;
            std::pair<std::size_t, std::size_t> _position;
    };
};

#endif /* !TILE_HPP_ */
