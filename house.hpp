#include "SDL.h"
#include "unit.hpp"
#include<string>
#pragma once

class House{
    private:
        int peopleCount;
        int localityGrading;
        string locality;
        int houseSize;
        int pricing;

    public:
        House(SDL_Texture * );
        int getLocalityGrading();


};
