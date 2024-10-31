#include "enemy_spawner.hpp"
#include "enemy_alan.hpp"

void EnemyFactory::Initialize() {
    mEnemyCreationMap["alan"] = [](Scene* s, v2 p) {return new EnemyAlan(s, p);};
    //more enemies
    //mEnemyCreationMap["enemy#"] = [](Scene* s, v2 p) {return new Enemy2(s, p);};
}


Enemy* EnemyFactory::Create(Scene* scene,v2 position, const std::string& name) {
    if(mEnemyCreationMap.find(name) != mEnemyCreationMap.end()){
        return mEnemyCreationMap[name](scene, position); 
    }else {
        return nullptr;
    }
}
EnemySpawner::EnemySpawner(Scene* scene)
    : GameObject(scene, {}){
        mEnemyFactory.Initialize();
    }

void EnemySpawner::Tick(float deltaTime) {
    mTime += deltaTime;
    if(mTime > 1){
        mTime = 0;
        SpawnEnemies();
    }
}
void EnemySpawner::SpawnEnemies(){
    int screenWidth = GetScreenWidth(); //int screenWidth = (64*8); 
    int randomX = rand() % screenWidth;
    //este codigo es malo pero hara el trabajo por ahora
    randomX = randomX==0 ? -64: randomX;

    v2 spawnPosition = {static_cast<float>((rand() % (screenWidth)) - 64), -64.0f};
    Enemy* enemy = mEnemyFactory.Create(mScene, spawnPosition, "alan");
    mScene->Add(enemy);
}