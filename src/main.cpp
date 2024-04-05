#include <raylib.h>

#include <Engine/map.hpp>
#include <Engine/block.hpp>
#include <Engine/player.hpp>

int main(void)
{

    int screenWidth = 1200;
    int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "Voxelcraft 2D");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    Camera2D camera = { 0 };
    
    camera.target = (Vector2){ screenWidth / 2.0f, screenHeight / 2.0f };
    camera.offset = (Vector2){ screenWidth / 2.0f, (screenHeight / 2.0f) + ((screenHeight/100)*15) };
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
        //Eğer ekran boyutu deişirse kamerayı güncelleme
        if(GetScreenWidth() != screenWidth || GetScreenHeight() != screenHeight){
            screenWidth = GetScreenWidth();
            screenHeight = GetScreenHeight();
            camera.offset = (Vector2){ screenWidth / 2.0f, (screenHeight / 2.0f) + ((screenHeight/100)*15) };

        }

        map.render();
        player.render(map.AllMap);

        BeginDrawing();
            
            ClearBackground((Color){135, 206, 250, 255});

            BeginMode2D(camera);

            map.draw((Vector2){player.rect.x,player.rect.y});
            
            player.draw();

        EndDrawing();
        
    }

    
    CloseWindow();

    return 0;
}