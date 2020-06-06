#include "SDL.h"
#include "InAnimate.hpp"
#include<string>
#pragma once

class House: public InAnimate{
    private:
        int peopleCount;
        int localityGrading;
        // string locality;
        int houseSize;
        int pricing;

    public:
        House(SDL_Texture * );
        int getLocalityGrading();
        void setPeoplecount(int);
        void setPrice(int);

        


};
