#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <iostream>
#include <Engine/collider.hpp>
#include <raylib.h>

class GameObject{

public:
    GameObject(std::string textureUrl){
        this->textureUrl = textureUrl;
        isHaveTexture = true;
    }
    GameObject(Rectangle rect){
        this->rect = rect;
        isHaveTexture = false;
    }

    virtual void setup();
    virtual void render();
    virtual void draw();

    Rectangle rect;
    Color color;

private:
    Texture2D texture;
    std::string textureUrl;
    bool isHaveTexture;

};

#endif