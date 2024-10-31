#ifndef ENTITY_HPP
#define ENTITY_HPP


#include <raylib.h>

#include "game_object.hpp"
#include "texture_details.hpp"

class Entity : public GameObject {
    protected: 
        float mHealth;
    public: 
        Entity(Scene* scene, v2 startingPosition, float health);

        virtual void ReceiveDamage(float amount) = 0;

};

#endif //ENTITY_HPP