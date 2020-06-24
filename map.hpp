#include "SDL.h"
#include "unit.hpp"
#include<string>
#include<iostream>
#include<vector>
#include<cmath>
#pragma once

class Map: public Unit{

    private:
        int xmouse;
        int ymouse;
        float creation_time;
        std::string theme;
        const int MAP_WIDTH = 4964;
        const int MAP_HEIGHT = 2490;
        std::vector<int> grid_x; 
        std::vector<int> grid_y;
        int GRID_WIDTH =2998 -  2498;
        int GRID_HEIGHT = 626 - 375;
        const int SCROLL_SPEED = 50;
    public:

        Map(SDL_Texture * );
        void draw(SDL_Renderer *);
        
        void set_creation_time(int);

        void scroll(bool, bool, bool, bool);
        bool scrolling_flag(bool, bool, bool, bool); // checks if scrolling is possible

        void add_grid_point(); //add the grid point into the map array
        void check_grid(int&, int&);
};