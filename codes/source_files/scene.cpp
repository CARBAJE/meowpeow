#include "../classes/scene.hpp"
#include "../classes/game_object.hpp"

void Scene::SetSceneBounds(v2 position, v2 size){
    mSceneBounds.Update(position, size);
}

void Scene::Tick(float deltaTime) {
    for (auto& go: mPendingGameObjectsToAdd) {
        mGameObjects.push_back(go);
    }
    mPendingGameObjectsToAdd.clear();

    for (auto& go: mGameObjects) {
        go -> Tick(deltaTime);
        if (go -> IsDeleted()) {
            mPendingGameObjectsToRemove.push_back(go);
        }
        else if (!AABB::Intersects(mSceneBounds, go->mBounds)){
            go -> OnSceneExit();
        }
    }

    for (auto go: mPendingGameObjectsToRemove) {
        auto it = std::find(mGameObjects.begin(), mGameObjects.end(), go);
        mGameObjects.erase(it);
    }
    mPendingGameObjectsToRemove.clear();
}

void Scene::Render() {
    for (auto& go: mGameObjects) {
        go -> Render();
    }
}

void Scene::Add(GameObject* go) {
    mPendingGameObjectsToAdd.push_back(go);
}

bool Scene::DetectCollisions(GameObject* gameObject, v2 amount) {
    bool result = false;

    AABB futureAABB = gameObject -> mBounds;
    futureAABB.Update(gameObject->mPosition + gameObject -> mBoundsOffset + amount, gameObject->mBoundsSize);

    for (auto& go: mGameObjects) {
        if (go == gameObject) {
            continue;
        }
        
        if (AABB::Intersects(go->mBounds, futureAABB)){
            result = true;
            go -> OnCollision(gameObject);
            gameObject -> OnCollision(go);
        }
    }

    return result;
}