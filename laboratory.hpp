#include "SDL.h"
#include "unit.hpp"
#include<string>
#pragma once

class Laboratory{
    private:
        string labType;
        int progress;
        string currentTask;
        int efficiency;

    public:

        Laboratory(SDL_Texture * );
        void addScientist();
        void getTechnology();
        void getProgress();


};