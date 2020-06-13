#include "park.hpp"

Park::Park(SDL_Texture * asset): InAnimate(asset){
     setSize(175/2,  100/2);

}

int Park::showEnvImpact(){
    return env_impact;
}