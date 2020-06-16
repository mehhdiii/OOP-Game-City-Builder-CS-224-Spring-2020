#include"turbine.hpp"

Turbine::Turbine(SDL_Texture * asset): InAnimate(asset) {
    setSize(175/2,  100/2);
    name = "turbine";
}

// void Bank::setPrice(int house_price){
//     pricing = house_price;
// }

void Turbine::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}