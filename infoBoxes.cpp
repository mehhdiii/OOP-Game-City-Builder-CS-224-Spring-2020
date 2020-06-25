#include"infoBoxes.hpp"

InfoBoxes::InfoBoxes(SDL_Texture* asset): Unit(asset){
    setCoordinates(1020,60);
    setSize(SPRITE_W, SPRITE_H);
}

void InfoBoxes::draw(SDL_Renderer* gRenderer){
    // std::cout << "in draw info boxes"<<std::endl;
    SDL_RenderCopy(gRenderer, assets, NULL,  &mover);
}

InfoBoxes::~InfoBoxes(){
    
}