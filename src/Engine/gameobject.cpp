#include "gameobject.hpp"


void GameObject::setup()
{
    if (isHaveTexture)
    {
        texture = LoadTexture(textureUrl.c_str());
        texture.width = rect.width;
        texture.height = rect.height;
    }
    color = WHITE;
}

void GameObject::render()
{
}

void GameObject::draw()
{

    if(isHaveTexture){
        DrawTexture(texture, rect.x, rect.y, color);
    }else{
        DrawRectangle(rect.x,rect.y,rect.width,rect.height,color);
    }
}
