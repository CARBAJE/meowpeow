#ifndef ENEMY_SPAWNER_HPP   
#define ENEMY_SPAWNER_HPP

#include"game_object.hpp"
#include"enemy.hpp" 
#include<map>
#include<functional>
class EnemyFactory{
    private: 
        std::map<std::string, std::function<Enemy*(Scene*, v2)>> mEnemyCreationMap;
    public:
        void Initialize();
        Enemy* Create(Scene* scene,v2 position, const std::string& name); 
};
class EnemySpawner : public GameObject {
    private:
        EnemyFactory mEnemyFactory;
        float mTime;

        void SpawnEnemies(); 

    public:
        EnemySpawner(Scene* scene); 

        virtual void Tick(float deltaTime) override;
        
};

#endif //ENEMY_SPAWNER_HPP