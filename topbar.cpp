#include"topbar.hpp"


Topbar::Topbar(SDL_Texture * asset): Unit(asset){
    setCoordinates(0,0);
    setSize(SCREEN_WIDTH, 45);
    setRect();
    
    for(int i = 0; i<number_of_bars; i++){
        std::vector<SDL_Texture*> *v1 = new std::vector<SDL_Texture*>;
        stats_sprite.push_back(*v1);
        
    }
}


void Topbar::add_static_sprite(SDL_Texture* sprite_texture, int sprite_color){
    // stats_sprite = sprite_texture;
    //pink == 0;
    //gold ==1;
    //green==2;
    //blue==4;
    if(sprite_color == -1){
        for(int i=0; i<4; i++){
            stats_sprite[i].push_back(sprite_texture);
        }
    }
    else{
        stats_sprite[sprite_color].push_back(sprite_texture);
    }
    
}


void Topbar::draw(SDL_Renderer * gRenderer){
    
    SDL_RenderCopy(gRenderer, assets, NULL,  &mover);

    SDL_RenderCopy(gRenderer, stats_sprite[0][2], NULL, &cash_mover);

    SDL_RenderCopy(gRenderer, stats_sprite[1][1], NULL, &greenenergy_mover);

    SDL_RenderCopy(gRenderer, stats_sprite[2][2], NULL, &xplevel_mover);

    SDL_RenderCopy(gRenderer, stats_sprite[3][3], NULL, &oxygenlevel_mover);
}
void Topbar::setRect(){
    int width = 103;
    int height = 32;
    
    // for(int i=0; i<4;i++){
    //     cash[i].x = 0;
    //     cash[i].y = i*height;
    //     cash[i].w = width;
    //     cash[i].h = height;


    //     xplevel[i].x = width;
    //     xplevel[i].y = i*height;
    //     xplevel[i].w = width;
    //     xplevel[i].h = height;

    //     greenenergy[i].x = 2*width;
    //     greenenergy[i].y = i*height;
    //     greenenergy[i].w = width;
    //     greenenergy[i].h = height;

    //     oxygenlevel[i].x = 3*width;
    //     oxygenlevel[i].y = i*height;
    //     oxygenlevel[i].w = width;
    //     oxygenlevel[i].h = height;

    // }
    


    cash_mover.x =150;
    cash_mover.y = 7;
    cash_mover.w = width;
    cash_mover.h = height;

    greenenergy_mover.x = 409;
    greenenergy_mover.y = 7;
    greenenergy_mover.w = width;
    greenenergy_mover.h = height;

    xplevel_mover.x = 736;
    xplevel_mover.y = 7;
    xplevel_mover.w = width;
    xplevel_mover.h =height;

    oxygenlevel_mover.x = 1049;
    oxygenlevel_mover.y = 7;
    oxygenlevel_mover.w = width;
    oxygenlevel_mover.h = height;



    


}


Topbar::~Topbar(){
    for(int i =0; i<number_of_bars; i++){
        stats_sprite[i].clear();
    }
}