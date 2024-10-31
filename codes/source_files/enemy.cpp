//#include <cmath>
#include "../classes/enemy.hpp"
#include "../classes/input.hpp"
#include "../classes/assets.hpp"
#include "../classes/entity.hpp"
#include "../classes/explosion_particle.hpp"

Enemy::Enemy(Scene* scene, v2 startingPosition)
    : Entity(scene, startingPosition, 5){
        //mTexture = Assets::GetTexture("enemy_simple");
        mTag = "Enemy";
        
        mSpeed = 3;
        mTime = 0;
        //mDirection = {1, 0};
        mColor = WHITE;

        mBoundsSize = {50, 50};
        mBoundsOffset = {4, 4};
        mBounds = AABB(mPosition + mBoundsOffset, mBoundsSize);
    }

void Enemy::Tick(float deltaTime) {
  
}

void Enemy::OnOutsideScene() {
}

void Enemy::Render() {

}

void Enemy::ReceiveDamage(float amount) {
    mHurtTime = 0.1f;
    mHealth -= amount;
    if (mHealth <= 0) {
        Death();
    }
}

void Enemy::Death() {
    Delete();
    mScene->Add(new ExplosionParticle(mScene, mPosition));
}

void Enemy::OnCollision(GameObject* other) {
    mColor = RED;
}