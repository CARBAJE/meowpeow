#include <cmath>

#include "enemy_bonbon.hpp"
#include "assets.hpp"

EnemyBonbon::EnemyBonbon(Scene* scene, v2 startingPosition)
:Enemy(scene, startingPosition) {
    mIdle = Assets::GetAnimation("bonbon_idle");
    mSpeed = 7;
    mStartTimer=2; 
    mDirection={0, 0 }; 
    mStartedMoving =false; //si quitamos esta variable (y de la clase) 
    //podemos hacer un enemigo que siga al jugador hasta que lo destruya :)
}

void EnemyBonbon::Tick(float deltaTime) {
    mIdle.Tick(deltaTime);

    if(mStartTimer>0){
        mStartTimer-=deltaTime; 
    }

    if(mStartTimer <=0 && !mStartedMoving) {
        mStartedMoving=true; 
        mDirection= (mScene->GetPlayer()->mPosition - mPosition).Normalized(); 

    }

    if(mHurtTime > 0) {
        mHurtTime -= deltaTime;
    }

    if (mStartedMoving){
        Move(mDirection*mSpeed);
    }
}

void EnemyBonbon::Render() {

    Rectangle destination = {};
    destination.x = mPosition.x;
    destination.y = mPosition.y;
    destination.width = 64;
    destination.height = 64;
    mColor = (mHurtTime > 0) ? RED : WHITE;
    
    mIdle.Render(mPosition, {64, 64}, mColor);

}


