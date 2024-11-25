#pragma once

#include "../classes/scene.hpp"
#include "../classes/ui_overlay.hpp"

class UIImageButton{
private:
  bool mHot;
  bool mHovered;
  TextureDetails* mTexture;
  Color mColor;
public:  
  float x;
  float y;
  float h;
  float w;
  UIImageButton();
  void SetTexture(TextureDetails* texture);
  void SetBounds(float ax,float ay,float ah,float aw);
  
  bool Clicked();
  void Render();
};

class MainMenuOverlay : public UIOverlay {
private:
  float mStartButtonX;
  float mStartButtonY;
  float mTime;
  
  TextureDetails mStartButtonTexture;
  UIImageButton mStartButton;
public: 
  MainMenuOverlay(Scene* scene);
  
  //bool ImageButton(TextureDetails* texture, float x, float y, float w, float h);
  
  void Tick(float deltaTime) override;
  void Render() override;
};

class MenuScene : public Scene{
private:
  MainMenuOverlay* mMainMenuOverlay;
public:
  //GameScene();
  MenuScene();
  //virtual void initialize() override;
};
