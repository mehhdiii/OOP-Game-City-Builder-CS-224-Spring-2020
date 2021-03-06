#include"topbar.hpp"


Topbar::Topbar(SDL_Texture * asset): Unit(asset){
    setCoordinates(0,0);
    setSize(SCREEN_WIDTH, 45);
    
    for(int i = 0; i<number_of_bars; i++){
        std::vector<SDL_Texture*> *v1 = new std::vector<SDL_Texture*>;
        stats_sprite.push_back(*v1);
        
    }
    std::cout<<"this shit works!" <<std::endl;
    for(int i =0; i<number_of_bars; i++){
        Draw_text *p = new Draw_text();
        text_objects.push_back(p);
    }
    setRect();
}

void Topbar::add_static_sprite(SDL_Texture* sprite_texture, int sprite_color){
    // stats_sprite = sprite_texture;
    //pink == 0;    // xp_level
    //gold ==1;     // cash
    //green==2;     // green energy
    //blue==4;      // oxygen level
    // for(int i=0; i<5; i++){
    stats_sprite[sprite_color].push_back(sprite_texture);
      
}

void Topbar::draw(SDL_Renderer * gRenderer){ //, int & main_cash, int & XP_level
    int top_cash = 30000;
    int top_xp_level = 800; 
    int main_cash = 10000;
    int cash_percent = ( main_cash / top_cash ) * 100;
    SDL_RenderCopy(gRenderer, assets, NULL,  &mover);

    if (cash_percent >= 0 && cash_percent < 20){
        SDL_RenderCopy(gRenderer, stats_sprite[0][0], NULL, &cash_mover);
    }
    else if (cash_percent >= 20 && cash_percent < 40){
        SDL_RenderCopy(gRenderer, stats_sprite[0][1], NULL, &cash_mover);
    }
    else if (cash_percent >= 40 && cash_percent < 60){
        SDL_RenderCopy(gRenderer, stats_sprite[0][2], NULL, &cash_mover);
    }
    else if (cash_percent >= 60 && cash_percent < 80){
        SDL_RenderCopy(gRenderer, stats_sprite[0][3], NULL, &cash_mover);
    }
    else if (cash_percent >= 80 && cash_percent < 100){
        SDL_RenderCopy(gRenderer, stats_sprite[0][4], NULL, &cash_mover);
    }

    SDL_RenderCopy(gRenderer, stats_sprite[1][4], NULL, &greenenergy_mover);

    SDL_RenderCopy(gRenderer, stats_sprite[2][2], NULL, &xplevel_mover);

    SDL_RenderCopy(gRenderer, stats_sprite[3][3], NULL, &oxygenlevel_mover);
}

