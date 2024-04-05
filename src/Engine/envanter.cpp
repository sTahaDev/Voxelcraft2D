#include "envanter.hpp"

void Envanter::setup()
{
    items.push_back(blockUrls.grass);
    items.push_back(blockUrls.dirt);
    items.push_back(blockUrls.cobblestone);
    items.push_back(blockUrls.wood);
    items.push_back(blockUrls.empty);
    items.push_back(blockUrls.empty);
    items.push_back(blockUrls.empty);
    items.push_back(blockUrls.empty);

    
    
}

void Envanter::render()
{

    //Current item i güncelleme
    for (int i = 0; i < maxItem; i++)
    {
        if (IsKeyPressed(i + 49))
        {
            
            if (items[i] != blockUrls.empty)
            {
        
                currentItem = items[i];
                selectedItemIndex = i;
                
            }
        }
    }
}