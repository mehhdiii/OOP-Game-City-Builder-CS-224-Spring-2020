#include "vehicle.hpp"

Vehicle::Vehicle(SDL_Texture * asset): Animate(asset){
    setSize(175/2,  100/2); 
}

void Vehicle::upgrade(int current_balance){

}