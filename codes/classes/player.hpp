#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>
#include "game_object.hpp"
#include "texture_details.hpp"

class Player : public GameObject {
    private:
        TextureDetails mTexture;
        float mSpeed;
    public:
        Player(Scene* scene, v2 startingPosition);

        virtual void Tick(float deltaTime) override;
        virtual void Render() override;
};

#endif //PLAYER_HPP
