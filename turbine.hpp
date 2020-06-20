#include "SDL.h"
#include"inAnimate.hpp"
#include<string>
#include <iostream>
#include <vector>
#pragma once

class Turbine: public InAnimate{

    private:

        int pricing;
        float creation_time;
        int subjective_green_energy = 15;
        // std::vector <int> house_prices; //costs of all houses
    public:

        Turbine(SDL_Texture * );
        void update_scores(int &, int &);
        int get_green_energy();
        // void setPeoplecount(int);
        // void setPrice(int);
        void set_creation_time(int);
};
