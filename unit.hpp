#include "SDL.h"
#include<string>
#include<cmath>
#include<iostream>
#pragma once
Uint32 SDL_GetTicks(void);


class Unit{


        
       
    protected:
        const int SCREEN_WIDTH = 1360; //screen width of sdl window
        const int SCREEN_HEIGHT = 725; //screen height of the sdl window
        SDL_Texture* assets; //picture object
        SDL_Rect src; //object containing the coordinates to render from assets
        SDL_Rect mover = {0,0,50,50}; //size of the object to draw on screen


    public:
       
        std::string name; //stores the objects name for polymorphic implimentation 
        Unit(SDL_Texture *); //constructor passed with the object pointer to be drawn
        virtual void draw(SDL_Renderer*)=0; //draws on screen
        void setCoordinates(int, int); //sets coordinates;
        void setSize(int, int); //sets size of the object;-
        int getx();
        int gety();
        int getw();
        int geth();
        bool operator == (Unit * );
        virtual ~Unit();
};