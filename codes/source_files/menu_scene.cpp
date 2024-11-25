#include "../classes/menu_scene.hpp"
#include "../classes/assets.hpp"
#include "../classes/settings.hpp"
#include "../classes/scene_manager.hpp"
#include <iostream>

UIImageButton::UIImageButton()
: mHot(false),mHovered(false),mTexture(nullptr),mColor(WHITE){
  
}

void UIImageButton::SetTexture(TextureDetails* texture){
  mTexture = texture;
}

void UIImageButton::SetBounds(float ax,float ay,float aw,float ah){
  x = ax;
  y = ay;
  w = aw;
  h = ah;
}
  
bool UIImageButton::Clicked(){
  Vector2 mousePosition = GetMousePosition();
  bool released = IsMouseButtonReleased(0);
  bool pressed = IsMouseButtonPressed(0);
  //bool result = false;
  
  if((mousePosition.x >= x && mousePosition.x <= (x + w)) && (mousePosition.y >= y && mousePosition.y <= (y + h))){
      mHovered = true;
  } else {
      mHovered = false;
  }
  
  //static bool hot = 
  if(pressed){
    if((mousePosition.x >= x && mousePosition.x <= (x + w)) && (mousePosition.y >= y && mousePosition.y <= (y + h))){
      mHot = true;
    }
    else {
      mHot = false;
    }
  }
  
  if(released){
    if((mousePosition.x >= x && mousePosition.x <= (x + w)) && (mousePosition.y >= y && mousePosition.y <= (y + h))){
      if(mHot){
        mHot = false;
        return true;
      }
    }
  
  }
  return false;
}

void UIImageButton::Render(){
  if(!mTexture){
    return;
  }
  
  mColor = WHITE;
  if(mHovered){
    mColor = RED;
  }   
  DrawTexturePro(mTexture->texture, mTexture->source, {x,y,w,h}, {0,0}, 0, mColor);
}

  
MainMenuOverlay::MainMenuOverlay(Scene* scene)
:UIOverlay(scene){
  mStartButtonTexture = Assets::GetTexture("start_button");
  
  mStartButtonX = Settings::screenWidth / 2 - (mStartButtonTexture.texture.width * 4)/2;
  mStartButtonY = Settings::screenHeight / 2 ;
  
  mStartButton.SetTexture(&mStartButtonTexture);
  //mStartButton.SetBounds(mStartButtonX,mStartButtonY,48*2,8*2);
  mTime = 0;
}

/*bool MainMenuOverlay::ImageButton(TextureDetails* texture, float x, float y, float w, float h){
  Rectangle destination = {};
  destination.x = x;
  destination.y = y;
  destination.width = w;
  destination.height = h;
  
  DrawTexturePro(texture->texture, texture->source, destination, {0,0}, 0, WHITE);

  return result;
}*/
  
void MainMenuOverlay::Tick(float deltaTime){
  mTime += deltaTime;
  float offset = std::sin(mTime) * 16;
  mStartButton.SetBounds(mStartButtonX,mStartButtonY + offset,48*4,8*4);
  if(mStartButton.Clicked()){
    //std::cout << "Clicked" << std::endl;
    SceneManager::PushScene("game_scene");
  }
}

void MainMenuOverlay::Render(){
  mStartButton.Render();
}

MenuScene::MenuScene(){
  mMainMenuOverlay = new MainMenuOverlay(this);
  AddOverlay("main_menu_overlay", mMainMenuOverlay);
}

//void MenuScene::initialize(){}
