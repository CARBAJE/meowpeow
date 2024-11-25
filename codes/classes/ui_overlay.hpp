#pragma once 

#include "../classes/texture_details.hpp"

class Scene;

class UIOverlay{
protected:
  Scene* mScene;
public:
  UIOverlay(Scene* scene);

  virtual void Tick(float deltaTime);
  virtual void Render();
};

class HudOverlay : public UIOverlay{
private:
  TextureDetails mPlayerHealthTexture;
  bool mFading;
  Color mFadeColor;
  float mFadeAlpha;
public:
  HudOverlay(Scene* scene);
  
  void FadeScreen();
  
  virtual void Tick(float deltaTime) override;
  virtual void Render() override;
};
