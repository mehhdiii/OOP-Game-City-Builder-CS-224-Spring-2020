#include "SDL.h"
#include "unit.hpp"

#pragma once

class InAnimate: public Unit{
    
    private:

        int width;
        int height;
        int price;
    protected:
        int OBJECT_WIDHT = 3*80;
        int OBJECT_HEIGHT =  3* 0.5625*80;
    public:
        
        InAnimate(SDL_Texture *);
        void draw(SDL_Renderer *);
};