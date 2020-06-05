#include "SDL.h"
#include "unit.hpp"
#include<string>
#pragma once

class Map{
    private:

        int xmouse;
        int ymouse;
        string theme;
    public:
        Map(SDL_Texture * );
        void draw(SDL_Renderer *);
        void scroll(int, int);
    

}