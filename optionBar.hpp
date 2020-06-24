#include "SDL.h"
#include "unit.hpp"
#include<string>
#include<vector>
#include "park.hpp"
#include<iostream>
#pragma once

class OptionBar: public Unit{
//     private:


//         int options;
    public:


        // std::vector <std::tuple<int, int> > coordinates_of_objects; //coordinates of objects visible at the option bar  

        bool enabled;

        OptionBar(SDL_Texture * );
        
        int detect_selection( int x, int y); //select object at present at the option bar
        
        void place_object(bool click, int x, int y); //places object when clicked by the user
        void draw(SDL_Renderer * ); //draw the option bar to the screen
        // int getLocalityGrading();
        // void setPeoplecount(int);
        // void setPrice(int);
        ~OptionBar();
};