void Topbar::draw_modified(SDL_Renderer* gRenderer, int & main_cash, int & XP_level, int & P_level, int & green_energy){
    cash = main_cash;
    float top_cash = 10000.0;
    float top_xp_level = 250.0;
    float top_p_level = 4.0;
    float top_g_energy = 20.0;
    float cash_percent = ( main_cash / top_cash ) * 100;
    float xp_percent = ( XP_level / top_xp_level ) * 100;
    float p_percent = (P_level / top_p_level) * 100;
    float g_percent = (green_energy / top_g_energy) * 100;

    // std::cout << "main cash : " << main_cash << std::endl;
    // std::cout << "cash percent : " << cash_percent << std::endl;
    // std::cout << " XP level  : " << XP_level << std::endl;
    // std::cout << "xp percent : " << xp_percent << std::endl;
    // std::cout << " P level  : " << P_level << std::endl;
    // std::cout << "p percent : " << p_percent << std::endl;

    SDL_RenderCopy(gRenderer, assets, NULL,  &mover);

    // SDL_RenderCopy(gRenderer, stats_sprite[0][3], NULL, &greenenergy_mover); // xp_level

    //blue - player level
    if (p_percent >= 0.0 && p_percent < 20.0){
        SDL_RenderCopy(gRenderer, stats_sprite[3][0], NULL, &cash_mover); // &oxygenlevel_mover
     }
    else if (p_percent >= 20.0 && p_percent < 40.0){
        SDL_RenderCopy(gRenderer, stats_sprite[3][1], NULL, &cash_mover); //oxygen level
    }
    else if (p_percent >= 40.0 && p_percent < 60.0){
        SDL_RenderCopy(gRenderer, stats_sprite[3][2], NULL, &cash_mover); //oxygen level
    }
    else if (p_percent >= 60.0 && p_percent < 80.0){
        SDL_RenderCopy(gRenderer, stats_sprite[3][3], NULL, &cash_mover); //oxygen level
    }
    else if (p_percent >= 80.0 ){ //&& p_percent <= 100.0
        SDL_RenderCopy(gRenderer, stats_sprite[3][4], NULL, &cash_mover); //oxygen level
    }

    //pink - xp level
    if (xp_percent >= 0.0 && xp_percent < 20.0){
        SDL_RenderCopy(gRenderer, stats_sprite[0][0], NULL, &xplevel_mover);//greenenergy
    }
    else if (xp_percent >= 20.0 && xp_percent < 40.0){
        SDL_RenderCopy(gRenderer, stats_sprite[0][1], NULL, &xplevel_mover);//greenenergy
    }
    else if (xp_percent >= 40.0 && xp_percent < 60.0){
        SDL_RenderCopy(gRenderer, stats_sprite[0][2], NULL, &xplevel_mover);//greenenergy
    }
    else if (xp_percent >= 60.0 && xp_percent < 80.0){
        SDL_RenderCopy(gRenderer, stats_sprite[0][3], NULL, &xplevel_mover);//greenenergy
    }
    else if (xp_percent >= 80.0){ // && g_percent <= 100.0
        SDL_RenderCopy(gRenderer, stats_sprite[0][4], NULL, &xplevel_mover);//greenenergy
    }

    // gold - cash
    if (cash_percent >= 0.0 && cash_percent < 20.0){ //g_percent
        SDL_RenderCopy(gRenderer, stats_sprite[1][0], NULL, &oxygenlevel_mover); // &cash_mover
    }
    else if (cash_percent >= 20.0 && cash_percent < 40.0){
        SDL_RenderCopy(gRenderer, stats_sprite[1][1], NULL, &oxygenlevel_mover);
    }
    else if (cash_percent >= 40.0 && cash_percent < 60.0){
        SDL_RenderCopy(gRenderer, stats_sprite[1][2], NULL, &oxygenlevel_mover);
    }
    else if (cash_percent >= 60.0 && cash_percent < 80.0){
        SDL_RenderCopy(gRenderer, stats_sprite[1][3], NULL, &oxygenlevel_mover);
    }
    else if (cash_percent >= 80.0 ){ //&& xp_percent <= 100.0
        SDL_RenderCopy(gRenderer, stats_sprite[1][4], NULL, &oxygenlevel_mover);
    }

    //green - green energy
    if (g_percent >= 0.0 && g_percent < 20.0){ //cash_percent
        SDL_RenderCopy(gRenderer, stats_sprite[2][0], NULL, &greenenergy_mover);
    }
    else if (g_percent >= 20.0 && g_percent < 40.0){
        SDL_RenderCopy(gRenderer, stats_sprite[2][1], NULL, &greenenergy_mover);
    }
    else if (g_percent >= 40.0 && g_percent < 60.0){
        SDL_RenderCopy(gRenderer, stats_sprite[2][2], NULL, &greenenergy_mover);
    }
    else if (g_percent >= 60.0 && g_percent < 80.0){
        SDL_RenderCopy(gRenderer, stats_sprite[2][3], NULL, &greenenergy_mover);
    }
    else if (g_percent >= 80.0 ){ //&& cash_percent <= 100.0
        SDL_RenderCopy(gRenderer, stats_sprite[2][4], NULL, &greenenergy_mover);
    }

    //now draw the text on screen
    //player level drawing
    text_objects[0]->setText(std::to_string(main_cash)); //"Cash "+
    text_objects[1]->setText(std::to_string(XP_level)); //"XP level "+
    text_objects[2]->setText(std::to_string(green_energy)); //"Green energy "+
    text_objects[3]->setText(std::to_string(P_level)); //"player level "+
    
    text_objects[0]->draw(gRenderer);
    text_objects[1]->draw(gRenderer);
    text_objects[2]->draw(gRenderer);
    text_objects[3]->draw(gRenderer);
}

void Topbar::setRect(){
    int width = 120;
    int height = 40;
    
    cash_mover.x =180+20;
    cash_mover.y = 3;
    cash_mover.w = width;
    cash_mover.h = height;

    greenenergy_mover.x = 519+20;
    greenenergy_mover.y = 3;
    greenenergy_mover.w = width;
    greenenergy_mover.h = height;

    xplevel_mover.x = 826+20;
    xplevel_mover.y = 3;
    xplevel_mover.w = width;
    xplevel_mover.h =height;

    oxygenlevel_mover.x = 1079+45;
    oxygenlevel_mover.y = 3;
    oxygenlevel_mover.w = width;
    oxygenlevel_mover.h = height;

    //setting coordinates of text object

    text_objects[0]->setCoordinates(1079 -30, oxygenlevel_mover.y+5); //+oxygenlevel_mover.w
    text_objects[1]->setCoordinates(826 -40, xplevel_mover.y +5);//+xplevel_mover.w
    text_objects[2]->setCoordinates(519-35, greenenergy_mover.y+5);//+greenenergy_mover.w
    text_objects[3]->setCoordinates(180-40, cash_mover.y +5); //+cash_mover.w  
}


Topbar::~Topbar(){

    stats_sprite.clear();
    text_objects.clear();
}