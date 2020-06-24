#include "SDL.h"
#include "building.hpp"
#include<string>
#include <vector>
#include <iostream>
#include<cmath>
#pragma once

class Bank: public Building{

    private:

        float creation_time;
        float loan_taken_time;
        bool active_loan = false;   // a flag to check if the player has taken a loan or not
        int time_margin_given;
        float deadline_time;
        // std::vector <int> house_prices; //costs of all houses
    public:

        Bank(SDL_Texture * );
        void update_scores(int &, int &);
        void loan(int&);
        bool check_outstanding_loan();
        void set_creation_time(int);
        ~Bank();
};
