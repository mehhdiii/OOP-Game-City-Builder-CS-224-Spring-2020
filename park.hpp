#include "SDL.h"
#include "building.hpp"
#pragma once


class Park: public Building{
    private:
        
        int env_impact; 
        
    public:
        Park(SDL_Texture * );
        int showEnvImpact();
        
        

};