#include "SDL.h"
#include "building.hpp"
#include<string>
#include <vector>
#pragma once

class Bank: public Building{

    private:

        int peopleCount;
        int pricing;
        float creation_time;
        // std::vector <int> house_prices; //costs of all houses
    public:

        Bank(SDL_Texture * );
        // void setPeoplecount(int);
        // void setPrice(int);
        void set_creation_time(int);
};
