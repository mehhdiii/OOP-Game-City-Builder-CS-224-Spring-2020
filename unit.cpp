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
bool Unit::operator==(Unit * temp_obj){
    int temp_x = temp_obj->getx();
    int temp_y = temp_obj->gety();
    int static_x = this->getx();
    int static_y = this->gety();
    int min_distance_for_collision = temp_obj->getw()/4 + this->getw()/4;
    int distance = sqrt(pow((static_x +temp_obj->getw()/2 - ((temp_x)+ (this)->getw()/2)),2) + pow((static_y+temp_obj->geth()/2  - (temp_y +(this)->geth()/2)), 2));
    if (distance < min_distance_for_collision){
        return 1;
    }
    return 0; 

}

Unit::~Unit(){
    
}
