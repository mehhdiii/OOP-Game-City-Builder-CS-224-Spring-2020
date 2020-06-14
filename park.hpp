#include "SDL.h"
#include "inanimate.hpp"
#pragma once


class Park: public InAnimate{
    
    private:
        
        int env_impact;  
        float creation_time;       
    public:

        Park(SDL_Texture * );
        int showEnvImpact();   
        void set_creation_time(int);
};