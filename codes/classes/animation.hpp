#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "texture_details.hpp"
#include "math.hpp"
#include <vector>
#include <functional>
class Animation{
public:

    Animation(); 

    void Tick(float deltaTime);
    void Render(v2 position, v2 size, Color color=WHITE); 

    void SetTimePerFrame(float time);
    void AddFrame(TextureDetails frame);
    
    void SetAnimationEndCallback(std::function<void()> callback);    
private:
    std::vector<TextureDetails> mFrames;
    int mCurrentFrame;
    float mTime;
    float mTimePerFrame;
    std::function<void()> mCallback;
}; 

#endif //ANIMATION_HPP