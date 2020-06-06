#include"house.hpp"

House::House(SDL_Texture * asset): InAnimate(asset) {}

void House::setPeoplecount(int people){
    peopleCount = people;


}
void House::setPrice(int house_price){
    pricing = house_price;
}

