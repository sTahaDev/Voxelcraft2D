#include "map.hpp"

void Map::setup()
{

    // Çimen Katmanı
    for (int i = 0; i < lineLength; i++)
    {
        AllMap.push_back(new Block(envanter.blockUrls.grass, i * blockSize, windowHeight - (blockSize * 2), blockSize, blockSize));
        AllMap.back()->setup();
    }
    // Toprak Katmanı
    for (int k = 0; k < dirtLineLenght; k++)
    {
        for (int i = 0; i < lineLength; i++)
        {
            AllMap.push_back(new Block(envanter.blockUrls.dirt, i * blockSize, windowHeight - (blockSize * (1-k)), blockSize, blockSize));
            AllMap.back()->setup();
        }
    }
}

void Map::render()
{

    // Block Ekleme Mape
    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        AllMap.push_back(new Block(envanter.currentItem, this->calculateBlockPositon().x, calculateBlockPositon().y, blockSize, blockSize));
        AllMap.back()->setup();
    }

    for (int i = 0; i < AllMap.size(); i++)
    {
        AllMap[i]->render();
        if (AllMap[i]->isClicked(camera))
        {
            delete AllMap[i];
            AllMap.erase(AllMap.begin() + i);
        }
    }
}

void Map::draw(Vector2 playerPos)
{
    for (int i = 0; i < AllMap.size(); i++)
    {   
        //Chunk sistemi. Sadece chunka dahil olanları çiz.
        if((AllMap[i]->getRect().x >= playerPos.x && AllMap[i]->getRect().x <= playerPos.x + (blockSize * chunk.x)) || (AllMap[i]->getRect().x <= playerPos.x && AllMap[i]->getRect().x >= playerPos.x - (blockSize * chunk.x))){
            if((AllMap[i]->getRect().y >= playerPos.y && AllMap[i]->getRect().y <= playerPos.y + (blockSize * chunk.y)) || (AllMap[i]->getRect().y <= playerPos.y && AllMap[i]->getRect().y >= playerPos.y - (blockSize * chunk.y))){
                AllMap[i]->draw();
            }
            
        }
        
    }
}

Vector2 Map::calculateBlockPositon()
{
    mousePos = GetMousePosition();
    
    // Fare pozisyonunu kamera pozisyonuna göre düzelt
    Vector2 correctedMousePos = {(mousePos.x - camera.offset.x) / camera.zoom + camera.target.x,
                                 (mousePos.y - camera.offset.y) / camera.zoom + camera.target.y};

    std::cout << correctedMousePos.y << std::endl;

    // Heseplama
    int x = ((int)correctedMousePos.x / blockSize) * blockSize;
    int y = ((int)correctedMousePos.y / blockSize) * blockSize;
    
    //Sıfırdam küçük iken olan bug ı düzelttim
    if(correctedMousePos.x < 0){
        x -= blockSize;
    }
    if(correctedMousePos.y < 0){
        y -= blockSize;
    }

    return {(float)x, (float)y};
}
