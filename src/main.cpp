#include <raylib.h>

#include <Engine/map.hpp>
#include <Engine/block.hpp>
#include <Engine/player.hpp>
#include <Engine/envanter.hpp>
#include <Engine/ui.hpp>
#include <Engine/scenemanager.hpp>

#include <Scenes/gamescene.hpp>
#include <Scenes/menu.hpp>

int main(void)
{

    int screenWidth = 1200;
    int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Voxelcraft 2D");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    Menu menuscene;
    SceneManager::setup(menuscene);

    //Scenes
    GameScene gamescene;
    SceneManager::addScene(gamescene);
    

    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {

        SceneManager::update();

        BeginDrawing();

        ClearBackground((Color){135, 206, 250, 255});

        SceneManager::render();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}