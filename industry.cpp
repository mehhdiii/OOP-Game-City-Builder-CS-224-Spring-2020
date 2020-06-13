#include "industry.hpp"

Industry::Industry(SDL_Texture * asset): Building(asset){}

int Industry::upgrade_industry(int balance){

    int new_bal = balance-upgrade_cost;
    upgrade_cost = upgrade_cost*2-upgrade_cost/4;
    return new_bal;
}

void Industry::set_industry_type(std::string assignment_type, int balance){
    int required_balance;
    int index = 0; 
    for (auto i=all_types.begin(); i!=all_types.end(); i++){
        if ((*i) == assignment_type){
            required_balance = industy_cost[index];
            if (balance>= required_balance){
                std::cout << "Industry has setup with its directed focus work." <<std::endl;
                industry_type = assignment_type;
                balance = balance - required_balance;
            }
            break;
        } 
        index++;
    }
}

void Industry::set_energy_consumption(int t_e_c){
    totalEnergyConsumption = t_e_c;
}

void Industry::set_greenEnergy_dependency(int g_e_d){
    greenEnergyDependence = g_e_d;
}

void Industry::set_fossilFuel_dependency(int f_f_d){
    fossilFeulDependence = f_f_d;
}

int Industry::showStructureLevel(){
    return structureLevel;
}

void Industry::show_all_features(){
    std::cout << "Total Energy Consumption : " << totalEnergyConsumption << std::endl;
    std::cout << "Green Energy Dependency : " << greenEnergyDependence << std::endl;
    std::cout << "Fossil Fuel Dependency : " << fossilFeulDependence << std::endl;
}