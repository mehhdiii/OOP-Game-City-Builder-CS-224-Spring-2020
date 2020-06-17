#include "bird.hpp"

Bird::Bird(SDL_Texture * asset): Animate(asset){
    name = "bird";
}

void Bird::update_scores(int & main_cash, int & XP_level){  // updates the values of cash and XP_level
    std::cout << "You have bought a bird costing 50."<<std::endl;
    main_cash = main_cash -50; // updated the money | deduct the amount of buying a bird i.e. 50.
	XP_level = XP_level + 2; // updated the XP_level | it adds 2 XP to buy a bird i.e. exhaustion to your character.
}

void Bird::setCoordinates(int , int ){}

void Bird::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}