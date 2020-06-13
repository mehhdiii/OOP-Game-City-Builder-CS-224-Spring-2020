#include "SDL.h"
#include "inanimate.hpp"
#pragma once


class Park: public InAnimate{
    
    private:
        
        int env_impact;         
    public:

        Park(SDL_Texture * );
        int showEnvImpact();   
};