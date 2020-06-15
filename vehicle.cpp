#include "vehicle.hpp"

Vehicle::Vehicle(SDL_Texture * asset): InAnimate(asset){
    setSize(175/2,  100/2); 
    name = "vehicle";
}


void Vehicle::upgrade(int current_balance){
}

void Vehicle::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}

