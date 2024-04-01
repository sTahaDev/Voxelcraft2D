#include <raylib.h>

#include <Engine/map.hpp>
#include <Engine/block.hpp>
#include <Engine/player.hpp>

int main(void)
{

    const int screenWidth = 1200;
    const int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "Voxelcraft 2D");

    Map map(screenWidth,screenHeight);
    map.setup();

    Player player({0,0,50,100});
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

            map.draw();
            
            player.draw();

        EndDrawing();
        
    }

    
    CloseWindow();

    return 0;
}