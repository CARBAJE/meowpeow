#include "../classes/game_scene.hpp"
#include "../classes/ui_overlay.hpp"
#include "../classes/player.hpp"
#include "../classes/enemy_spawner.hpp"
#include "../classes/settings.hpp"

GameScene::GameScene(){
} 

void GameScene::initialize(){
    Scene::initialize();

    SetSceneBounds({-0, -0}, {(float)Settings::screenWidth+0, (float)Settings::screenHeight+0}); //probando el tamano XD por eos tiene -0

    Player * player = new Player(this, {100, 100});
    Add(player);

    Add(new EnemySpawner(this)); //apgado para probar otro enemigo manual
    AddOverlay("hud",new HudOverlay(this));
}
