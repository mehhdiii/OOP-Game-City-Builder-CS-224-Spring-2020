#include "SDL.h"
#include "inanimate.hpp"
#pragma once


class Park: InAnimate{
    private:
        int structure_level;
        int env_impact; 
    public:
        Park(SDL_Texture * );
        void showEnvImpact();
        void showStructureLevel();

};