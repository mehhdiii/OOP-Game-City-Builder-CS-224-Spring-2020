#include"unit.hpp"

Unit::Unit(SDL_Texture * asset): assets{asset}{}

void Unit::setCoordinates(int xpos, int ypos){
    mover.x = xpos;
    mover.y = ypos; 
}
void Unit::setSize(int xsiz, int ysiz){
    mover.w = xsiz;
    mover.h = ysiz;
}
int Unit::getx(){
    return mover.x;
}
int Unit::gety(){
    return mover.y;
}
int Unit::getw(){
    return mover.w;
}
int Unit::geth(){
    return mover.h;
}

Unit::~Unit(){
    
}
