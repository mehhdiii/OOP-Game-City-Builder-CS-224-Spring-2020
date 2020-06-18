#include "industry.hpp"

Industry::Industry(SDL_Texture * asset): Building(asset){
   setSize(OBJECT_WIDHT, OBJECT_HEIGHT); 
    name = "industry";
}

void Industry::update_scores(int & main_cash, int & XP_level){  // updates the values of cash and XP_level
    std::cout << "You have bought a industry costing 1500."<<std::endl;
    main_cash = main_cash - 1500; // updated the money | deduct the amount of buying a industry i.e. 1500.
	XP_level = XP_level + 25; // updated the XP_level | it adds 25 XP to buy a industry i.e. exhaustion to your character.
}

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

void Industry::show_progress(){
    float current_time = SDL_GetTicks()/1000; // current time in seconds
    int required_time = 90; // the time required for a work to be completed | 1.5 minutes 
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

void Industry::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}
