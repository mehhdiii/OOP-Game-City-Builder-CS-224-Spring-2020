#include "SDL.h"
#include "building.hpp"
#include "scientist.hpp"
#include <string>
#include <iostream>
#include<vector>
#pragma once

class Laboratory: public Building{

    private:

        int progress;               // the percentage of completion of a given task 
        int efficiency;             // 
        int labNo;                  // to number the labs created
        
        std::string labType;        // states the type of the lab.. energy research, bio-research, tech-update etc
        std::vector <std::string> tech_list; //different technologies, all locked initially. the user has to spend money to unlock working on respective tech.
        std::string currentTask;    // assigned task   
        std::vector <int> technology_cost; //costs of all technlogies 
    public:

        Laboratory(SDL_Texture * );
        void addScientist();
        void assignWork(std::string, int);
        std::string getTechnology();
        int getProgress();
};