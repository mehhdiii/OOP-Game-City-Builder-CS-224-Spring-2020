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