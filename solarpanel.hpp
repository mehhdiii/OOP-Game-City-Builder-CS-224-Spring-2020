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
        float creation_time;
    public:
    
        SolarPanel(SDL_Texture *);
        void setEnergy(int);
        void show_all_features();
        void set_creation_time(int);
};

