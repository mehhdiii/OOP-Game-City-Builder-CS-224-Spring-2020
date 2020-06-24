#include "SDL.h"
#include "Animate.hpp"
#include<iostream>
#pragma once

class Bird: public Animate{

    private:

        SDL_Rect Image;
        float creation_time;
    public:

        Bird(SDL_Texture *);
        void update_scores(int &, int &);
        void setCoordinates(int , int );
        void set_creation_time(int);
        ~Bird();
};