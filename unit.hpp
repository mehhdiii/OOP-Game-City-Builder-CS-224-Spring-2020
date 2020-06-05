#include "SDL.h"
#pragma once

class Unit{
    private:

        SDL_Texture* assets; //picture object
        SDL_Rect src; //object containing the coordinates to render from assets
        SDL_Rect mover = {0,0,50,50}; //size of the object to draw on screen
    
        //make this full screen
        const int SCREEN_WIDTH = 800; //screen width of sdl window
        const int SCREEN_HEIGHT = 600; //screen height of the sdl window

    public:

        Unit(SDL_Texture *); //constructor passed with the object pointer to be drawn
        virtual void Draw(SDL_Renderer*)=0; //draws on screen
        void setCoordinates(int, int); //sets coordinates;
        void setSize(int, int); //sets size of the object;-
};