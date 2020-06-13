#include "SDL.h"
#include "inanimate.hpp"
#pragma once

class Building: public InAnimate{
    
    protected:

        int structure_level;
        int height;
        int price;
        int upgrade_cost;
    public:

        Building(SDL_Texture *);
        int upgrade(int balance);
        int showStructureLevel();
};