#ifndef PLAYER_PROJECTILE_HPP
#define PLAYER_PROJECTILE_HPP

#include <raylib.h>
#include "game_object.hpp"
#include "texture_details.hpp"

class PlayerProjectile : public GameObject {
    private:
        TextureDetails mTexture;
        float mSpeed;
    public:
        PlayerProjectile(Scene* scene, v2 startingPosition);

        virtual void Tick(float deltaTime) override;
        virtual void Render() override;
};

#endif //PLAYER_PROJECTILE_HPP
