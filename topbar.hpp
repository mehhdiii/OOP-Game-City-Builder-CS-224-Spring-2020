#include "SDL.h"
#include "unit.hpp"
#include<string>
#include<iostream>
#include<vector>
#include"draw_text.hpp"
#pragma once

class Topbar: public Unit{
    private:
        int number_of_bars=4;
        int transition_in_stat_sprite =5;
        std::vector<std::vector<SDL_Texture*>> stats_sprite;
        SDL_Rect cash_mover;
        SDL_Rect greenenergy_mover;
        SDL_Rect xplevel_mover;
        SDL_Rect oxygenlevel_mover;
        const int SPRITE_W = 103;
        const int SPRITE_H = 32;

        //text rendering objects
        std::vector<Draw_text*> text_objects; 
        // SDL_Rect cash_mover; //size of the object to draw on screen
        void setRect(); //cropping out the sprite from the sheet
    public:

    Topbar(SDL_Texture*);
    ~Topbar();
    void draw(SDL_Renderer*);
    void draw_modified(SDL_Renderer*, int &, int &, int &, int &);
    void update_bars(int , int, int, int);
    void add_static_sprite(SDL_Texture*, int sprite_color);

};