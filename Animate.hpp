#include "SDL.h"
#include "unit.hpp"
#pragma once

class Animate: public Unit{
    private:
        int speed;

    public:
        Animate(SDL_Texture * asset);

        void setSpeed();

        void mover();
};