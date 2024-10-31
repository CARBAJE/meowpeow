#include "../classes/player.hpp"
#include "../classes/projectile.hpp"
#include "../classes/input.hpp"
#include "../classes/assets.hpp"


Player::Player(Scene* scene, v2 startingPosition)
    : Entity(scene, startingPosition, 10){ //10 de vida por ajora
        mTexture = Assets::GetTexture("player_left");
        mSpeed = 10;
        mAttackSpeed = 200.0f / 1000.0f;//1.0f / 5.0f;
        mAttackTime = 0;

        mBoundsSize = {64, 64};
        mBounds = AABB(mPosition , mBoundsSize);

        mRestrictMovementInScene = true;
    }

void Player::Tick(float deltaTime) {
    float h = Input::GetHorizontalAxis();
    float v = Input::GetVerticalAxis();

    if(mAttackTime > 0){
        mAttackTime -= deltaTime;
    }

    if(Input::KeyDown(KEY_SPACE) && mAttackTime <= 0) {
        mScene->Add(new Projectile(mScene, mPosition, this, "Enemy"));
        mAttackTime = mAttackSpeed;
    }

    
    if (h!=0 || v!=0) {
        v2 velocity = {h * mSpeed, v * mSpeed};
        Move(velocity);

    }

    if (h < 0) {
        mTexture = Assets::GetTexture("player_left");
    }
    else if (h > 0) {
        mTexture = Assets::GetTexture("player_right");
    }
    else{
        mTexture = Assets::GetTexture("player_neutral");
    }
}

void Player::Render() {

    Rectangle destination = {};
    destination.x = mPosition.x;
    destination.y = mPosition.y;
    destination.width = 64;
    destination.height = 64;

    DrawTexturePro(mTexture.texture, mTexture.source, destination, {0, 0}, 0, WHITE);
}

void Player::ReceiveDamage(float amount) {
    mHealth -= amount;
 
  
}
