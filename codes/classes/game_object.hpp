#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "scene.hpp"
#include "math.hpp"

class GameObject {
    public:
        Scene* mScene;
        v2 mPosition;

        GameObject(Scene* scene, v2 startingPosition);

        virtual void Tick(float deltaTime) = 0;
        virtual void Render() = 0;
};

#endif //GAME_DEFINE_HPP
