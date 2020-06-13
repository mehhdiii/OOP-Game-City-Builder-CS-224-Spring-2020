#include "SDL.h"
#include<vector>
#include<string>
#include<iostream>
#pragma once


class Menu{     
    
    private:

    std::vector <std::vector <SDL_Texture*>> menu_sprites;
    std::vector <std::vector <std::vector < int >>> coordinates_screen;
    // std::vector <int> temp; 
    void draw();
    int current_screen;
    public:

    Menu();
    void refresh(SDL_Renderer * gRenderer, int x, int y, bool click); //checks which sprite to draw;
    void add_sprite(SDL_Texture*, int screen_number);
    ~Menu();
};