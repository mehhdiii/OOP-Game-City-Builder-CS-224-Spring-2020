#include"inanimate.hpp"

InAnimate::InAnimate(SDL_Texture * asset): Unit(asset){
}

void InAnimate::draw(SDL_Renderer * renderer){
    SDL_RenderCopy(renderer, assets, NULL, &mover);

    if (box_flag == 1){
        // we will renderer the panel box here
    }
}

void InAnimate::set_box_flag(bool inpt_flag){
    box_flag = inpt_flag;
}

void InAnimate::setCoordinates(int x, int y){
    Unit::setCoordinates(x - getw()/2 , y-geth()/2); //centralizing the objects coordinates
}

void InAnimate::refresh_coordinates(int x, int y){
    Unit::setCoordinates(x, y); //
}

void InAnimate::load_description_texture(SDL_Texture * new_asset, SDL_Renderer * gRenderer){
    InfoBoxes * infobox = new InfoBoxes(new_asset);
    description_tex = new_asset;
    if (box_flag == 1){
        // we will renderer the panel box here
        (*infobox).draw(gRenderer);
    }
}

InAnimate::~InAnimate(){
    
}