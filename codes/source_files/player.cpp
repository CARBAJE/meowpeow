#include "../classes/player.hpp"
#include "../classes/input.hpp"
#include "../classes/assets.hpp"

Player::Player(Scene* scene, v2 startingPosition)
    : GameObject(scene, startingPosition){
        mTexture = Assets::GetTexture("player_left");
        mSpeed = 10;
    }

void Player::Tick(float deltaTime) {
    float h = Input::GetHorizontalAxis();
    float v = Input::GetVerticalAxis();

    mPosition.x += h * mSpeed;
    mPosition.y += v * mSpeed;

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

