#include "SDL.h"
#include "unit.hpp"
#include<string>
#include<iostream>
#include<vector>

#pragma once

class InfoBoxes: public Unit{

    private:
    
        const int SPRITE_W = 0.7*400;
        const int SPRITE_H = 0.7*500;

        //text rendering objects
        // std::vector<Draw_text*> text_objects; 
        // SDL_Rect cash_mover; //size of the object to draw on screen
        void setRect(); //cropping out the sprite from the sheet
    public:

    InfoBoxes(SDL_Texture*);
    ~InfoBoxes();
    void draw(SDL_Renderer*);
};