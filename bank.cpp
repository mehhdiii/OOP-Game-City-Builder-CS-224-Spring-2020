#include"bank.hpp"

Bank::Bank(SDL_Texture * asset): Building(asset) {
    setSize(175/2,  100/2);
    name = "bank";
}

// void Bank::setPeoplecount(int people){
//     peopleCount = people;
// }


// void Bank::setPrice(int house_price){
//     pricing = house_price;
// }

void Bank::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}