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
#include<tuple>
// #include<ctime>
#include"menu.hpp"
#include"house.hpp"
#include"park.hpp"
#include"farm.hpp"
#include"industry.hpp"
#include"optionBar.hpp"
#include"topbar.hpp"

using namespace std;
Uint32 SDL_GetTicks(void);

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

    //global reference to sprites2;
    SDL_Texture* assets2;
    SDL_Texture* forest_texture;

    SDL_Texture* house_texture ;
	SDL_Texture* bank_texture ;
	SDL_Texture* industry_texture ;
	SDL_Texture* lab_texture;
	SDL_Texture* man_texture ;
	SDL_Texture* park_texture ;
	SDL_Texture* scientist_texture ;
	SDL_Texture* tree_texture ;
	SDL_Texture* turbine_texture ;
	SDL_Texture* vehicle_texture ;
	SDL_Texture* worker_texture ;

    //You may use C++ linked lists, or you can create your own.

    // vector <Bird*> birds;
    // vector <Building*> buildings;
    // vector <Unit *> allobjects;
    Unit * temp_object = NULL; //object that are not yet been fixed on the screen
    // vector <Unit*> allobjects;
    vector <Farm*> farms;
    vector <House*> houses;
    // vector <Laboratory*> laboratories;
    vector <Industry*> industries;
    vector <Park*> parks;
    // vector <Vehicle*> vehicles;
    // vector <Worker*> workers;
    // vector <Scientist*> scientists;
    
    //menus and bars:
    OptionBar * optionBar = NULL; //option bar variable
    Menu menu; //menu objects
    Topbar * topbar = NULL; 

    // Fountain obj = Fountain(assets);
    // SDL_Rect src = {0, 0, 360, 400}; //object containing the coordinates to render from assets
    // SDL_Rect mover = {25,25,50,100}; //size of the object to draw on screen
    //sound variables:
    // Mix_Chunk *eggy = NULL; //egg splash.
    Mix_Music *background_music = NULL; //plays in the background
    // Mix_Chunk *bird1 = NULL;
    // Mix_Chunk *bird2 = NULL;

    
    
public:

    void update_parameters();
    bool init();
    bool loadMedia();
    void run();
    void close();
    SDL_Texture* loadTexture( std::string path );
    
    
    // void main_menu(list <SDL_Texture *>);
    void range_OptionBar(int xMouse, int yMouse);
    void select_object_in_optionbar(int, int); //checks which object is to be created by the option bar!
    void hover_object_with_cursor(); //hovers the object on screen with the cursors coordintes!

    bool detect_collision(int, int); 
    //draw
    void draw_all(SDL_Renderer *);
    
    
};

