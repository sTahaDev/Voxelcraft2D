#include "block.hpp"


void Block::setup(){
    rect = {(float)x,(float)y,(float)width,(float)height};
    GameObject::setup();

}

void Block::render(){
    GameObject::render();

    //Mouse gelince karartma
    mousePos = GetMousePosition();
    if(CheckCollisionRecs(rect,{mousePos.x,mousePos.y,0.1f,0.1f})){
        //Mouse ye tıklandı mı
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            isClicked = true;
        }
        color = GRAY;
    }else{
        color = WHITE;
        isClicked = false;
    }
}

void Block::draw(){
    GameObject::draw();
}

Rectangle Block::getRect(){
    return this->rect;
}

