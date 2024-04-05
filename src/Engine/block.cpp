#include "block.hpp"

void Block::setup()
{
    rect = {(float)x, (float)y, (float)width, (float)height};
    GameObject::setup();
}

void Block::render()
{
    GameObject::render();

    // Mouse gelince karartma
    mousePos = GetMousePosition();
    
}

void Block::draw()
{
    GameObject::draw();
}

Rectangle Block::getRect()
{
    return this->rect;
}

void Block::setColor(Color color)
{
    this->color = color;
}

bool Block::isClicked(Camera2D& camera)
{
    // Mouse gelince karartma
    mousePos = GetMousePosition();
    if (CheckCollisionRecs(rect, {mousePos.x + (camera.target.x - camera.offset.x), mousePos.y + (camera.target.y - camera.offset.y), 0.1f, 0.1f}))
    {
        // Mouse ye tıklandı mı
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            return true;
        }
        color = GRAY;
    }
    else
    {
        color = WHITE;
        return false;
    }

    return false;
}