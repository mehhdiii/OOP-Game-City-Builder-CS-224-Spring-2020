#include "building.hpp"
#include<cstdlib>
// #include"pigoen.hpp"
#pragma once


class Fountain: public Building{
    SDL_Rect src; //source object storing the pictures coordinates to extract from assets
    // bool broken = false; //bool which stores if an egg has fallen into a nest or not
    
public:
    // int kill_count; //counting frames after the egg falls in the list
    Fountain(SDL_Texture* tex);
    // Egg(SDL_Texture*, SDL_Rect);
    void draw(SDL_Renderer*); //draws the egg on screen 
    // void egg_in_nest(bool); //If collision occurs, it makes the object aware of it
    
};