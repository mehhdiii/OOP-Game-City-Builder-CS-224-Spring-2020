#include "SDL.h"
#include "Animate.hpp"
#pragma once

class Scientist: public Animate{
    private:

        SDL_Rect Image;
        int intelligence;
        bool work_Power;
    public:

        Scientist(SDL_Texture *);
        int getworkPower();

};