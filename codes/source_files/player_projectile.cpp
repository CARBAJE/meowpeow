#include "../classes/player_projectile.hpp"
#include "../classes/input.hpp"
#include "../classes/assets.hpp"

PlayerProjectile::PlayerProjectile(Scene* scene, v2 startingPosition)
    : GameObject(scene, startingPosition){
        mTexture = Assets::GetTexture("player_projectile");
        mSpeed = 20;
    }

void PlayerProjectile::Tick(float deltaTime) {
    mPosition.y -= mSpeed;
}

void PlayerProjectile::Render() {

    Rectangle destination = {};
    destination.x = mPosition.x;
    destination.y = mPosition.y;
    destination.width = 64;
    destination.height = 64;

    DrawTexturePro(mTexture.texture, mTexture.source, destination, {0, 0}, 0, WHITE);
}

