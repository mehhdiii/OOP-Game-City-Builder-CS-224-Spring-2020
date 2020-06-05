#include"unit.hpp"

Unit::Unit(SDL_Texture * asset): assets{asset}{}

void Unit::setCoordinates(int xpos, int ypos){
    mover.x = xpos;
    mover.y = ypos; 
}
