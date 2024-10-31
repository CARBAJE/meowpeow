#include"../classes/animation.hpp"
#include<raylib.h>

Animation::Animation()
:mTime(0), mTimePerFrame(0), mCurrentFrame(-1){
}

void Animation::SetAnimationEndCallback(std::function<void()> callback){
        mCallback = callback;
    }
void Animation :: Tick(float deltaTime){
    mTime += deltaTime;
    if(mTime >= mTimePerFrame){
        mTime = 0;

        ++mCurrentFrame;
        mCurrentFrame %= mFrames.size();

        if(!mCurrentFrame ){
            if(mCallback){
                mCallback();}
        }
    }
}
    
void Animation :: Render(v2 position, v2 size, Color color){
    if(mCurrentFrame == -1){
        return;
    }

    Rectangle destination = {};
    destination.x = position.x;
    destination.y = position.y;
    destination.width = size.x; 
    destination.height = size.y;

    DrawTexturePro(mFrames[mCurrentFrame].texture, mFrames[mCurrentFrame].source, destination, {0, 0}, 0, color);
}

void Animation :: AddFrame(TextureDetails frame){
    mFrames.push_back(frame);
    mCurrentFrame = 0;
}


void Animation :: SetTimePerFrame (float time){
    mTimePerFrame = time;
}