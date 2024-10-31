#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <raylib.h>

#include "game_object.hpp"
#include "texture_details.hpp"
#include "entity.hpp"
#include "animation.hpp"
class Enemy : public Entity {
    protected:
  
        Color mColor;
        float mSpeed;
        float mTime;
        float mHurtTime;
    
        virtual void Death();
    public:
        Enemy(Scene* scene, v2 startingPosition);

        virtual void Tick(float deltaTime) override;
        virtual void Render() override;

        virtual void OnCollision(GameObject* other) override;
        virtual void OnOutsideScene() override;

        virtual void ReceiveDamage(float amount) ;
};

#endif //ENEMY_HPP