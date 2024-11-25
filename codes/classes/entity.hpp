#ifndef ENTITY_HPP
#define ENTITY_HPP


#include <raylib.h>

#include "game_object.hpp"
#include "texture_details.hpp"

class Entity : public GameObject {
    protected: 
        int mHealth;
    public: 
        Entity(Scene* scene, v2 startingPosition, int health);

        virtual void ReceiveDamage(int amount) = 0;
        virtual void Death() = 0;
        int GetHealth() const;
};

#endif //ENTITY_HPP
