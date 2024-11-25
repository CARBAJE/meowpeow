#ifndef ENEMY_BONBON_HPP
#define ENEMY_BONBON_HPP

#include "enemy.hpp"

class EnemyBonbon : public Enemy{
    private:
        Animation mIdle;
        v2 mDirection;
        float mStartTimer; 
        bool mStartedMoving; 
    public: 
        EnemyBonbon(Scene* scene, v2 startingPosition) ; 

        virtual void Tick(float deltaTime) override;
        virtual void Render() override;
        virtual void OnOutsideScene() override;

};


#endif //ENEMY_BONBON_HPP
