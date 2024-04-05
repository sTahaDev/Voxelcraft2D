#pragma once

#include <raylib.h>
#include <iostream>
#include <Engine/gameobject.hpp>
#include <Engine/block.hpp>
#include <Engine/collider.hpp>


class Player : public GameObject{

public:
    Player(Rectangle rect,Camera2D& camera) : GameObject(rect),camera(camera){
        
    }

    void setup();
    void render(std::vector<Block*> blocks);
    void draw();
    
    
private:
    int speedAmount;
    int jumpAmount;
    bool isJumping;
    int velocity;
    int gravity;
    int maxVelocity;
    int colliderOptimisationBlockLimit;
    Camera2D &camera;

};