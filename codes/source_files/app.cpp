#include <raylib.h>

#include "../classes/scene.hpp"
#include "../classes/player.hpp"
#include "../classes/assets.hpp"

int main() {
    const int scale = 8;
    const int screenWidth = 64 * scale;
    const int screenHeight = 64 * scale;
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Player ship/Player_ship (16 x 16).png","player_left", 0, 0, 16, 16);
    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Player ship/Player_ship (16 x 16).png","player_neutral", 16, 0, 16, 16);
    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Player ship/Player_ship (16 x 16).png","player_right", 32, 0, 16, 16);
    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Space_BG (2 frames) (64 x 64).png","background_0", 0, 0, 64, 64);
    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Space_BG (2 frames) (64 x 64).png","background_1", 64, 0, 64, 64);
    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Projectiles/Player_beam (16 x 16).png","player_projectile");

    SetTargetFPS(60);

    Scene scene;

    scene.Add(new Player(&scene, {100, 100}));

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
