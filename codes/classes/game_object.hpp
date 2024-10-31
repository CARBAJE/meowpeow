#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <string>

#include "scene.hpp"
#include "math.hpp"

class GameObject {
    public:
        Scene* mScene;
        v2 mPosition;

        AABB mBounds;
        v2 mBoundsOffset;
        v2 mBoundsSize;

        bool mRestrictMovementInScene;

        std::string mTag;

        GameObject(Scene* scene, v2 startingPosition);

        virtual void Tick(float deltaTime) = 0;
        virtual void Render();

        virtual void OnCollision(GameObject* other);
        virtual void OnOutsideScene();

        bool IsDeleted();
    
    protected:
        bool mDeleted;
        bool Move(v2 amount);

        void Delete();
};

#endif //GAME_DEFINE_HPP
