#include "SDL.h"
#include "unit.hpp"
#include<string>
#include<iostream>
#pragma once

class Map: public Unit{

    private:

        int xmouse;
        int ymouse;
        float creation_time;
        std::string theme;
        const int MAP_WIDTH = 4964;
        const int MAP_HEIGHT = 2490;
        const int SCROLL_SPEED = 50;
    public:

        Map(SDL_Texture * );
        void draw(SDL_Renderer *);
        
        void set_creation_time(int);

        void scroll(bool, bool, bool, bool);
        bool scrolling_flag(bool, bool, bool, bool); // checks if scrolling is possible
};