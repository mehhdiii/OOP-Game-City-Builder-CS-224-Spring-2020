#include"inanimate.hpp"

InAnimate::InAnimate(SDL_Texture * asset): Unit(asset){

}
void InAnimate::draw(SDL_Renderer * renderer){
    SDL_RenderCopy(renderer, assets, NULL, &mover);
}
