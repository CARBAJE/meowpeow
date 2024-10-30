#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <raylib.h>
#include "game_object.hpp"
#include "texture_details.hpp"

class Enemy : public GameObject {
    private:
        TextureDetails mTexture;
        Color mColor;
        v2 mDirection;
        float mSpeed;
        float mTime;
        float mHealth;
        float mHurtTime;
    
    protected:
        void Death();
    public:
        Enemy(Scene* scene, v2 startingPosition);

        virtual void Tick(float deltaTime) override;
        virtual void Render() override;

        virtual void OnCollision(GameObject* other) override;
        virtual void OnSceneExit() override;

        virtual void ReciveDamage(float amount);
};

#endif //ENEMY_HPP