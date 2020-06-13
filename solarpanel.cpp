#include "solarpanel.hpp"

SolarPanel::SolarPanel(SDL_Texture * asset): InAnimate(asset){
     setSize(175/2,  100/2);
}

void SolarPanel::setEnergy(int assigned_energy){
    energyProduced = assigned_energy;
}

void SolarPanel::show_all_features(){
     cout << "Efficiency of this solar panel is " << efficiency << "."<< endl;
     cout << "Production period of this solar panel is " << productionPeriod << "days."<< endl;
     cout << "Energy produced of this solar panel is " << energyProduced << "MW."<< endl;
}