#include "building.hpp"

Building::Building(SDL_Texture * asset): InAnimate(asset){}

int Building::upgrade(int balance){
    int new_bal = balance-upgrade_cost;
    upgrade_cost = upgrade_cost*2-upgrade_cost/4;
    return new_bal;
}
int Building::showStructureLevel(){
    return structure_level;
}

void Building::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}

void Building::show_progress(){
    float current_time = SDL_GetTicks()/1000; // current time in seconds
    int required_time = 120; // the time required for a work to be completed | 2 minutes
    progress = ((current_time-creation_time)/required_time)*100; // percentage of progress i.e. how much time-wise work should be completed.
    // std::cout << "Progress " << progress << std::endl;
    // std::cout << "Creation time " << creation_time << " seconds" << std::endl;
    // std::cout << "Current time " << current_time << " seconds" << std::endl;
    // std::cout << " current_time - creation_time " << current_time - creation_time << std::endl;
    // std::cout << "Required time " << required_time << " seconds" << std::endl;    
    if (progress >= 100){
        std::cout << "Your product is ready! " << std::endl; 
        creation_time = SDL_GetTicks()/1000;    // resetting the creation time to current time in order start working on the next product.
    }
    else{
        std::cout << "Your product is still in progress " << progress << " %." << std::endl; 
    }
}