#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "math.hpp"

class GameObject;
class UIOverlay;
class Player;

class Scene {
    private:
        std::vector<GameObject*> mGameObjects;
        std::vector<GameObject*> mPendingGameObjectsToAdd;
        std::vector<GameObject*> mPendingGameObjectsToRemove;
        
        std::map<std::string, UIOverlay*> mUIOverlays;

        Player* mPlayer;

        AABB mSceneBounds;
        
        bool mDestroyed;
    public:
        //Scene();
    
        virtual void initialize();
        virtual void Destroy();
        
        void Tick(float deltaTime);
        void Render();

        void SetSceneBounds(v2 position, v2 size);

        void Add(GameObject* go);

        bool DetectCollisions(GameObject* gameObject, v2 amount);

        bool DetectOutsideOfScene(GameObject* gameObject, v2 amount);

        void SetPlayer(Player* player);
        Player* GetPlayer();
        
        void AddOverlay(const std::string& name, UIOverlay* overlay);
        
        UIOverlay* GetOverlay(const std::string& name);
        
        bool WasDestroyed();
        void ScheduleDestroy();
};

#endif //SCENE_HPP
