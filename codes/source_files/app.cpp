#include <raylib.h>

#include "../classes/scene.hpp"
#include "../classes/player.hpp"
#include "../classes/assets.hpp"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Player ship/Player_ship (16 x 16).png","player_left", 0, 0, 16, 16);
    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Player ship/Player_ship (16 x 16).png","player_neutral", 16, 0, 16, 16);
    Assets::LoadAssetTexture("../textures/Mini Pixel Pack 3/Player ship/Player_ship (16 x 16).png","player_right", 32, 0, 16, 16);

    SetTargetFPS(60);

    Scene scene;

    scene.Add(new Player(&scene, {100, 100}));

    while (!WindowShouldClose()) {
        scene.Tick(0);

        BeginDrawing();
        ClearBackground(BLACK);

        scene.Render();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
