#pragma once
#include <string>
#include <map>
#include <vector>

#include "../classes/scene.hpp"

class SceneManager{
private:
  static Scene* mCurrentScene;
  //static Scene* mPreviousScene;
  
  static std::vector<Scene*> mSceneStack;
  static std::map<std::string, Scene*> mSceneMap;
  
public:
  static void AddScene(const std::string& name, Scene* scene);
  static void PushScene(const std::string& name);
  static void PopScene();
  static void ForcePopBack();
  
  static Scene* GetCurrentScene();
};
