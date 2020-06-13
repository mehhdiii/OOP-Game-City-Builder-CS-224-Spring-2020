#include "SDL.h"
#include "unit.hpp"
#pragma once

class InAnimate: public Unit{
    
    private:

        int width;
        int height;
        int price;
    public:

        InAnimate(SDL_Texture *);
        void draw(SDL_Renderer *);
};