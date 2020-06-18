#include "park.hpp"

Park::Park(SDL_Texture * asset): InAnimate(asset){
    setSize(OBJECT_WIDHT, OBJECT_HEIGHT); 
    name = "park";
}

int Park::showEnvImpact(){
    return env_impact;
}

void Park::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}