#include "SDL.h"
#include "building.hpp"
#include <string>
#include <iostream>
#include<cmath>

#pragma once
#include<vector>


class Farm: public Building{

    private:
    
        const int WIDTH = 80;
        const int HEIGHT = 0.5625*WIDTH;
        std::string type;
        std::vector <std::string> products; //different products, all locked initially. the user has to spend money to unlock product production. 
        std::vector <int> product_cost; //costs of all products
        std::vector <bool> active_products;
        float creation_time;
        //serialization template




    public:

        Farm(SDL_Texture * );
        void update_scores(int &, int &);
        void addProduct(std::string, int);
        void set_creation_time(int);
        ~Farm();
};