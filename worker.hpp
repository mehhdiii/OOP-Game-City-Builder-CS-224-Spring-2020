#include "SDL.h"
#include "Animate.hpp"
#pragma once

class worker: public Animate{
    private:

        SDL_Rect Image;
        int work_Power;
        bool probation_period;
    public:

        worker(SDL_Texture *);
        void deploy();

};