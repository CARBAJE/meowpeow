#include "enemy_spawner.hpp"
#include "enemy_alan.hpp"
#include "enemy_lips.hpp"
#include "enemy_bonbon.hpp"   

void EnemyFactory::Initialize() {
    mEnemyCreationMap["alan"] = [](Scene* s, v2 p) {return new EnemyAlan(s, p);};
    mEnemyCreationMap["lips"] = [](Scene* s, v2 p) {return new EnemyLips(s, p);};
    mEnemyCreationMap["bonbon"]=[](Scene* s, v2 p) {return new EnemyBonbon(s, p);};
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
        mPossibleEnemies.push_back("alan");
        mPossibleEnemies.push_back("lips");
        mPossibleEnemies.push_back("bonbon"); 
        mEnemyFactory.Initialize();
        mTime = 0;
    }

void EnemySpawner::Tick(float deltaTime) {
    mTime += deltaTime;
    if(mTime > 1){
        mTime = 0;
        SpawnEnemies();
    }
}
void EnemySpawner::SpawnEnemies(){
    int randomMobNameIndex = rand() % mPossibleEnemies.size();  
    int screenWidth = GetScreenWidth(); //int screenWidth = (64*8); 
    int randomX = rand() % screenWidth;
    //este codigo es malo pero hara el trabajo por ahora
    randomX = randomX==0 ? -64: randomX;

    v2 spawnPosition = {static_cast<float>((rand() % (screenWidth)) - 64), -64.0f};
    Enemy* enemy = mEnemyFactory.Create(mScene, spawnPosition, mPossibleEnemies[randomMobNameIndex]);
    mScene->Add(enemy);
}