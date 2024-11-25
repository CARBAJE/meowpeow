#include "../classes/entity.hpp"

Entity::Entity(Scene* scene, v2 startingPosition, int health)
    : GameObject(scene, startingPosition), mHealth(health){

    }
    
int Entity::GetHealth() const {
  return mHealth;
}
