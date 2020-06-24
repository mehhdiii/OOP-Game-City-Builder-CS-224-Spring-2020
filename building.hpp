#include "SDL.h"
#include "inanimate.hpp"
#include<iostream>
#pragma once

class Building: public InAnimate{
    
    protected:

        int structure_level;
        int height;
        int price;
        int upgrade_cost = 100;
        float creation_time;
        float progress;

    public:

        Building(SDL_Texture *);
        void update_scores(int &, int &);
        int upgrade_building(int & );
        int showStructureLevel();
        void set_creation_time(int);
        void show_progress();
        ~Building();

};