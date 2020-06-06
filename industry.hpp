#include "SDL.h"
#include "unit.hpp"
#pragma once

class Industry{

    private:
        int pollution;
        int structureLevel;
        int totalEnergyConsumption;
        int greenEnergyDependence;
        int fossilFeulDependence;
    public:
        Industry(SDL_Texture * );
        void upgrade();


};