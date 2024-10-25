#include "../classes/scene.hpp"
#include "../classes/game_object.hpp"

void Scene::Tick(float deltaTime) {
    for (auto& go: mPendingGameObjectsToAdd) {
        mGameObject.push_back(go);
    }
    mPendingGameObjectsToAdd.clear();

    for (auto& go: mGameObject) {
        go -> Tick(deltaTime);
    }
}

void Scene::Render() {
    for (auto go: mGameObject) {
        go -> Render();
    }
}

void Scene::Add(GameObject* go) {
    mPendingGameObjectsToAdd.push_back(go);
}
