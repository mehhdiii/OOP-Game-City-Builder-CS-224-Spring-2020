#include "SDL.h"
#include "Animate.hpp"
#pragma once

class Bird: public Animate{

    private:

        SDL_Rect Image;
        float creation_time;
    public:

        Bird(SDL_Texture *);
        void setCoordinates(int , int );
        void set_creation_time(int);
};