#pragma once
#include "../classes/scene.hpp"

class GameScene : public Scene{
public:
  GameScene();
  
  virtual void initialize() override;
  //virtual void Destroy() override;
};
