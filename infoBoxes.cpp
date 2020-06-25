#include"infoBoxes.hpp"

InfoBoxes::InfoBoxes(SDL_Texture* asset): Unit(asset){
    setCoordinates(0,0);
    setSize(SPRITE_W,SPRITE_H);
}

void InfoBoxes::draw(SDL_Renderer* gRenderer){
    SDL_RenderCopy(gRenderer, assets, NULL,  &mover);
}

InfoBoxes::~InfoBoxes(){
    
}