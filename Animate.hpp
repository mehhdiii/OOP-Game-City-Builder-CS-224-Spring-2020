#include "SDL.h"
#include "unit.hpp"
#include<string>
#pragma once

class Animate: public Unit{
    
    private:

        int speed;
    protected:    
        int OBJECT_WIDHT = 3*80;
        int OBJECT_HEIGHT =  3* 0.5625*80;
    public:
  
        Animate(SDL_Texture *);
        void draw(SDL_Renderer *);
        void setSpeed();
        void movement();
};