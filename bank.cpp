#include"bank.hpp"

Bank::Bank(SDL_Texture * asset): Building(asset) {
    setSize(175/2,  100/2);
    name = "bank";
}

void Bank::update_scores(int & main_cash, int & XP_level){  // updates the values of cash and XP_level
    std::cout << "You have bought a bank costing 800."<<std::endl;
    main_cash = main_cash -800; // updated the money | deduct the amount of buying a bank i.e. 1000.
	XP_level = XP_level + 12; // updated the XP_level | it adds 25 XP to buy a bank i.e. exhaustion to your character.
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