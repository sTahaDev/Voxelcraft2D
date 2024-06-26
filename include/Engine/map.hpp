#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <raylib.h>
#include <Engine/block.hpp>
#include <vector>
#include <Engine/envanter.hpp>

class Map{
public:

    Map(int windowWidth,int windowHeight,Camera2D& camera,Envanter &envanter) : camera(camera),envanter(envanter){
        this->windowWidth = windowWidth;
        this->windowHeight = windowHeight;
        
    }

    std::vector<Block*> AllMap;
    void setup();
    void render();
    void draw(Vector2 playerPos);
    Envanter& envanter;
  

    int blockSize = 50;
    int lineLength = 300;
    int dirtLineLenght = 6;
    Vector2 chunk = {30,30};
private:
    int windowWidth;
    int windowHeight;
    Vector2 mousePos;
    Vector2 calculateBlockPositon();
    Camera2D& camera;
    
    
    
};

#endif