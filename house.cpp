#include"house.hpp"

House::House(SDL_Texture * asset): Building(asset) {
    setSize(175/2,  100/2);
    
}

void House::setPeoplecount(int people){
    peopleCount = people;
}

int House::getLocalityGrading(){

    return localityGrading;
}

void House::setPrice(int house_price){
    pricing = house_price;
}


