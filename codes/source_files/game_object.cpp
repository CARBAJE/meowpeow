#include "../classes/game_object.hpp"

GameObject::GameObject(Scene* scene, v2 startingPosition) 
    : mScene(scene), mPosition(startingPosition), mDeleted(false){
        mTag = "Empty Tag";
        mBoundsOffset = v2::Zero();
    }

bool GameObject::Move(v2 amount) {
    mPosition += amount;
    mBounds.Update(mPosition + mBoundsOffset, mBoundsSize);
    return mScene -> DetectCollisions(this, amount);
} 

void GameObject::Delete() {
    mDeleted = true;
}

bool GameObject::IsDeleted() {
    return mDeleted;
}

void GameObject::OnCollision(GameObject* other) {
}

void GameObject::OnSceneExit(){
}