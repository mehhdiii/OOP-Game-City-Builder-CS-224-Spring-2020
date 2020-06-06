#include "SDL.h"
#include "Animate.hpp"
#pragma once

class bird: public Animate{
    private:

        SDL_Rect Image;
    public:

        bird(SDL_Texture *);
        void setCoordinates(int , int );

};