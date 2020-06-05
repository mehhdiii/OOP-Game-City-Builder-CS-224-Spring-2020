#include "SDL.h"
#pragma once
class Building{
public:
    SDL_Texture* assets; //picture object
    SDL_Rect src; //object containing the coordinates to render from assets
    SDL_Rect mover = {0,0,50,50}; //size of the object to draw on screen
    const int SCREEN_WIDTH = 800; //screen width of sdl window
    const int SCREEN_HEIGHT = 600; //screen height of the sdl window
public:
    Building(SDL_Texture*); //constructor
    virtual void draw(SDL_Renderer*) = 0; //virtual draw function as there is no synthesizable object of the type UNIT
    SDL_Rect getMover(); //gets the mover object of a given object

    void setCoordinates(int, int); //sets coordinates of this object
    virtual ~Building(); // default distructor
};