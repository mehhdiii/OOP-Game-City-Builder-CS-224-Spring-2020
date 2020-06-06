#include "SDL.h"
#include "inAnimate.hpp"
#pragma once

class building: public InAnimate{
    protected:

        int structure_level;
        int height;
        int price;
    public:

        building(SDL_Texture *);
        void upgrade();

};