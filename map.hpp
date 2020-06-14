#include "SDL.h"
#include "unit.hpp"
#include<string>
#pragma once

class Map: public Unit{

    private:

        int xmouse;
        int ymouse;
        float creation_time;
        std::string theme;
    public:

        Map(SDL_Texture * );
        void draw(SDL_Renderer *);
        void scroll(int, int);
        void set_creation_time(int);
};