#include "SDL.h"
#include "inanimate.hpp"
#pragma once

class Vehicle: public InAnimate{

    private:

        int pollution;
        int structureLevel;
        int upgrade_cost;
        float creation_time;
    public:

        Vehicle(SDL_Texture *);
        void upgrade(int current_balance);
        void set_creation_time(int);
};