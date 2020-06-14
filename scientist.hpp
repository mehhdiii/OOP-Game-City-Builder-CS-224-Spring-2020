#include "SDL.h"
#include "Animate.hpp"
#include <string>
#pragma once

class Scientist: public Animate{

    private:

        int associatedLabNo;
        SDL_Rect Image;
        int intelligence;
        bool work_Power;
        float creation_time;
        std::string associatedLabType;
    public:

        Scientist(SDL_Texture *);
        int getworkPower();
        void set_associatedLabNo(int);
        void set_associatedLabType(std::string);
        void set_creation_time(int);
};