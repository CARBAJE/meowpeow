//#include <cmath>
#include "../classes/enemy.hpp"
#include "../classes/input.hpp"
#include "../classes/assets.hpp"

Enemy::Enemy(Scene* scene, v2 startingPosition)
    : GameObject(scene, startingPosition){
        mTexture = Assets::GetTexture("enemy_simple");
        mTag = "Enemy";
        mSpeed = 10;
        mTime = 0;
        mDirection = {1, 0};
        mColor = WHITE;

        mHealth = 3;

        mBoundsSize = {50, 50};
        mBoundsOffset = {4, 4};
        mBounds = AABB(mPosition + mBoundsOffset, mBoundsSize);
    }

void Enemy::Tick(float deltaTime) {
    mTime += deltaTime;

    //if(mTime > .5f) {
    //    mDirection.x *= -1;
    //    mTime = 0;
    //}

    if(mHurtTime > 0) {
        mHurtTime -= deltaTime;
    }

    Move(mDirection * mSpeed);
}

void Enemy::OnSceneExit() {
    mDirection.x *= -1;
}

void Enemy::Render() {

    Rectangle destination = {};
    destination.x = mPosition.x;
    destination.y = mPosition.y;
    destination.width = 64;
    destination.height = 64;
    mColor = (mHurtTime > 0) ? RED : WHITE;

    DrawTexturePro(mTexture.texture, mTexture.source, destination, {0, 0}, 0, mColor);
    
    DrawRectangleLines(mBounds.x0 + mBoundsOffset.x, mBounds.y0 + mBoundsOffset.y, mBoundsSize.x, mBoundsSize.y, RED);

    //mColor = WHITE
}

void Enemy::ReciveDamage(float amount) {
    mHurtTime = 0.1f;
    mHealth -= amount;
    if (mHealth <= 0) {
        Death();
    }
}

void Enemy::Death() {
    Delete();
}

void Enemy::OnCollision(GameObject* other) {
    mColor = RED;
}