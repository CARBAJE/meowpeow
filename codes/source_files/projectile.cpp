#include "../classes/projectile.hpp"
#include "../classes/input.hpp"
#include "../classes/assets.hpp"
#include "../classes/enemy.hpp"
#include "../classes/entity.hpp"

Projectile::Projectile(Scene* scene, v2 startingPosition, GameObject* owner, const std::string& targetTag)
    : GameObject(scene, startingPosition){
        mTargetTag = targetTag;
        mOwner = owner;
        mTag = "Projectile";
        mTexture = Assets::GetTexture("player_projectile");
        mSpeed = 20;

        mDamage = 1;

        mBoundsSize = {48, 40};//{64, 64};
        mBoundsOffset = {4, 4};
        mBounds = AABB(mPosition + mBoundsOffset, mBoundsSize);
}

void Projectile::Tick(float deltaTime) {
    Move({0, -mSpeed});
}

void Projectile::Render() {

    Rectangle destination = {};
    destination.x = mPosition.x;
    destination.y = mPosition.y;
    destination.width = 64;
    destination.height = 64;

    DrawTexturePro(mTexture.texture, mTexture.source, destination, {0, 0}, 0, WHITE);

    //DrawRectangleLines(mBounds.x0 + mBoundsOffset.x, mBounds.y0 + mBoundsOffset.y, mBoundsSize.x, mBoundsSize.y, RED);
}

void Projectile::OnCollision(GameObject* other) {
    if (other == mOwner) {
        return;
    }
    if (other->mTag == mTag) {
        return;
    }
    if (other->mTag == mTargetTag) {
        Entity* enemy = dynamic_cast<Entity*>(other); //entity son las cosas que tienen vida o las que peuden ser danadas 

        if(!enemy) {
            return;
        }

        enemy -> ReceiveDamage(mDamage);

        Delete();
    }
   
}

void Projectile::OnOutsideScene() {
    Delete();
}