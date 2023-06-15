/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
    #define SPRITE_HPP_

    #include <raylib.h>
    #include <rlgl.h>
    #include "Shaders.hpp"
    #include <memory>

// typedef struct sprite_s {
//     Texture2D button;
// } sprite_t;

namespace Zappy {
    class Sprite {
        public:
            /**
             * @brief Construct a new Sprite object
             * 
             */
            Sprite(Texture2D top, Texture2D side, Texture2D bot, Shader _shader);
            Sprite(Texture2D top, Texture2D side, Texture2D bot);

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
            void drawBlockTexture(Vector3 position, Vector3 size, Color color);
            void drawWaterTexture(Vector3 position, Vector3 size, Color color);
        protected:
        private:
            Texture2D _top;
            Texture2D _side;
            Texture2D _bot;
            std::shared_ptr<Shaders> _shader;
            bool ret = false;
            float itemBounce = 0;
            float seconds = 0;
            float Rotation = 0;
    };
}

#endif /* !SPRITE_HPP_ */
