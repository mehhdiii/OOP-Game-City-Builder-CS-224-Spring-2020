#include "SDL.h"
#include "inAnimate.hpp"
#include <string>
#include <iostream>

#pragma once
#include<vector>
class Farm: public InAnimate{
    private:
        // std::string type;
        std::vector <std::string> products; //different products, all locked initially. the user has to spend money to unlock product production. 
        std::vector <int> product_cost; //costs of all products
        std::vector <bool> active_products;
    public:
        Farm(SDL_Texture * );
        void addProduct(std::string, int);
        

};