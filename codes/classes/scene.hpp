#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

class GameObject;

class Scene {
    private:
        std::vector<GameObject*> mGameObject;

    public:
        void Tick(float deltaTime);
        void Render();

        void Add(GameObject* go);
};

#endif //SCENE_HPP
