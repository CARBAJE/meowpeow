#ifndef ENEMY_LIPS_HPP
#define ENEMY_LIPS_HPP

#include "enemy.hpp"

class EnemyLips : public Enemy{
    private:
        Animation mIdle;
        v2 mDirection;
        float mShootTime;

        void ShootAtPlayer();
    public: 
        EnemyLips(Scene* scene, v2 startingPosition) ; 

        virtual void Tick(float deltaTime) override;
        virtual void Render() override;

        virtual void OnOutsideScene() override;
};

#endif //ENEMY_LIPS_HPP
