#pragma once

#include <iostream>
#include <string>
#include <raylib.h>

class Envanter{

public:

    const int maxItem = 8;
    std::vector<std::string> items;
   
    

    struct
    {
        std::string empty = "";
        std::string dirt = "../assets/blocks/dirt.png";
        std::string grass = "../assets/blocks/grass.png";
        std::string cobblestone = "../assets/blocks/rock.png";
        std::string wood = "../assets/blocks/wood.png";
    }blockUrls;
    
    std::string currentItem = blockUrls.dirt;
    int selectedItemIndex = 0;

    void setup();
    void render();

private:


};