#include <raylib.h>

#include "../classes/scene.hpp"
#include "../classes/player.hpp"
#include "../classes/enemy.hpp"
#include "../classes/assets.hpp"
#include "../classes/enemy_alan.hpp"
#include "../classes/enemy_spawner.hpp"
#include "../classes/enemy_lips.hpp"
#include "../classes/enemy_bonbon.hpp"

int main() {
    const int scale = 8;
    const int screenWidth = 64 * scale;
    const int screenHeight = 64 * scale;
    
    InitWindow(screenWidth, screenHeight, "MeowPeow");

    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Player ship/Player_ship (16 x 16).png","player_left", 0, 0, 16, 16);
    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Player ship/Player_ship (16 x 16).png","player_neutral", 16, 0, 16, 16);
    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Player ship/Player_ship (16 x 16).png","player_right", 32, 0, 16, 16);
    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Space_BG (2 frames) (64 x 64).png","background_0", 0, 0, 64, 64);
    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Space_BG (2 frames) (64 x 64).png","background_1", 64, 0, 64, 64);
    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Projectiles/Player_beam (16 x 16).png","player_projectile");
    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Enemies/Alan (16 x 16).png", "enemy_simple", 0, 0, 16, 16);
    
    Assets::LoadAssetAnimation("../textures/Mini Pixel Pack 3/Enemies/Alan (16 x 16).png", "alan_idle", 6,0.1f, 16,16); 
    Assets::LoadAssetAnimation("../textures/Mini Pixel Pack 3/Enemies/Lips (16 x 16).png", "lips_idle", 5, 0.1f, 16, 16);
    Assets::LoadAssetAnimation("../textures/Mini Pixel Pack 3/Enemies/Bon_Bon (16 x 16).png", "bonbon_idle", 4, 0.1f, 16, 16);
    Assets::LoadAssetAnimation("../textures/Mini Pixel Pack 3/Projectiles/Enemy_projectile (16 x 16).png", "enemy_projectile_animation", 4, 0.1f, 16, 16);
    Assets::LoadAssetAnimation("../textures/Mini Pixel Pack 3/Effects/Explosion (16 x 16).png", "explosion_animation", 5,0.1f, 16,16);
    
    Assets::LoadAssetAnimation("../textures/Mini Pixel Pack 3/Player ship/Boosters (16 x 16).png","boosters_animation", 2, 0.1f, 16, 16);
    Assets::LoadAssetAnimation("../textures/Mini Pixel Pack 3/Player ship/Boosters_left (16 x 16).png","boosters_left_animation", 2, 0.1f, 16, 16);
    Assets::LoadAssetAnimation("../textures/Mini Pixel Pack 3/Player ship/Boosters_right (16 x 16).png","boosters_right_animation", 2, 0.1f, 16, 16);

    //Enemy_projectile (16 x 16).png <- nombre de la textura
    SetTargetFPS(60);

    Scene scene;
    scene.SetSceneBounds({-0, -0}, {screenWidth+0, screenHeight+0}); //probando el tamano XD por eos tiene -0

    Player * player = new Player(&scene, {100, 100});
    scene.SetPlayer(player);
    scene.Add(player);

    //scene.Add(new Player(&scene, {100, 100}));
    //scene.Add(new EnemyAlan(&scene, {screenWidth/4, 100}));

    scene.Add(new EnemySpawner(&scene)); //apgado para probar otro enemigo manual
    //scene.Add(new EnemyBonbon(&scene, {100, 100})); 
    //scene.Add(new EnemyLips(&scene, {screenWidth/4, 100})); //PRUEBa

    TextureDetails backgroundAnimation[2] = {Assets::GetTexture("background_0"), Assets::GetTexture("background_1"),};

    int currentFrame = 0;
    float backgroundTime = 0;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        backgroundTime += deltaTime;

        if(backgroundTime > 0.1){
            backgroundTime = 0;
            ++currentFrame;
            currentFrame %= 2;
        }
        scene.Tick(deltaTime);

        BeginDrawing();
        ClearBackground(BLACK);

        DrawTexturePro(backgroundAnimation[currentFrame].texture, backgroundAnimation[currentFrame].source, {0, 0, screenWidth, screenHeight}, {0, 0}, 0, WHITE);

        scene.Render();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
