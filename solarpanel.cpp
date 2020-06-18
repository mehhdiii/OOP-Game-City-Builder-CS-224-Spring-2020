#include "solarpanel.hpp"

SolarPanel::SolarPanel(SDL_Texture * asset): InAnimate(asset){
     setSize(80,  0.5625*80); 
     name = "solarpanel";
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