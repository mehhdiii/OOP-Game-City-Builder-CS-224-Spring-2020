#include "SDL.h"
#include "inanimate.hpp"
#include<iostream>
#pragma once


class Park: public InAnimate{
    
    private:
        
        int env_impact;  
        float creation_time;       
    public:

        Park(SDL_Texture * );
        void update_scores(int &, int &);
        int showEnvImpact();   
        void set_creation_time(int);
};