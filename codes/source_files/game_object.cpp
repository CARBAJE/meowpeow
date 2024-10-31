#include "../classes/game_object.hpp"

GameObject::GameObject(Scene* scene, v2 startingPosition) 
    : mScene(scene), mPosition(startingPosition), mDeleted(false){
        mTag = "Empty Tag";
        mRestrictMovementInScene = false;
        mBoundsOffset = v2::Zero();
    }

bool GameObject::Move(v2 amount) {
    
    mScene -> DetectCollisions(this, amount);
    
    bool outsideScene= mScene -> DetectOutsideOfScene(this, amount);
    if (outsideScene) {
        if(mRestrictMovementInScene){
            return false;
        }
    }

    mPosition += amount;
    mBounds.Update(mPosition + mBoundsOffset, mBoundsSize);
   
    return true;
} 
void GameObject::Render() {
}   
void GameObject::Delete() {
    mDeleted = true;
}

bool GameObject::IsDeleted() {
    return mDeleted;
}

void GameObject::OnCollision(GameObject* other) {
}

void GameObject::OnOutsideScene(){
}