#include"building.hpp"
#include<iostream>
using namespace std;

Building::Building (SDL_Texture* input_texture): assets(input_texture){
    //constructor
}
SDL_Rect Building::getMover(){ //gets the mover object of the given object
    return mover;
}

// bool Unit::operator>=(Unit *myobj){
//     return mover.x >= myobj->mover.x && mover.y >= myobj->mover.y ;
// }

// bool Unit::operator<=(Unit *myobj){
//     return mover.x <= myobj->mover.x && mover.y <= myobj->mover.y;
// }

// bool Unit::operator==(Unit *myobj){
//     return mover.x <= myobj->mover.x && mover.y <= myobj->mover.y;
// }
// Unit* Unit::operator+(int r){
//     mover.x+r;
//     mover.y+r;
//     return this;
// }
// void Unit::draw(SDL_Renderer* renderer){

//     // SDL_RenderClear( renderer );
//     SDL_RenderCopy(renderer, assets, NULL, NULL);
//     // SDL_RenderPresent( renderer );
    
// }

void Building::setCoordinates(int x, int y){ //set the coordinates of the object
    mover.x = x;
    mover.y = y;
}
Building::~Building(){
    // assets = {0, 0, 0, 0};
    delete this;
}