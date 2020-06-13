#include "SDL.h"
#include "inanimate.hpp"
#include <iostream>
#pragma once
using namespace std;

class SolarPanel: public InAnimate{

    private:

        int efficiency;
        int productionPeriod;
        int energyProduced;
        int lifeTime;
    public:
    
        SolarPanel(SDL_Texture *);
        void setEnergy(int);
        void show_all_features();
};

