#include "SDL.h"
#include "animate.hpp"
#pragma once

class Worker: public Animate{
    
    private:

        SDL_Rect Image;
        int work_power;
        bool probation_period;
    public:

        Worker(SDL_Texture *);
        void set_work_power(int);
        void deploy();
        void show_all_features();
};