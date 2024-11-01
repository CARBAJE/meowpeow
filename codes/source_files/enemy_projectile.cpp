#include "enemy_projectile.hpp"
#include "enemy.hpp"
#include "entity.hpp"
#include "assets.hpp"

EnemyProjectile::EnemyProjectile(Scene* scene, v2 startingPosition, GameObject* owner, v2 direction)
    : Projectile(scene, startingPosition, mOwner, "Player"){

        mIdle = Assets::GetAnimation("enemy_projectile_animation");
        mDirection = direction;
        
        mSpeed = 10;

        mDamage = 1;
}
        

void EnemyProjectile::Tick(float deltaTime) {
    mIdle.Tick(deltaTime);
    Move({mDirection * mSpeed});
}

void EnemyProjectile::Render() {

    Rectangle destination = {};
    destination.x = mPosition.x;
    destination.y = mPosition.y;
    destination.width = 64;
    destination.height = 64;

    mIdle.Render(mPosition, {64, 64});
}

