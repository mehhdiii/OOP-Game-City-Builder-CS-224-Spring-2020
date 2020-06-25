#include "SDL.h"
#include "animate.hpp"
#include <iostream>
#pragma once

class Worker: public Animate{
    
    private:

        SDL_Rect Image;
        int work_power;
        bool probation_period;
        float creation_time;
    public:

        Worker(SDL_Texture *); 
        void update_scores(int &, int &); //updates scores of the worker
        void set_work_power(int); //sets the work power of the worker
        void deploy(); //deploys the worker for work
        void show_all_features(); //shows all features of the worker
        void set_creation_time(int); //sets the creation time of the worker
        ~Worker();
        
};