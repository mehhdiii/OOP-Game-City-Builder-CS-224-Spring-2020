#include "bird.hpp"
// #include <iostream>
// using namespace std;

Bird::Bird(SDL_Texture * asset): Animate(asset){}

void Bird::setCoordinates(int , int ){
    
}

void Bird::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}