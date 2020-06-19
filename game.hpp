#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
// #include <SDL_ttf.h>
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
#include"bird.hpp"
#include"building.hpp"
#include"bank.hpp"
#include"house.hpp"
#include"park.hpp"
#include"farm.hpp"
#include"industry.hpp"
#include"laboratory.hpp"
#include"optionBar.hpp"
#include"park.hpp"
#include"scientist.hpp"
#include"solarpanel.hpp"
#include"topbar.hpp"
#include"tree.hpp"
#include"turbine.hpp"
#include"vehicle.hpp"
#include"worker.hpp"

#include "map.hpp"

using namespace std;
Uint32 SDL_GetTicks(void);


class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1360;
    const int SCREEN_HEIGHT = 725;
    const int OPTIONBAR_CLOSE_BUTTON_WIDTH = 20;
    const int OPTIONBAR_CLOSE_HEIGHT = 20;
    const int SCROLL_SPEED = 50;

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
    SDL_Texture* map_texture;
    //You may use C++ linked lists, or you can create your own.

    vector <Bird*> birds;
    vector <Building*> buildings;
    vector <Bank*> banks;
    // vector <Unit *> allobjects;
    Unit * temp_object = NULL; //object that are not yet been fixed on the screen
    // vector <Unit*> allobjects;
    vector <Farm*> farms;
    vector <House*> houses;
    vector <Laboratory*> laboratories;
    vector <Industry*> industries;
    vector <Park*> parks;
    vector <Tree*> trees;
    vector <Turbine*> turbines;
    vector <SolarPanel*> solarpanels;
    vector <Vehicle*> vehicles;
    vector <Worker*> workers;
    vector <Scientist*> scientists;
    Scientist * scientist_obj = NULL;

    //menus and bars:
    OptionBar * optionBar = NULL; //option bar variable
    Menu menu; //menu objects
    Topbar * topbar = NULL; 
    Map * map = NULL;
    // Fountain obj = Fountain(assets);
    // SDL_Rect src = {0, 0, 360, 400}; //object containing the coordinates to render from assets
    // SDL_Rect mover = {25,25,50,100}; //size of the object to draw on screen
    //sound variables:
    // Mix_Chunk *eggy = NULL; //egg splash.
    
    Mix_Music *background_music = NULL; //plays in the background
    // Mix_Chunk *bird1 = NULL;
    // Mix_Chunk *bird2 = NULL;
// protected:

    int main_cash = 10000;
    
    
public:

    void update_parameters();
    bool init();
    bool loadMedia();
    void run_menu();
    void run();
    void close();
    SDL_Texture* loadTexture( std::string path );
    //draw menu:
    void draw_menu(SDL_Renderer*);


    
    // void main_menu(list <SDL_Texture *>);
    void range_OptionBar(int xMouse, int yMouse);
    void select_object_in_optionbar(int, int); //checks which object is to be created by the option bar!
    void hover_object_with_cursor(); //hovers the object on screen with the cursors coordintes!

    void scroll_objects(bool, bool, bool, bool);

    bool detect_collision(int, int); 
    
    //draw
    void draw_all(SDL_Renderer *);
    




    
    template<typename mytype> //template to store a generic type of object vector for passing into the function
    bool helper_detect_collision(int x, int y, vector<mytype*> obj) //helper function for detect collision using template
    {
	int sp_of_temp_obj_x = temp_object->getx();
	int sp_of_temp_obj_y = temp_object->gety();
	int ep_of_temp_obj_x = x+temp_object->getw();
	int ep_of_temp_obj_y = y + temp_object->geth();

	//static object
	int sp_of_static_obj_x, sp_of_static_obj_y, ep_of_static_obj_x, ep_of_static_obj_y; 
	
	bool yChecksp = 0;
	bool yCheckep = 0;
	bool xChecksp = 0;
	bool xCheckep = 0;
	for(auto i = obj.begin(); i!= obj.end(); i++){
		sp_of_static_obj_x = (*i)->getx();
		sp_of_static_obj_y = (*i)->gety();
		ep_of_static_obj_x = (*i)->getw() + (*i)->getx();
		ep_of_static_obj_y = (*i)->geth() + (*i)->gety();

		xChecksp = (sp_of_temp_obj_x  >= sp_of_static_obj_x && sp_of_temp_obj_x <= ep_of_static_obj_x);
		xCheckep = (ep_of_temp_obj_x >= sp_of_static_obj_x && ep_of_temp_obj_x <= ep_of_static_obj_x);
		yChecksp = (sp_of_temp_obj_y  >= sp_of_static_obj_y && sp_of_temp_obj_y <= ep_of_static_obj_y);
		yCheckep = (ep_of_temp_obj_y >= sp_of_static_obj_y && ep_of_temp_obj_y <= ep_of_static_obj_y);
 
		if((xChecksp||xCheckep) && (yChecksp ||yCheckep)){
			
			break;
		}
	}
	return ((xCheckep || xChecksp)&&(yCheckep||yChecksp)); 
}
 
 
 
    
};

