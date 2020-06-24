#include "SDL.h"
#include <SDL_mixer.h>
#include<string>
#include<iostream>
#include<vector>
#pragma once

class Sound{

    private:

        bool bg_muted = 0;
        bool sfx_muted = 0;
        Mix_Music *game_background_music = NULL; //plays in the background in the game
        Mix_Music *menu_background_music = NULL; //plays in the background in the menu
        Mix_Chunk *click_music = NULL; //plays in the background in the game
        Mix_Chunk *error_music = NULL; //plays in the background in the menu
        Mix_Chunk *hover_music = NULL; //plays in the background in the game
        Mix_Chunk *loss_music = NULL; //plays in the background in the menu
        Mix_Chunk *positive_music = NULL; //plays in the background in the game
        Mix_Chunk *victory_music = NULL; //plays in the background in the menu
    public:

        Sound();
        // ~Sound();
        void stop_music();
        void pause_music();
        void resume_music();
        bool check_mute();
        void set_mute(bool);
        bool check_sfx_mute();
        void set_sfx_mute(bool);
        void pause_sfx_music();
        void resume_sfx_music();
        bool load_all_SFX_music();
        void play_click_music();
        void play_error_music();
        void play_hover_music();
        void play_loss_music();
        void play_positive_music();
        void play_victory_music();
        bool load_menu_background_music();
        void play_menu_background_music();
        bool load_game_background_music();
        void play_game_background_music();    
};