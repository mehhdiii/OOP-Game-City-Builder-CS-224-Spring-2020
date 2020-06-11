#include "SDL.h"
#include "Animate.hpp"
#pragma once

class Worker: public Animate{
    private:

        SDL_Rect Image;
        int work_Power;
        bool probation_period;
    public:

        Worker(SDL_Texture *);
        void deploy();

};