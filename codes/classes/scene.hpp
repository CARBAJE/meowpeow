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

        GameObject* mPlayer;

        AABB mSceneBounds;
    public:
        void Tick(float deltaTime);
        void Render();

        void SetSceneBounds(v2 position, v2 size);

        void Add(GameObject* go);

        bool DetectCollisions(GameObject* gameObject, v2 amount);

        bool DetectOutsideOfScene(GameObject* gameObject, v2 amount);

        void SetPlayer(GameObject* player);
        GameObject* GetPlayer();
};

#endif //SCENE_HPP
