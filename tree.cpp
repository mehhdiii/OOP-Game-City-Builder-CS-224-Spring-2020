#include "tree.hpp"

Tree::Tree(SDL_Texture * asset): InAnimate(asset){
     setSize(175/2,  100/2);

}

void Tree::showOxygenGen(){
     cout << "Oxygen Generated : " <<  oxygenGenerated << endl;
}
