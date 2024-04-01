#include "player.hpp"

void Player::setup(){
    GameObject::setup();

    speedAmount = 10;
    jumpAmount = 20;
    velocity = 0;
    gravity = 1;
    maxVelocity = 30;

}

void Player::render(std::vector<Block*> blocks ){
    GameObject::render();

    rect.y += velocity;

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        rect.x += speedAmount;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        rect.x -= speedAmount;

    if(velocity > maxVelocity){
        velocity = maxVelocity;
    }

    for (int i = 0; i < blocks.size(); i++)
    {
        if(CheckCollisionRecs(rect,blocks[i]->getRect())){
            velocity = 0;
            isJumping = false;
            
        }
        

        Collider::addCollider(rect,blocks[i]->getRect());

        
    }

    
    
    velocity += gravity;

    if(IsKeyPressed(KEY_SPACE) && !isJumping){
        velocity -= jumpAmount;
        isJumping = true;
    }

    

    
    
}

void Player::draw(){
    GameObject::draw();

}