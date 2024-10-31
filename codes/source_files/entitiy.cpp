#include "../classes/entity.hpp"

Entity::Entity(Scene* scene, v2 startingPosition, float health)
    : GameObject(scene, startingPosition), mHealth(health){

    }
