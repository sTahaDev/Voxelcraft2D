#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <iostream>
#include <raylib.h>
#include <Engine/gameobject.hpp>

class Block : GameObject
{
public:
    Block(std::string textureUrl, int x, int y, int width, int height) : GameObject(textureUrl)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }
    void setup();
    void render();
    void draw();
    Rectangle getRect();
    bool isClicked = false;

private:
    int x;
    int y;
    int width;
    int height;
    Vector2 mousePos;
    
    
};

#endif