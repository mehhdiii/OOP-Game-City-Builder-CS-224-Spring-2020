#include "SDL.h"
#include "Animate.hpp"
#pragma once

class Bird: public Animate{
    private:

        SDL_Rect Image;
    public:

        Bird(SDL_Texture *);
        void setCoordinates(int , int );

};