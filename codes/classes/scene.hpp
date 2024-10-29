#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <algorithm>

#include "math.hpp"

class GameObject;

class Scene {
    private:
        std::vector<GameObject*> mGameObjects;
        std::vector<GameObject*> mPendingGameObjectsToAdd;
        std::vector<GameObject*> mPendingGameObjectsToRemove;

    public:
        void Tick(float deltaTime);
        void Render();

        void Add(GameObject* go);

        bool DetectCollisions(GameObject* gameObject, v2 amount);
};

#endif //SCENE_HPP
