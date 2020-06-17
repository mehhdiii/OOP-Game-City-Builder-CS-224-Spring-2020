#include"house.hpp"

House::House(SDL_Texture * asset): Building(asset) {
    setSize(175/2,  100/2);
    name = "house";
}

void House::update_scores(int & main_cash, int & XP_level){  // updates the values of cash and XP_level
    std::cout << "You have bought a farm costing 650."<<std::endl;
    main_cash = main_cash - 650; // updated the money | deduct the amount of buying a house i.e. 650.
	XP_level = XP_level + 20; // updated the XP_level | it adds 20 XP to buy a house i.e. exhaustion to your character.	
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