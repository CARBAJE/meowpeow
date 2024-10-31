#ifndef ENEMY_ALAN_HPP
#define ENEMY_ALAN_HPP

#include "enemy.hpp"

class EnemyAlan : public Enemy{
    private:
        Animation mIdle;
        v2 mDirection;
    public: 
        EnemyAlan(Scene* scene, v2 startingPosition) ; 

        virtual void Tick(float deltaTime) override;
        virtual void Render() override;

        virtual void OnOutsideScene() override;
}; 

#endif //ENEMY_ALAN_HPP
