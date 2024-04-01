#include "map.hpp"

void Map::setup(){
    
    //Çimen Katmanı
    for (int i = 0; i < lineLength; i++)
    {
        AllMap.push_back(new Block(blockUrls.grass,i*blockSize,windowHeight-(blockSize*2),blockSize,blockSize));
        AllMap.back()->setup();
    }
    //Toprak Katmanı
    for (int i = 0; i < lineLength; i++)
    {
        AllMap.push_back(new Block(blockUrls.dirt,i*blockSize,windowHeight-(blockSize*1),blockSize,blockSize));
        AllMap.back()->setup();
    }
    
}

void Map::render(){

    //Block Ekleme Mape
    if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)){
        AllMap.push_back(new Block(blockUrls.dirt,this->calculateBlockPositon().x,calculateBlockPositon().y,blockSize,blockSize));
        AllMap.back()->setup();
    }

    for (int i = 0; i < AllMap.size(); i++)
    {
        AllMap[i]->render();
        if(AllMap[i]->isClicked){
            delete AllMap[i];
            AllMap.erase(AllMap.begin()+i);
        }
    }   
    
}

void Map::draw(){
    for (int i = 0; i < AllMap.size(); i++)
    {
        AllMap[i]->draw();
    }
}

Vector2 Map::calculateBlockPositon()
{
    mousePos = GetMousePosition();
    int x = (int)(mousePos.x / blockSize);
    x = x * blockSize;
    int y = (int)(mousePos.y / blockSize);
    y = y * blockSize;

    return {(float)x,(float)y};
}
