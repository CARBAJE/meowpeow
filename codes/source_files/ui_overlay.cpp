#include "raylib.h"
#include "../classes/ui_overlay.hpp"
#include "../classes/assets.hpp"
#include "../classes/scene.hpp"
#include "../classes/player.hpp"
#include "../classes/settings.hpp"
#include "../classes/scene_manager.hpp"

UIOverlay::UIOverlay(Scene* scene)
: mScene(scene){
}

void UIOverlay::Tick(float deltaTime){
}

void UIOverlay::Render(){
}

HudOverlay::HudOverlay(Scene* scene)
: UIOverlay(scene){
  mPlayerHealthTexture = Assets::GetTexture("player_life");
  mFadeAlpha = 0;
  mFadeColor = BLACK;
  //fa
}

void HudOverlay::FadeScreen(){
  mFading = true; 
}

void HudOverlay::Tick(float deltaTime){
  if(mFading){
    mFadeAlpha += deltaTime * 100;
    if(mFadeAlpha > 255){
      mFading = false;
      SceneManager::PopScene();
   }
  }
  mFadeColor.a = mFadeAlpha;
}

void HudOverlay::Render(){
  auto player = mScene->GetPlayer();
  if(player){
    //return;
  //}
  
  for(int i = 0; i < player->GetHealth(); ++i){
    Rectangle destination={};
    float padding = 4;
    float size = 48;
    destination.x = 16 + i * (size + padding);
    destination.y = 16;
    destination.width = size;
    destination.height = size;
    
    DrawTexturePro(mPlayerHealthTexture.texture, mPlayerHealthTexture.source,destination, {0,0}, 0, WHITE);
  }
  }
  //if(mFading){
    DrawRectangle(0,0,Settings::screenWidth, Settings::screenHeight, mFadeColor);
   //}
}
