#include "enemy_lips.hpp"
#include "assets.hpp"
#include <cmath>

EnemyLips::EnemyLips(Scene* scene, v2 startingPosition)
:Enemy(scene, startingPosition) {
    mIdle = Assets::GetAnimation("lips_idle");
    mSpeed = 10;
}

void EnemyLips::Tick(float deltaTime) {
    mIdle.Tick(deltaTime);
    mTime += deltaTime;

    mDirection.x = std::sin(mTime*7) * mSpeed;  //circulo /ovalo
    mDirection.y = std::cos(mTime*7) * mSpeed;

    mDirection.y+=mSpeed/10.f; //hace que vaya para abajo
    //mDirection.x+=mSpeed/10; //hace que vaya para la derecha

    if(mHurtTime > 0) {
        mHurtTime -= deltaTime;
    }

    Move(mDirection);
}

void EnemyLips::Render() {

    Rectangle destination = {};
    destination.x = mPosition.x;
    destination.y = mPosition.y;
    destination.width = 64;
    destination.height = 64;
    mColor = (mHurtTime > 0) ? RED : WHITE;
    
    mIdle.Render(mPosition, {64, 64}, mColor);

}

void EnemyLips::OnOutsideScene() {
}