#include "SDL.h"
#include "unit.hpp"
#include<string>
#include<iostream>
#include<vector>
#pragma once

class Topbar: public Unit{
    private:
        SDL_Texture* stats_sprites;
    public:

    Topbar(SDL_Texture*);

    void draw(SDL_Renderer*);
    void update_bars(int , int, int, int);
    void add_static_sprite(SDL_Texture*);


};