#pragma once
// #include <fstream>
// #include <boost/archive/text_iarchive.hpp>
// #include <boost/archive/text_oarchive.hpp>
#include<cmath>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <list>
#include<vector>
#include<tuple>
#include<algorithm>
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
#include"draw_text.hpp"
#include "map.hpp"
#include "sound.hpp"


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
    vector <Bird*> birds;
    vector <Building*> buildings;
    vector <Bank*> banks;
    vector <Unit *> all_objects;
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
    Menu * menu = new Menu(); //menu objects
    Topbar * topbar = NULL; 
    Map * map = NULL;
    //text variables
    //Globally used font
    TTF_Font *gFont = NULL;
    // Draw_text texts_object; //text class object




    // scores for the top bar
    int main_cash = 10000;
    int green_energy = 0; // MegaWatts
    int XP_level = 0;
    int P_level = 1; // first level
    int oxygen_level = 21; // percentage of oxygen level in the city.. upper bound is 21 and lower bound 14 or lower.    
    //a template which sorts the array of objects to draw on screen by using stl sorting algorithm (with respect to the y coordinate of objects)
    template<typename T>
    struct sortbyC{
		 bool operator() (const T &L,const T &R) const
            { 
             return (L->gety() < R->gety()); 
            }
	};
    template<typename Mytype>
    void Coordinate_sorting(vector<Mytype>&);
    // sound object
    Sound sound;
    //creating serialization template
    // Allow serialization to access non-public data members.
public:
    void update_parameters();
    bool init();
    bool loadMenu();
    bool loadMedia();
    void run_menu();
    void close_menu();
    bool exit_from_menu();
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
    bool helper_detect_collision(int x, int y, vector<mytype*> obj); //helper function for detect collision using template
    ~Game();
};

