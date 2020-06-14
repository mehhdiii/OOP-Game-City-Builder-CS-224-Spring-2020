#include "SDL.h"
#include "unit.hpp"
#include<string>
#pragma once

class Animate: public Unit{
    
    private:

        int speed;
    public:
  
        Animate(SDL_Texture *);
        void draw(SDL_Renderer *);
        void setSpeed();
        void movement();
};