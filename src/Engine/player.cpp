#include "player.hpp"

void Player::setup(){
    GameObject::setup();

    speedAmount = 10;
    jumpAmount = 20;
    velocity = 0;
    gravity = 1;
    maxVelocity = 30;
    colliderOptimisationBlockLimit = 180;
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
        
        if((blocks[i]->getRect().x <= rect.x && blocks[i]->getRect().x >= rect.x - colliderOptimisationBlockLimit) || (blocks[i]->getRect().x >= rect.x && blocks[i]->getRect().x <= rect.x + colliderOptimisationBlockLimit)){
            if((blocks[i]->getRect().y >= rect.y && blocks[i]->getRect().y <= rect.y + colliderOptimisationBlockLimit) || (blocks[i]->getRect().y <= rect.y && blocks[i]->getRect().y >= rect.y - colliderOptimisationBlockLimit)){
                Collider::addCollider(rect,blocks[i]->getRect());
                //blocks[i]->setColor(BLACK);
                
            }
        }
    }

    velocity += gravity;

    if(IsKeyPressed(KEY_SPACE) && !isJumping){
        velocity -= jumpAmount;
        isJumping = true;
    }

    //camera.target = (Vector2){ rect.x + rect.width / 2, rect.y + rect.height / 2 }; 
    float cameraSpeed = 2.0f; // Kamera hızını ayarlayın
    camera.target.x += (rect.x - camera.target.x) * cameraSpeed * GetFrameTime();
    camera.target.y += (rect.y - camera.target.y) * cameraSpeed * GetFrameTime();

}

void Player::draw(){
    GameObject::draw();
}
