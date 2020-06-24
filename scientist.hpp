#include "SDL.h"
#include "Animate.hpp"
#include <string>
#include<iostream>
#pragma once

class Scientist: public Animate{

    private:
        int scientist_count;
        int associatedLabNo;
        SDL_Rect Image;
        int intelligence;
        bool work_Power;
        float creation_time;
        std::string associatedLabType;
    public:

        Scientist(SDL_Texture *);
        void update_scores(int &, int &);
        int getworkPower();
        void set_associatedLabNo(int);
        void set_associatedLabType(std::string);
        void set_creation_time(int);

        void increase_scientist();
        int show_scientist_count();
        ~Scientist();
};