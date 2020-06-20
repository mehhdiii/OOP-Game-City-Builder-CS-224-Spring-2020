#include "SDL.h"
#include<vector>
#include<string>
#include<iostream>
#pragma once


class Menu{     
    
    private:
    bool quit_= 0; //if the user presses quit
    const int map_selection_box_width = 392-77; //map selection screen boxes 
    const int map_selection_box_height = 646 - 286;
    const int selection_box_w = 816 - 542; //main menu selection boxes
    const int selection_box_h = 340 -257;
    const int player_selection_box_w = 567-293; //player selection screen boxes
    const int player_selection_box_h =  612 - 273;
    const int mute_selection_box_w = 807 - 562 ;   //settings screen selection boxes
    const int mute_selection_box_h = 396- 323;
    bool bg_muted = 0; //mute flags
    bool sfx_muted = 0;
    SDL_Rect back_button_mover = {1192, 638, 2*210/3, 2*110/3}; //back button for settings sprite
    std::vector <std::vector <SDL_Texture*>> menu_sprites; //vector to store all menu sprites
    // std::vector <std::vector <std::vector < int >>> coordinates_screen;
    // std::vector <int> temp; 
    void draw(); //draws all sprites on screen
    int current_screen;
    public:

    Menu();
    void refresh(SDL_Renderer * gRenderer, int x, int y, bool click); //checks which sprites to draw and draws them on screen;
    void add_sprite(SDL_Texture*, int screen_number); //adds a sprite to the 2d vectors of sprites. 
    bool quit_game(); //checks if quit game was called 
    
    bool menuactive = true; //flag which maintains the menu state
    ~Menu();
};