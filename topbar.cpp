#include"topbar.hpp"


Topbar::Topbar(SDL_Texture * asset): Unit(asset){
    setSize(SCREEN_WIDTH, 45);
}

// void Topbar::add_static_sprites(SDL_Texture* sprite_texture){
//     stats_sprites.push_back(sprite_texture);
// }

void Topbar::draw(SDL_Renderer * gRenderer){
    
    SDL_RenderCopy(gRenderer, assets, NULL,  &mover);

}