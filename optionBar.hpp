#include "SDL.h"
#include "unit.hpp"
#include<string>
#pragma once

class OptionBar: public Unit{
    
    private:

        int options;
    public:

        OptionBar(SDL_Texture * );
        // int getLocalityGrading();
        // void setPeoplecount(int);
        // void setPrice(int);
};
