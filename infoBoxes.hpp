#include "SDL.h"
#include "unit.hpp"
#include<string>
#include<iostream>
#include<vector>

#pragma once

class InfoBoxes: public Unit{

    private:
    
        const int SPRITE_W = 200;
        const int SPRITE_H = 0.5625*SPRITE_W;

        //text rendering objects
        // std::vector<Draw_text*> text_objects; 
        // SDL_Rect cash_mover; //size of the object to draw on screen
        void setRect(); //cropping out the sprite from the sheet
    public:

    InfoBoxes(SDL_Texture*);
    ~InfoBoxes();
    void draw(SDL_Renderer*);
};