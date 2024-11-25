#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>
#include "game_object.hpp"
#include "texture_details.hpp"
#include "entity.hpp"
#include "animation.hpp"
#include "explosion_particle.hpp"

class Player : public Entity {
    private:
        TextureDetails* mTexture;
        Animation* mBoosters; 

        TextureDetails mShipTextures[3];
        Animation mBoostersAnimations[3];

        float mSpeed;
        float mAttackSpeed;
        float mAttackTime;
        float mHurtTime;
        
        Color mColor;
        
    public:
        Player(Scene* scene, v2 startingPosition);

        virtual void Tick(float deltaTime) override;
        virtual void Render() override;

        virtual void ReceiveDamage(int amount) override;
        virtual void Death() override;
};

#endif //PLAYER_HPP
