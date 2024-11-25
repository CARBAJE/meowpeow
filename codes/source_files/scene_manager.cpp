#include "../classes/scene_manager.hpp"

Scene* SceneManager::mCurrentScene = nullptr;
//Scene* SceneManager::mPreviousScene = nullptr;

std::map<std::string, Scene*> SceneManager::mSceneMap;
std::vector<Scene*> SceneManager::mSceneStack;

void SceneManager::AddScene(const std::string& name, Scene* scene){
  mSceneMap[name] = scene;
}

void SceneManager::PushScene(const std::string& name){
  //currentScene->
  mSceneStack.push_back(mSceneMap[name]);
  mSceneStack.back()->initialize();
}

void SceneManager::ForcePopBack(){
  mSceneStack.pop_back();
}

void SceneManager::PopScene(){
  if(mSceneStack.empty()){
    return ;
  }
  mSceneStack.back()->ScheduleDestroy();
  //mSceneStack.pop_back();
}

Scene* SceneManager::GetCurrentScene(){
  if(mSceneStack.empty()){
    return nullptr;
  }
  return mSceneStack.back();
}

