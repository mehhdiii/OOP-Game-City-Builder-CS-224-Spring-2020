#include "solarpanel.hpp"

SolarPanel::SolarPanel(SDL_Texture * asset): InAnimate(asset){
     setSize(80,  0.5625*80); 
     name = "solarpanel";
}

void SolarPanel::update_scores(int & main_cash, int & XP_level){  // updates the values of cash and XP_level
    std::cout << "You have bought a solar panel costing 2000."<<std::endl;
    main_cash = main_cash -2000; // updated the money | deduct the amount of buying a buiding i.e. 1000.
	XP_level = XP_level + 40; // updated the XP_level | it adds 25 XP to buy a building i.e. exhaustion to your character.
}

void SolarPanel::setEnergy(int assigned_energy){
    energyProduced = assigned_energy;
}

void SolarPanel::show_all_features(){
     cout << "Efficiency of this solar panel is " << efficiency << "."<< endl;
     cout << "Production period of this solar panel is " << productionPeriod << "days."<< endl;
     cout << "Energy produced of this solar panel is " << energyProduced << "MW."<< endl;
}

void SolarPanel::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}
SolarPanel::~SolarPanel(){
    
}