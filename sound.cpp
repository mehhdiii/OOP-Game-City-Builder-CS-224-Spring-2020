// #include"sound.hpp"


// Sound::Sound(SDL_Texture * asset){
//     // setCoordinates(0,0);
//     setSize(SCREEN_WIDTH, 45);
//     setRect();
    
//     for(int i = 0; i<number_of_bars; i++){
//         std::vector<SDL_Texture*> *v1 = new std::vector<SDL_Texture*>;
//         stats_sprite.push_back(*v1);
        
//     }
// }


// void Topbar::add_static_sprite(SDL_Texture* sprite_texture, int sprite_color){
//     // stats_sprite = sprite_texture;
//     //pink == 0;    // xp_level
//     //gold ==1;     // cash
//     //green==2;     // green energy
//     //blue==4;      // oxygen level
//     if(sprite_color == -1){
//         for(int i=0; i<4; i++){
//             stats_sprite[i].push_back(sprite_texture);
//         }
//     }
//     else{
//         stats_sprite[sprite_color].push_back(sprite_texture);
//     }
// }

// void Topbar::draw(SDL_Renderer * gRenderer){ //, int & main_cash, int & XP_level
//     SDL_RenderCopy(gRenderer, stats_sprite[1][4], NULL, &greenenergy_mover);

//     SDL_RenderCopy(gRenderer, stats_sprite[2][2], NULL, &xplevel_mover);

//     SDL_RenderCopy(gRenderer, stats_sprite[3][3], NULL, &oxygenlevel_mover);
// }

// void Topbar::draw_modified(SDL_Renderer* gRenderer, int & main_cash, int & XP_level, int & P_level, int & green_energy){
    
// }

// void Topbar::setRect(){
//     int width = 103;
//     int height = 32;

//     cash_mover.x =150 + 10 + 20;
//     cash_mover.y = 7;
//     cash_mover.w = width;
//     cash_mover.h = height;

//     greenenergy_mover.x = 409 + 25 + 25 + 20 + 30 +10;
//     greenenergy_mover.y = 7;
//     greenenergy_mover.w = width;
//     greenenergy_mover.h = height;

//     xplevel_mover.x = 736 + 20 + 20 +20 +20 +10;
//     xplevel_mover.y = 7;
//     xplevel_mover.w = width;
//     xplevel_mover.h =height;

//     oxygenlevel_mover.x = 1049+15 + 15;
//     oxygenlevel_mover.y = 7;
//     oxygenlevel_mover.w = width;
//     oxygenlevel_mover.h = height;  
// }


// Topbar::~Topbar(){
//     for(int i =0; i<number_of_bars; i++){
//         stats_sprite[i].clear();
//     }
// }