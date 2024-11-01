#ifndef ENEMY_PROJECTILE_HPP
#define ENEMY_PROJECTILE_HPP

#include <raylib.h>

#include "animation.hpp"
#include "projectile.hpp"
#include "game_object.hpp"
#include "texture_details.hpp"

class EnemyProjectile : public Projectile {
    private:
        Animation mIdle; 
        v2 mDirection;
    public:
        EnemyProjectile(Scene* scene, v2 startingPosition, GameObject* owner, v2 direction); 
       
        virtual void Tick(float deltaTime) override;
        virtual void Render() override;

};

#endif //ENEMY_PROJECTILE_HPP