#ifndef EXPLOSION_PARTICLE_HPP
#define EXPLOSION_PARTICLE_HPP
#include "game_object.hpp"
#include "texture_details.hpp"
#include "animation.hpp"
#include "assets.hpp"
class ExplosionParticle : public GameObject {
    private: 
        Animation mIdle; 
    public:
        ExplosionParticle(Scene* scene, v2 Position)
        : GameObject(scene, Position){
            mIdle = Assets::GetAnimation("explosion_animation");
            mIdle.SetAnimationEndCallback([this](){
                Delete();
            });
        }

        void Tick(float deltaTime) {
            mIdle.Tick(deltaTime);
        }
        void Render() {
            mIdle.Render(mPosition, {64, 64}, WHITE);
        }
}; 

#endif //EXPLOSION_PARTICLE_HPP