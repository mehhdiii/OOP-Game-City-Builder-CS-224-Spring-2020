#include "SDL.h"
#include "Animate.hpp"
#pragma once

class scientist: public Animate{
    private:

        SDL_Rect Image;
        int intelligence;
        bool work_Power;
    public:

        scientist(SDL_Texture *);
        int getworkPower();

};