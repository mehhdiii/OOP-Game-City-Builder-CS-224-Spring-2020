#include "tree.hpp"

Tree::Tree(SDL_Texture * asset): InAnimate(asset){
     setSize(175/2,  100/2);
     name = "tree";
}

void Tree::showOxygenGen(){
     cout << "Oxygen Generated : " <<  oxygenGenerated << endl;
}

void Tree::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}
