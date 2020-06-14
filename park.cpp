#include "park.hpp"

Park::Park(SDL_Texture * asset): InAnimate(asset){
    setSize(175/2,  100/2);
    name = "park";
}

int Park::showEnvImpact(){
    return env_impact;
}

void Park::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}