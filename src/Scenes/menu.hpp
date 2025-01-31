#pragma once

#include <raylib.h>
#include <Engine/scenemanager.hpp>

class Menu : public Scene
{
public:
    int screenWidth = 1200;
    int screenHeight = 800;

    Menu()
    {
        id = 1;
        setup();
    }

    void setup()
    {
        

        
    }

    void update()
    {
        DrawText("Burasi Menu",450,250,45,GRAY);
        if(IsKeyDown(KEY_A)){
            SceneManager::run(0);
        }

    }

    void render()
    {

    }
};
