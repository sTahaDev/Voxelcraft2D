#pragma once

#include <Engine/map.hpp>
#include <Engine/block.hpp>
#include <Engine/player.hpp>
#include <Engine/envanter.hpp>
#include <Engine/ui.hpp>
#include <Engine/scenemanager.hpp>

class GameScene : public Scene
{
public:
    
    Camera2D camera = {0};

    Envanter envanter;
    UI ui;
    Map map;
    Player player;

    GameScene()
        : ui(envanter),
          map(GetScreenWidth(), GetScreenHeight(), camera, envanter),
          player({0, 0, 50, 100}, camera)
    {
        id = 0;
        setup();
    }

    void setup()
    {
        

        camera.target = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
        camera.offset = (Vector2){GetScreenWidth() / 2.0f, (GetScreenHeight() / 2.0f) + ((GetScreenHeight() / 100) * 15)};
        camera.rotation = 0.0f;
        camera.zoom = 1.0f;

        envanter.setup();
        ui.setup();
        map.setup();
        player.setup();
        player.color = RED;
    }

    void update()
    {
        // Eğer ekran boyutu deişirse kamerayı güncelleme
        //Şuanlık çalışmaz bunu düzelt
        if (GetScreenWidth() != GetScreenWidth() || GetScreenHeight() != GetScreenHeight())
        {
            int screenWidth = GetScreenWidth();
            int screenHeight = GetScreenHeight();
            camera.offset = (Vector2){screenWidth / 2.0f, (screenHeight / 2.0f) + ((screenHeight / 100) * 15)};

            // Ui'i düzenle
            ui.updateScreen();
        }

        envanter.render();
        map.render();
        player.render(map.AllMap);
        ui.render();
    }

    void render()
    {
        BeginMode2D(camera);

        map.draw((Vector2){player.rect.x, player.rect.y});

        player.draw();
        EndMode2D();
        ui.draw();
    }
};
