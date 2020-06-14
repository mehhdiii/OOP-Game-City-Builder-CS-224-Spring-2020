#include "SDL.h"
#include "building.hpp"
#include<string>
#include <vector>
#pragma once

class House: public Building{

    private:

        int peopleCount;
        int localityGrading;
        int houseSize;
        int pricing;
        float creation_time;
        // std::vector <int> house_prices; //costs of all houses
    public:

        House(SDL_Texture * );
        int getLocalityGrading();
        void setPeoplecount(int);
        void setPrice(int);
        void set_creation_time(int);
};
