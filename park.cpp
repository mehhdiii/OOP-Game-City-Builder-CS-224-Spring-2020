#include "park.hpp"

Park::Park(SDL_Texture * asset): InAnimate(asset){
    setSize(175/2,  100/2);
    name = "park";
}

void Park::update_scores(int & main_cash, int & XP_level){  // updates the values of cash and XP_level
    std::cout << "You have bought a park costing 450."<<std::endl;
    main_cash = main_cash - 450; // updated the money | deduct the amount of buying a park i.e. 450.
	XP_level = XP_level + 15; // updated the XP_level | it adds 15 XP to buy a park i.e. exhaustion to your character.
}

int Park::showEnvImpact(){
    return env_impact;
}

void Park::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}