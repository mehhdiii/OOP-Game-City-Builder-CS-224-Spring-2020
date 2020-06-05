#include "SDL.h"
#include "unit.hpp"
#pragma once

class Map{
    private:

        int xmouse;
        int ymouse;
    public:
        Map(SDL_Texture * );
        void draw(SDL_Renderer *);
        void scroll(int, int);
    

}