#include"sound.hpp"


Sound::Sound(){
}

bool Sound::load_menu_background_music(){
    bool success = true;
    menu_background_music = Mix_LoadMUS("game_sounds/Inception.wav");
    if(menu_background_music ==NULL ) // checks whether music has been loaded
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
    return success;
}

void Sound::play_menu_background_music(){
    if( Mix_PlayingMusic() == 0 )
    {
        //Play the music
        Mix_PlayMusic( menu_background_music, -1 );
    }
}

void Sound::stop_music(){
    Mix_HaltMusic();
}

bool Sound::load_game_background_music(){
    bool success = true;
    game_background_music = Mix_LoadMUS("game_sounds/Game_Background.wav");
	if(game_background_music ==NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
    return success;
}

void Sound::play_game_background_music(){
    if( Mix_PlayingMusic() == 0 )
    {
        SDL_Delay(2500);
        //Play the music
        Mix_PlayMusic( game_background_music, -1 );
    }	
}    

bool Sound::load_all_SFX_music(){
    bool success = true;
    click_music = Mix_LoadWAV("game_sounds/Click.wav");
    error_music = Mix_LoadWAV("game_sounds/Error.wav");
    hover_music = Mix_LoadWAV("game_sounds/Hover.wav");
    loss_music = Mix_LoadWAV("game_sounds/Loss.wav");
    positive_music = Mix_LoadWAV("game_sounds/Positive.wav"); 
    victory_music = Mix_LoadWAV("game_sounds/Victory.wav");
    if(click_music == NULL || error_music == NULL || hover_music == NULL || loss_music == NULL || positive_music ==NULL || victory_music == NULL) 
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
    return success;
}

void Sound::play_click_music(){
    //Play the music
    Mix_PlayChannel(-1, click_music, 0);
    // Mix_PlayMusic( click_music, 1 );
}

void Sound::play_error_music(){
    //Play the music
    // Mix_PlayMusic( error_music, 1 );
}

void Sound::play_hover_music(){
    // if( Mix_PlayingMusic() == 0 )
    // {
    //     //Play the music
    //     Mix_PlayMusic( hover_music, -1 );
    // }
    //Play the music
    
    Mix_PlayChannel(-1, hover_music, 0);
    // Mix_PlayMusic( hover_music, 1);
}   

void Sound::play_loss_music(){
    //Play the music
    // Mix_PlayMusic( loss_music, 1 );
}

void Sound::play_positive_music(){
    //Play the music
    // Mix_PlayMusic( positive_music, 1 );
}

void Sound::play_victory_music(){
    //Play the music
    // Mix_PlayMusic( victory_music, 1 );
}