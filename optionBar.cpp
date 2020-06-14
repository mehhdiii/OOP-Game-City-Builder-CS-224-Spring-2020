#include"optionBar.hpp"

OptionBar::OptionBar(SDL_Texture * asset): Unit(asset) {
    
    setCoordinates(0, SCREEN_HEIGHT-250);
    setSize(SCREEN_WIDTH, 250);
    enabled = true;
}

void OptionBar::draw(SDL_Renderer * gRenderer){
    SDL_RenderCopy(gRenderer, assets, NULL, &mover );
}

int OptionBar::detect_selection( int x, int y){
    y = y  - (SCREEN_HEIGHT-250);
    if(x >311 && y>32 && x< 386 && y<108){
        std::cout << x << y  - (SCREEN_HEIGHT-250)<< std::endl;
        return 0;
    }
    return -1;
    
}
void OptionBar::place_object(bool click, int x, int y){

}
// void optionBar::setPeoplecount(int people){
//     // peopleCount = people;
// }

// void optionBar::setPrice(int house_price){
//     // pricing = house_price;
// }

