#include "SDL.h"
#include"inAnimate.hpp"
#include<string>
#include <vector>
#pragma once

class Turbine: public InAnimate{

    private:

        int pricing;
        float creation_time;
        // std::vector <int> house_prices; //costs of all houses
    public:

        Turbine(SDL_Texture * );
        // void setPeoplecount(int);
        // void setPrice(int);
        void set_creation_time(int);
};
