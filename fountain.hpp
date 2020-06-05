#include "building.hpp"
#include<cstdlib>
// #include"pigoen.hpp"
#pragma once


class Fountain: public Building{
    SDL_Rect src; //source object storing the pictures coordinates to extract from assets
   
    
public:
    // int kill_count; //counting frames after the egg falls in the list
    Fountain(SDL_Texture* tex);
    
    void draw(SDL_Renderer*); //draws the egg on screen 
    // void egg_in_nest(bool); //If collision occurs, it makes the object aware of it
    
};