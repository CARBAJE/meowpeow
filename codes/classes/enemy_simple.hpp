#ifndef ENEMY_SIMPLE_HPP
#define ENEMY_SIMPLE_HPP

#include <raylib.h>
#include "game_object.hpp"
#include "texture_details.hpp"

class EnemySimple : public GameObject {
    private:
        TextureDetails mTexture;
        v2 mDirection;
        float mSpeed;
        float mTime;
    public:
        EnemySimple(Scene* scene, v2 startingPosition);

        virtual void Tick(float deltaTime) override;
        virtual void Render() override;
        virtual void OnCollision(GameObject* other) override;
};

#endif //ENEMY_SIMPLE_HPP