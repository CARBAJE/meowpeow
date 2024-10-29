#include "../classes/game_object.hpp"

GameObject::GameObject(Scene* scene, v2 startingPosition) 
    : mScene(scene), mPosition(startingPosition), mDeleted(false){
        
    }

bool GameObject::Move(v2 amount) {
    mPosition += amount;
    mBounds.Update(mPosition, mSize);
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