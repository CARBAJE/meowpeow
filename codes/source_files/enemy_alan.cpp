#include "enemy_alan.hpp"
#include "assets.hpp"

EnemyAlan::EnemyAlan(Scene* scene, v2 startingPosition)
:Enemy(scene, startingPosition) {
    mIdle = Assets::GetAnimation("alan_idle");
    mSpeed = 10;
    mDirection = {1, 0.06f};
} 

void EnemyAlan::Tick(float deltaTime) {
    mIdle.Tick(deltaTime);
    mTime += deltaTime;

    if(mHurtTime > 0) {
        mHurtTime -= deltaTime;
    }

    Move(mDirection * mSpeed);
}

void EnemyAlan::Render() {

    Rectangle destination = {};
    destination.x = mPosition.x;
    destination.y = mPosition.y;
    destination.width = 64;
    destination.height = 64;
    mColor = (mHurtTime > 0) ? RED : WHITE;

    //DrawTexturePro(mTexture.texture, mTexture.source, destination, {0, 0}, 0, mColor);
    
    mIdle.Render(mPosition, {64, 64}, mColor);

    //DrawRectangleLines(mBounds.x0 + mBoundsOffset.x, mBounds.y0 + mBoundsOffset.y, mBoundsSize.x, mBoundsSize.y, RED);

}

void EnemyAlan::OnOutsideScene() {
    mDirection.x *= -1;
    if(mPosition.y > 8 * 64){
      Delete();
    }
}

    
