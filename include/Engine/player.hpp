#pragma once

#include <raylib.h>
#include <iostream>
#include <Engine/gameobject.hpp>
#include <Engine/block.hpp>
#include <Engine/collider.hpp>


class Player : public GameObject{

public:
    Player(Rectangle rect) : GameObject(rect){}

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


};