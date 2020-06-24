#include "SDL.h"
#include<vector>
#include<string>
#include<iostream>
#include"sound.hpp"
#pragma once


class Menu{     
    //0->main menu
    // 1 -> map selection
    // 2 -> player selection
    // 3 -> credits
    // 4-> settings
    
    private:
    bool quit_= 0; //if the user presses quit
    //front end varibles:
    int current_screen; //stores which screen user is on. <0, main menu>, <1, map selection>, <2, player selection>, <3, credits>, <4, settings>
    SDL_Texture * screen_ptr1; 
    SDL_Texture * screen_ptr2; 
    //these variables store which sprites are currently rendered to the screen and which were previously
    // this is used to detect transition between sprites!
    int previous_sprite_selected; 
    int present_sprite_selected; 
    
    // int previous_screen; //stores which screen user was on before the current screen
    const int map_selection_box_width = 392-77; //map selection screen boxes 
    const int map_selection_box_height = 646 - 286;
    const int selection_box_w = 816 - 542; //main menu selection boxes
    const int selection_box_h = 340 -257;
    const int player_selection_box_w = 567-293; //player selection screen boxes
    const int player_selection_box_h =  612 - 273;
    const int mute_selection_box_w = 807 - 562 ;   //settings screen selection boxes
    const int mute_selection_box_h = 396- 323;
    SDL_Rect back_button_mover = {1192, 638, 2*210/3, 2*110/3}; //back button for settings sprite
    std::vector <std::vector <SDL_Texture*>> menu_sprites; //vector to store all menu sprites
    //mute flags
    bool bg_muted = 0; 
    bool sfx_muted = 0;
    //vector to check which map was selected:
    int selected_map = 1; //4 maps
    //draws all sprites on screen
    void draw(); 
    
    
    public:
    bool menuactive = true; //flag which maintains the menu state
    bool check_mute();
    int get_selected_map(); //gets the value of which map to load on screen
    Menu();
    void refresh(SDL_Renderer * gRenderer, int x, int y, bool click, Sound &); //checks which sprites to draw and draws them on screen;
    void add_sprite(SDL_Texture*, int screen_number); //adds a sprite to the 2d vectors of sprites. 
    bool quit_game(); //checks if quit game was clicked 
    
    
    ~Menu();
};