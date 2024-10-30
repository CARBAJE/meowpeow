#include "../classes/player_projectile.hpp"
#include "../classes/input.hpp"
#include "../classes/assets.hpp"
#include "../classes/enemy.hpp"

PlayerProjectile::PlayerProjectile(Scene* scene, v2 startingPosition)
    : GameObject(scene, startingPosition){
        mTag = "Projectile";
        mTexture = Assets::GetTexture("player_projectile");
        mSpeed = 20;

        mDamage = 1;

        mBoundsSize = {48, 40};//{64, 64};
        mBoundsOffset = {4, 4};
        mBounds = AABB(mPosition + mBoundsOffset, mBoundsSize);
    }

void PlayerProjectile::Tick(float deltaTime) {
    Move({0, -mSpeed});
}

void PlayerProjectile::Render() {

    Rectangle destination = {};
    destination.x = mPosition.x;
    destination.y = mPosition.y;
    destination.width = 64;
    destination.height = 64;

    DrawTexturePro(mTexture.texture, mTexture.source, destination, {0, 0}, 0, WHITE);

    //DrawRectangleLines(mBounds.x0 + mBoundsOffset.x, mBounds.y0 + mBoundsOffset.y, mBoundsSize.x, mBoundsSize.y, RED);
}

void PlayerProjectile::OnCollision(GameObject* other) {
    if (other->mTag == mTag) {
        return;
    }
    if (other->mTag == "Enemy") {
        Enemy* enemy = dynamic_cast<Enemy*>(other);

        if(!enemy) {
            return;
        }

        enemy -> ReciveDamage(mDamage);
    }
    Delete();
}

void PlayerProjectile::OnSceneExit() {
    Delete();
}