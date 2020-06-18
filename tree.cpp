#include "tree.hpp"

Tree::Tree(SDL_Texture * asset): InAnimate(asset){
     setSize(OBJECT_WIDHT, OBJECT_HEIGHT); 
     name = "tree";
}

void Tree::update_scores(int & main_cash, int & XP_level){  // updates the values of cash and XP_level
     std::cout << "You have bought a tree costing 500."<<std::endl;
    main_cash = main_cash -500; // updated the money | deduct the amount of buying a buiding i.e. 1000.
     XP_level = XP_level + 30; // updated the XP_level | it adds 25 XP to buy a building i.e. exhaustion to your character.
}

void Tree::showOxygenGen(){
     cout << "Oxygen Generated : " <<  oxygenGenerated << endl;
}

void Tree::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}
