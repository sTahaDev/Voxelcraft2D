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
        std::string dirt = "../assets/dirt.png";
        std::string grass = "../assets/grass.png";
        std::string cobblestone = "../assets/rock.png";
        std::string wood = "../assets/wood.png";
    }blockUrls;
    
    std::string currentItem = blockUrls.dirt;

    void setup();
    void render();

private:


};