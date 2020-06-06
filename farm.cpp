#include "farm.hpp"

Farm::Farm(SDL_Texture * asset): InAnimate(asset), active_products(15){
    setSize(175/2,  100/2); 
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