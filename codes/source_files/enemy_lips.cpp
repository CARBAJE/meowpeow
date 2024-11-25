#include "enemy_lips.hpp"
#include "assets.hpp"
#include "enemy_projectile.hpp"
#include "player.hpp"
#include <cmath>

EnemyLips::EnemyLips(Scene* scene, v2 startingPosition)
:Enemy(scene, startingPosition) {
    mIdle = Assets::GetAnimation("lips_idle");
    mSpeed = 10;
}

void EnemyLips::Tick(float deltaTime) {
    mIdle.Tick(deltaTime);

    mShootTime += deltaTime;
    if(mShootTime > 3) {
       ShootAtPlayer(); 
        mShootTime = 0;
    }

    mTime += deltaTime;

    mDirection.x = std::sin(mTime*9) * mSpeed;  //circulo /ovalo
    mDirection.y = std::cos(mTime*9) * mSpeed;

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
void EnemyLips::ShootAtPlayer() {
    if(mScene->GetPlayer()){
      v2 direction = (mScene->GetPlayer()->mPosition - mPosition).Normalized();
      mScene->Add(new EnemyProjectile(mScene, mPosition, this, direction));
    }   
}
void EnemyLips::OnOutsideScene() {
    //mDirection.x *= -1;
    if(mPosition.y > 8 * 64){
      Delete();
    }
}
