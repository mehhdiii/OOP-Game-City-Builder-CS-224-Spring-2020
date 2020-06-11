#include "SDL.h"
#include "inanimate.hpp"
#pragma once

class SolarPanel: public inanimate{

    private:
        int efficiency;
        int productionPeriod;
        int energyProduced;
        
    public:
        SolarPanel(SDL_Texture *);
        int setEnergy();
};

