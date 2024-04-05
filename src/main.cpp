#include <raylib.h>

#include <Engine/map.hpp>
#include <Engine/block.hpp>
#include <Engine/player.hpp>

int main(void)
{

    const int screenWidth = 1200;
    const int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "Voxelcraft 2D");

    Camera2D camera = { 0 };
    int cameraYOffset = 100;
    camera.target = (Vector2){ screenWidth / 2.0f, screenHeight / 2.0f };
    camera.offset = (Vector2){ screenWidth / 2.0f, (screenHeight / 2.0f)+cameraYOffset };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    Map map(screenWidth,screenHeight,camera);
    map.setup();

    Player player({0,0,50,100},camera);
    player.setup();
    player.color = RED;

    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(60);               
    while (!WindowShouldClose())    
    {

        map.render();
        player.render(map.AllMap);

        BeginDrawing();
            
            ClearBackground(RAYWHITE);

            BeginMode2D(camera);

            map.draw();
            
            player.draw();

        EndDrawing();
        
    }

    
    CloseWindow();

    return 0;
}