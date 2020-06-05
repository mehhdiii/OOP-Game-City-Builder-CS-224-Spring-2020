#include "SDL.h"
#pragma once

class Vehicle{
    private:
        int pollution;
        int structureLevel;
        int upgrade_cost;
    public:
        Vehicle(SDL_Texture *);
        void upgrade(int current_balance);

};