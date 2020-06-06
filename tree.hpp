#include "SDL.h"
#include "inanimate.hpp"
#pragma once

class Tree: public inanimate{

    private:
        int oxygenGenerated;
        int type;
    public:
        Tree (SDL_Texture *);
        void showOxygenGen();
};

