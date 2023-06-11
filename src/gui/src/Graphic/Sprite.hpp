/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
    #define SPRITE_HPP_

    #include <raylib.h>
namespace Zappy {
    class Sprite {
        public:
            /**
             * @brief Construct a new Sprite object
             * 
             */
            Sprite();

            /**
             * @brief Set the Texture object
             * 
             */
            void setTexture();

            /**
             * @brief Set the Position object
             * 
             */
            void setPosition();

            /**
             * @brief Set the Scale object
             * 
             */
            void setScale();

            /**
             * @brief Destroy the Sprite object
             * 
             */
            ~Sprite();

        protected:
        private:
    };
}

#endif /* !SPRITE_HPP_ */
