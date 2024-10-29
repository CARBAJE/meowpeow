//#include <cmath>
#include "../classes/enemy_simple.hpp"
#include "../classes/input.hpp"
#include "../classes/assets.hpp"

Color c;

EnemySimple::EnemySimple(Scene* scene, v2 startingPosition)
    : GameObject(scene, startingPosition){
        mTexture = Assets::GetTexture("enemy_simple");
        mSpeed = 10;
        mTime = 0;
        mDirection = {1, 0};
        c = WHITE;

        mSize = {64, 64};
        mBounds = AABB(mPosition, mSize);
    }

void EnemySimple::Tick(float deltaTime) {
    mTime += deltaTime;

    if(mTime > .5f) {
        mDirection.x *= -1;
        mTime = 0;
    }

    Move(mDirection * mSpeed);
}

void EnemySimple::Render() {

    Rectangle destination = {};
    destination.x = mPosition.x;
    destination.y = mPosition.y;
    destination.width = 64;
    destination.height = 64;

    DrawTexturePro(mTexture.texture, mTexture.source, destination, {0, 0}, 0, c);
    c = WHITE;
}

void EnemySimple::OnCollision(GameObject* other) {
    c = RED;
}