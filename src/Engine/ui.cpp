#include "ui.hpp"

void UI::setup(){

    screenHeight = GetScreenHeight();
    screenWidth = GetScreenWidth();

    envanterBar = LoadTexture("../assets/ui/envanterbar.png");
    envanterSize = 70;
    envanterBar.width = envanterSize;
    envanterBar.height = envanterSize;
    envanterBarLength = 8;
    envanterBarPos.x = (screenWidth/2)-(envanterSize*envanterBarLength)/2;
    envanterBarPos.y = (screenHeight - 100);

    envanterBarItemsSize = envanterSize-16;

    

    for (int i = 0; i < envanterBarLength; i++)
    {
        envanterBarItemsTextures.push_back(Texture());
        if(envanter.items[i] != ""){
            envanterBarItemsTextures[i] = LoadTexture(envanter.items[i].c_str());
            envanterBarItemsTextures[i].width = envanterBarItemsSize;
            envanterBarItemsTextures[i].height = envanterBarItemsSize;
        }
    }
    
    selectedItemTexture = LoadTexture("../assets/ui/selecteditem.png");

    selectedItemTexture.width = envanterSize;
    selectedItemTexture.height = envanterSize;
    
}

void UI::render(){
    
}

void UI::draw(){
    for (int i = 0; i < envanterBarLength; i++)
    {
        DrawTexture(envanterBar,envanterBarPos.x + (envanterBar.width * i),envanterBarPos.y,WHITE);
        if(envanter.items[i] != ""){
            DrawTexture(envanterBarItemsTextures[i],(envanterBarPos.x + (envanterBar.width * i)) + envanterSize/2 - envanterBarItemsSize/2,envanterBarPos.y + envanterSize/2 - envanterBarItemsSize/2,WHITE);
            if(envanter.selectedItemIndex == i){
                DrawTexture(selectedItemTexture,envanterBarPos.x + (envanterBar.width * i),envanterBarPos.y,WHITE);
            }
        }
    }

    
    
}

void UI::updateScreen(){
    screenHeight = GetScreenHeight();
    screenWidth = GetScreenWidth();

    envanterBarPos.x = (screenWidth/2)-(envanterSize*envanterBarLength)/2;
    envanterBarPos.y = (screenHeight - 100);

}