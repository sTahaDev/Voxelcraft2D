#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <raylib.h>
#include <Engine/block.hpp>
#include <vector>

class Map{
public:

    Map(int windowWidth,int windowHeight,Camera2D& camera) : camera(camera){
        this->windowWidth = windowWidth;
        this->windowHeight = windowHeight;
    }

    std::vector<Block*> AllMap;
    void setup();
    void render();
    void draw();

    struct
    {
        std::string dirt = "../assets/dirt.png";
        std::string grass = "../assets/grass.png";
    }blockUrls;

    int blockSize = 50;
    int lineLength = 24;
    int dirtLineLenght = 4;
private:
    int windowWidth;
    int windowHeight;
    Vector2 mousePos;
    Vector2 calculateBlockPositon();
    Camera2D& camera;
    
    
    
};

#endif