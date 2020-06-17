#include "farm.hpp"


Farm::Farm(SDL_Texture * asset): Building(asset), active_products(15){
    setSize(80,  0.5625*80); 
    name = "farm";
}

void Farm::update_scores(int & main_cash, int & XP_level){  // updates the values of cash and XP_level
    std::cout << "You have bought a farm costing 550."<<std::endl;
    main_cash = main_cash -550; // updated the money | deduct the amount of buying a farm i.e. 550.
	XP_level = XP_level + 15; // updated the XP_level | it adds 15 XP to buy a farm i.e. exhaustion to your character.
}

void Farm::addProduct(std::string product, int balance){
    //search for the cost of the required upgrade
    int required_balance;
    int index = 0; 
    for (auto i=products.begin(); i!=products.end(); i++){
        if ((*i) == product){
            required_balance = product_cost[index];
            if (balance>= required_balance){
                std::cout << "upgraded!" <<std::endl;
                balance = balance - required_balance;
                active_products[index] = 1;
            }
            break;
        } 
        index++;
    }
}

void Farm::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}