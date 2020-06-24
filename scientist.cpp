#include "scientist.hpp"

Scientist::Scientist(SDL_Texture * asset): Animate(asset){
    setSize(175/2,  100/2); 
    name = "scientist";
    scientist_count = 0;
}

void Scientist::update_scores(int & main_cash, int & XP_level){  // updates the values of cash and XP_level
    std::cout << "You have bought a scientist costing 250."<<std::endl;
    main_cash = main_cash - 250; // updated the money | deduct the amount of buying a scientist i.e. 250.
	XP_level = XP_level + 30; // updated the XP_level | it adds 25 XP to buy a scientist i.e. exhaustion to your character.
}

int Scientist::getworkPower(){
    return 0;
}

void Scientist::set_associatedLabNo(int a_L_n){
    associatedLabNo = a_L_n; // setting associated lab no from laboratory class.
}

void Scientist::set_associatedLabType(std::string a_L_t){
    associatedLabType = a_L_t; // setting associated lab type from laboratory class.
}

void Scientist::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}

void Scientist::increase_scientist(){
    scientist_count+=1;
}

int Scientist::show_scientist_count(){
    std::cout << scientist_count<< std::endl ; 
    
    return scientist_count;
}
Scientist::~Scientist(){
    
}