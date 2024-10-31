#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>
#include "game_object.hpp"
#include "texture_details.hpp"
#include "entity.hpp"

class Player : public Entity {
    private:
        TextureDetails mTexture;
        float mSpeed;
        float mAttackSpeed;
        float mAttackTime;
    public:
        Player(Scene* scene, v2 startingPosition);

        virtual void Tick(float deltaTime) override;
        virtual void Render() override;

        virtual void ReceiveDamage(float amount) override;
};

#endif //PLAYER_HPP
