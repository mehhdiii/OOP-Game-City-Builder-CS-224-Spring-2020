#include"inanimate.hpp"

InAnimate::InAnimate(SDL_Texture * asset): Unit(asset){
}

void InAnimate::draw(SDL_Renderer * renderer){
    SDL_RenderCopy(renderer, assets, NULL, &mover);
}

void InAnimate::setCoordinates(int x, int y){
    // std::cout << "hello world!" <<std::endl;
    Unit::setCoordinates(x - getw()/2 , y-geth()/2); //centralizing the objects coordinates
}

void InAnimate::refresh_coordinates(int x, int y){
    Unit::setCoordinates(x, y); //
}

// void InAnimate::setfont(TTF_Font * myFont){
    
// }