#include "industry.hpp"

Industry::Industry(SDL_Texture * asset): Building(asset){
   setSize(OBJECT_WIDHT, OBJECT_HEIGHT); 
    name = "industry";
}

void Industry::update_scores(int & main_cash, int & XP_level){  // updates the values of cash and XP_level
    std::cout << "You have bought a industry costing 1800."<<std::endl;
    main_cash = main_cash - 1800; // updated the money | deduct the amount of buying a industry i.e. 1500.
	// we can also increase the xp_level if the user updates the industry
    XP_level = XP_level + 25; // updated the XP_level | it adds 25 XP to buy a industry i.e. exhaustion to your character.
}

void Industry::upgrade_industry(int & main_cash, int & XP_level){ 
    if (upgrade_count <= 5){
        upgrade_count +=1;
        main_cash = main_cash-upgrade_cost;
        upgrade_cost = upgrade_cost*2-upgrade_cost/4;
        XP_level += 5 + upgrade_count;
        subjective_green_energy += 2*upgrade_count;
        product_selling_profit += 20*upgrade_count;
    }
}

int Industry::get_green_energy(){
    return subjective_green_energy;
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

float Industry::collect_rewards(){
    float current_time = SDL_GetTicks()/1000; // current time in seconds
    int required_time = 300; // the time required for a work to be completed | 5 minutes 
    progress = ((current_time-creation_time)/required_time)*100; // percentage of progress i.e. how much time-wise work should be completed.
    // std::cout << "Progress " << progress << std::endl;//131 .. 1.31 * 250
    // std::cout << "Creation time " << creation_time << " seconds" << std::endl;
    // std::cout << "Current time " << current_time << " seconds" << std::endl;
    // std::cout << " current_time - creation_time " << current_time - creation_time << std::endl;
    // std::cout << "Required time " << required_time << " seconds" << std::endl;    
    if (progress >= 100){
        float profit = (progress/100) * product_selling_profit;
        std::cout << "Your product is ready! " << std::endl; 
        creation_time = SDL_GetTicks()/1000;    // resetting the creation time to current time in order start working on the next product.
        progress = 0;
        return profit;    
    }
    else{
        std::cout << "Your product is still in progress " << progress << " %." << std::endl; 
        return -1.0;
    }
}

void Industry::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}

Industry::~Industry(){

}