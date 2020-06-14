#include"house.hpp"

House::House(SDL_Texture * asset): Building(asset) {
    setSize(175/2,  100/2);
    name = "house";
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

void House::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}