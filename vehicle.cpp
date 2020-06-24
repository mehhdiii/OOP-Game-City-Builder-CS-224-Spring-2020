#include "vehicle.hpp"

Vehicle::Vehicle(SDL_Texture * asset): InAnimate(asset){
    setSize(OBJECT_WIDHT, OBJECT_HEIGHT); 
    name = "vehicle";
}

void Vehicle::update_scores(int & main_cash, int & XP_level){  // updates the values of cash and XP_level
    std::cout << "You have bought a vehicle costing 300."<<std::endl;
    main_cash = main_cash - 300; // updated the money | deduct the amount of buying a vehicle i.e. 300.
	XP_level = XP_level + 5; // updated the XP_level | it adds 5 XP to buy a vehicle i.e. exhaustion to your character.
}

void Vehicle::upgrade(int current_balance){
}

void Vehicle::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}

Vehicle::~Vehicle(){
    
}
