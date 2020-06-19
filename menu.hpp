#include "SDL.h"
#include<vector>
#include<string>
#include<iostream>
#pragma once


class Menu{     
    
    private:
    bool quit_= false;
    const int map_selection_box_width = 392-77;
    const int map_selection_box_height = 646 - 286;
    const int selection_box_w = 816 - 542;
    const int selection_box_h = 340 -257;
    const int player_selection_box_w = 567-293;
    const int player_selection_box_h =  612 - 273;
    SDL_Rect back_button_mover = {1192, 638, 2*210/3, 2*110/3};
    std::vector <std::vector <SDL_Texture*>> menu_sprites;
    std::vector <std::vector <std::vector < int >>> coordinates_screen;
    // std::vector <int> temp; 
    void draw();
    int current_screen;
    public:

    Menu();
    void refresh(SDL_Renderer * gRenderer, int x, int y, bool click); //checks which sprite to draw;
    void add_sprite(SDL_Texture*, int screen_number);
    bool quit_game();
    
    bool menuactive = true;
    ~Menu();
};