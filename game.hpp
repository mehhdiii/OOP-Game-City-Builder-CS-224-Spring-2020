#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <list>
#include<vector>
// #include<ctime>


using namespace std;

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1360;
    const int SCREEN_HEIGHT = 725;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    //global reference to sprites;
    SDL_Texture* assets;

    //You may use C++ linked lists, or you can create your own.

    // Fountain obj = Fountain(assets);
    // SDL_Rect src = {0, 0, 360, 400}; //object containing the coordinates to render from assets
    // SDL_Rect mover = {25,25,50,100}; //size of the object to draw on screen
    //sound variables:
    // Mix_Chunk *eggy = NULL; //egg splash.
    // Mix_Music *background_music = NULL; //plays in the background
    // Mix_Chunk *bird1 = NULL;
    // Mix_Chunk *bird2 = NULL;

    
    
public:

    void ToggleFullscreen(SDL_Window* Window);
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
    
    
};

