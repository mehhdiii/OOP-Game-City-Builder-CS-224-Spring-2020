#include "SDL.h"
#include "building.hpp"
#include <string>
#include <vector>
#include <iostream>
#pragma once

class Industry: public Building{

    private:

        int pollution;
        int structureLevel;
        int totalEnergyConsumption;
        int greenEnergyDependence;
        int fossilFeulDependence;
        int upgrade_cost = 250;
        int upgrade_count = 0;
        int product_selling_profit = 120;
        int subjective_green_energy = 5;
        float creation_time;
        float progress;
        
        std::string industry_type;
        std::vector <std::string> all_types; //various industry types, all locked initially. the user has to spend money to unlock product production. 
        std::vector <int> industy_cost; //costs of all types of industries
    public:

        Industry(SDL_Texture * );
        void update_scores(int &, int &);
        void upgrade_industry(int & , int &);     // takes input three variables i.e. cash, xp_level.
        int get_green_energy();
        void set_industry_type(std::string,int);
        void shift_industry_focus(std::string,int);     // sochna hy 
        void set_energy_consumption(int);
        void set_greenEnergy_dependency(int);
        void set_fossilFuel_dependency(int);
        int showStructureLevel();
        void show_all_features();
        float collect_rewards();
        void set_creation_time(int);

        ~Industry();
};

