#include "SDL.h"
#include "inanimate.hpp"
#include <string>
#include <vector>
#include <iostream>
#pragma once
using namespace std;

class Tree: public InAnimate{

    private:

        int oxygenGenerated;
        float creation_time;
        std::string type;
        std::vector <std::string> all_types; //various tree types, all locked initially. the user has to spend money to unlock product production. 
        std::vector <int> respective_cost; //costs of all types of trees
    public:
    
        Tree (SDL_Texture *);
        void update_scores(int &, int &);
        void showOxygenGen();
        void set_creation_time(int);
};

