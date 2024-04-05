#pragma once

#include <iostream>
#include <raylib.h>
#include <Engine/envanter.hpp>
#include <vector>

class UI{

public:
    
    UI(Envanter &envanter) : envanter(envanter){}
    

    void setup();
    void render();
    void draw();
    void updateScreen();

private:
    Envanter& envanter;
    Texture2D envanterBar;
    Vector2 envanterBarPos;
    int envanterBarLength;
    int envanterSize;
    int screenWidth;
    int screenHeight;

    std::vector<Texture2D> envanterBarItemsTextures;
    int envanterBarItemsSize;

    Texture2D selectedItemTexture;
};