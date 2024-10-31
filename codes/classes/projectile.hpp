#ifndef PROJECTILE_HPP //Tengp duda si debe ser PLAYER_PROJECTILE_HPP
#define PROJECTILE_HPP

#include <raylib.h>
#include "game_object.hpp"
#include "texture_details.hpp"

class Projectile : public GameObject {
    private:
        TextureDetails mTexture;
        GameObject* mOwner;
        std::string mTargetTag;
        float mSpeed;
        float mDamage;
    public:
        Projectile(Scene* scene, v2 startingPosition, GameObject* owner, const std::string& targetTag);

        virtual void Tick(float deltaTime) override;
        virtual void Render() override;

        virtual void OnCollision(GameObject* other) override;
        virtual void OnOutsideScene() override;
};

#endif //PLAYER_PROJECTILE_HPP
