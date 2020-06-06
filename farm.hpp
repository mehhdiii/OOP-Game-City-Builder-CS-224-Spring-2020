#include "SDL.h"
#include "inAnimate"
#pragma once

class Farm: public InAnimate{
    private:
        string type;
        string product;
    public:
        Farm(sdl_texture * );
        void addProduct();
        

};