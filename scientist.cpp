#include "scientist.hpp"

Scientist::Scientist(SDL_Texture * asset): Animate(asset){
    setSize(175/2,  100/2); 
}

int Scientist::getworkPower(){
    
    return 0;
}