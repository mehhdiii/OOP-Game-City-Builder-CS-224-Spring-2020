#include "farm.hpp"


Farm::Farm(SDL_Texture * asset): Building(asset), active_products(15){
    setSize(87.5,  50); 
    name = "farm";
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