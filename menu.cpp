#include "menu.hpp"


Menu::Menu(){
    current_screen = 0; //game starts at screen 0
    
    present_sprite_selected = 0; 
    previous_sprite_selected = present_sprite_selected;
    
    for(int i = 0; i<5; i++){
        std::vector<SDL_Texture*> * v1 = new std::vector<SDL_Texture*>;
        menu_sprites.push_back(*v1); 
    }



}

void Menu::add_sprite(SDL_Texture* sprite_texture, int screen_number){
    // std::vector <SDL_Texture *> temp = menu_sprites[0];
    // temp.push_back(sprite_texture);
    (menu_sprites[screen_number]).push_back(sprite_texture);
   
    
}
void Menu::refresh(SDL_Renderer * gRenderer, int xMouse, int yMouse, bool click, Sound & sound){
    // std::cout << "came here" <<std::endl;
    //0->main menu
    // 1 -> map selection
    // 2 -> player selection
    // 3 -> credits
    // 4-> settings
    // std::cout << "music volume  "<< Mix_VolumeMusic(-1) <<std::endl;
    // sound.play_hover_music();
    previous_sprite_selected = present_sprite_selected; //stores the previous selected sprite
    switch (current_screen)
    {
        
        case 0: //main menu
        {
            if((xMouse > 545 && xMouse < 545+selection_box_w && yMouse > 259 && yMouse <259+selection_box_h && current_screen==0)){ //first
                present_sprite_selected = 1;
                SDL_RenderCopy(gRenderer, (menu_sprites[0])[1], NULL, NULL);//Draws background to renderer
                if(previous_sprite_selected!=present_sprite_selected){
                    if (sfx_muted != 1){
                        sound.play_hover_music();
                    }
                }
            }
            else if ((xMouse > 545 && xMouse < 545+selection_box_w && yMouse > 348 && yMouse <348+selection_box_h && current_screen==0)) {//second
                present_sprite_selected = 2;
                SDL_RenderCopy(gRenderer, (menu_sprites[0])[2], NULL, NULL);//Draws background to renderer
                if(previous_sprite_selected!=present_sprite_selected){
                    if (sfx_muted != 1){
                        sound.play_hover_music();
                    }
                }
            
            }
            else if ((xMouse > 545 && xMouse < 545+selection_box_w && yMouse > 433 && yMouse <433+selection_box_h && current_screen==0)) {//second
                present_sprite_selected = 3;
                SDL_RenderCopy(gRenderer, (menu_sprites[0])[3], NULL, NULL);//Draws background to renderer
                if(previous_sprite_selected!=present_sprite_selected){
                    if (sfx_muted != 1){
                        sound.play_hover_music();
                    }
                }
            
            }
            else if ((xMouse > 545 && xMouse < 545+selection_box_w && yMouse > 522 && yMouse <522+selection_box_h && current_screen==0)) {//second
                present_sprite_selected = 4;
                SDL_RenderCopy(gRenderer, (menu_sprites[0])[4], NULL, NULL);//Draws background to renderer
                if(previous_sprite_selected!=present_sprite_selected){
                    if (sfx_muted != 1){
                        sound.play_hover_music();
                    }
                }
            
            }
            else if ((xMouse > 545 && xMouse < 545+selection_box_w && yMouse > 607 && yMouse <607+selection_box_h && current_screen==0)) {//second
                present_sprite_selected = 5;
                SDL_RenderCopy(gRenderer, (menu_sprites[0])[5], NULL, NULL);//Draws background to renderer
                if(previous_sprite_selected!=present_sprite_selected){
                    if (sfx_muted != 1){
                        sound.play_hover_music();
                    }
                }
            }
            else{
                SDL_RenderCopy(gRenderer, (menu_sprites[0])[0], NULL, NULL);
                present_sprite_selected = 0; 
                // sound.play_hover_music();
            }
            
            break;
        }
        case 1: //map selection screen
        {
            if(xMouse>77 && xMouse <77+map_selection_box_width && yMouse >286 && yMouse <286+map_selection_box_height){//map1
                present_sprite_selected = 1;
                SDL_RenderCopy(gRenderer, (menu_sprites[1])[1], NULL, NULL);
                 if(previous_sprite_selected!=present_sprite_selected){
                     if (sfx_muted != 1){
                        sound.play_hover_music();
                    }
                 }
            }
            else if (xMouse>392 && xMouse <392+map_selection_box_width && yMouse >286 && yMouse <286+map_selection_box_height){//map2
                present_sprite_selected = 2;
                SDL_RenderCopy(gRenderer, (menu_sprites[1])[2], NULL, NULL);
                 if(previous_sprite_selected!=present_sprite_selected){
                     if (sfx_muted != 1){
                        sound.play_hover_music();
                    }
                 }
            }
            else if(xMouse>704 && xMouse <704+map_selection_box_width && yMouse >286 && yMouse <286+map_selection_box_height){//map3
                present_sprite_selected = 3;
                SDL_RenderCopy(gRenderer, (menu_sprites[1])[3], NULL, NULL);
                 if(previous_sprite_selected!=present_sprite_selected){
                     if (sfx_muted != 1){
                        sound.play_hover_music();
                    }
                 }
            }
            else if(xMouse>1018 && xMouse <1018+map_selection_box_width && yMouse >286 && yMouse <286+map_selection_box_height){//map4
                present_sprite_selected = 4;
                SDL_RenderCopy(gRenderer, (menu_sprites[1])[4], NULL, NULL);
                 if(previous_sprite_selected!=present_sprite_selected){
                     if (sfx_muted != 1){
                        sound.play_hover_music();
                    }
                 }
            }
            else if(xMouse >1192 && yMouse >638){ //back!
                present_sprite_selected = 5;
                SDL_RenderCopy(gRenderer, (menu_sprites[1])[5], NULL, NULL);
                 if(previous_sprite_selected!=present_sprite_selected){
                     if (sfx_muted != 1){
                        sound.play_hover_music();
                    }
                 }
            }
            else{
                SDL_RenderCopy(gRenderer, (menu_sprites[1])[0], NULL, NULL); //unselected sprite
                // sound.play_hover_music();
            }
            break;
        }
        case 2:{//select player!
            
            
            if(xMouse > 293 && yMouse >273 && xMouse < 293+player_selection_box_w && yMouse < 273+player_selection_box_h){
                present_sprite_selected = 1;
                SDL_RenderCopy(gRenderer, (menu_sprites[2])[1], NULL, NULL);
                if(previous_sprite_selected!=present_sprite_selected){
                    if (sfx_muted != 1){
                        sound.play_hover_music();
                    }
                }
                    
            }
            else if(xMouse > 779 && yMouse >272 && xMouse < 779+player_selection_box_w && yMouse < 272+player_selection_box_h){
                present_sprite_selected = 2;
                SDL_RenderCopy(gRenderer, (menu_sprites[2])[2], NULL, NULL);
                if(previous_sprite_selected!=present_sprite_selected){
                    if (sfx_muted != 1){
                        sound.play_hover_music();
                    }
                }
                    
            }
            else if(xMouse >1192 && yMouse >638){ 
                present_sprite_selected = 3;
                SDL_RenderCopy(gRenderer, (menu_sprites[2])[3], NULL, NULL);
                if(previous_sprite_selected!=present_sprite_selected){
                    if (sfx_muted != 1){
                        sound.play_hover_music();
                    }
                }
                    
            }
            else{
                SDL_RenderCopy(gRenderer, (menu_sprites[2])[0], NULL, NULL);
                // sound.play_hover_music();
            }
            break;
        }
        case 3:{//credits
            
            if(xMouse >1192 && yMouse >638){ //back is pressed in  credits
                present_sprite_selected = 1;
                SDL_RenderCopy(gRenderer, (menu_sprites[3])[1], NULL, NULL);
                 if(previous_sprite_selected!=present_sprite_selected){
                     if (sfx_muted != 1){
                        sound.play_hover_music();
                    }
                 }
            }
            else{//normal credits!
                SDL_RenderCopy(gRenderer, (menu_sprites[3])[0], NULL, NULL);
                // sound.play_hover_music();
            }
            
            break;
            
        }
        case 4:{
            //checking for muted sprites
            if(bg_muted || sfx_muted){
                if(bg_muted && sfx_muted){
                    SDL_RenderCopy(gRenderer, (menu_sprites[4])[3], NULL, NULL);
                }
                else if (bg_muted){
                    SDL_RenderCopy(gRenderer, (menu_sprites[4])[1], NULL, NULL);
                }
                else if (sfx_muted){
                    SDL_RenderCopy(gRenderer, (menu_sprites[4])[2], NULL, NULL);
                }      
            }
            else{
                SDL_RenderCopy(gRenderer, (menu_sprites[4])[0], NULL, NULL);
            }

            //rendering the back button
            if(xMouse >1192 && yMouse >638){
                present_sprite_selected = 5;
                SDL_RenderCopy(gRenderer, (menu_sprites[4])[5], NULL, &back_button_mover );
                 if(previous_sprite_selected!=present_sprite_selected){
                     if (sfx_muted != 1){
                        sound.play_hover_music();
                    }
                 }

                    
            }
            else{
                SDL_RenderCopy(gRenderer, (menu_sprites[4])[4], NULL, &back_button_mover );
                //  if(previous_sprite_selected!=present_sprite_selected)
                //     sound.play_hover_music();
            }
            break;

            
        }
        

        
    }
    
    

    //detect a click
    if (click){
        //check mouse location
        // sound.play_click_music();
        switch (current_screen)
        {
            case 0:{
                if(xMouse > 545 && xMouse < 545+selection_box_w && yMouse > 259 && yMouse <259+selection_box_h && current_screen==0){ //user selects new game
                    current_screen =1;
                    present_sprite_selected = 0; //resetting the sprite count
                    if (sfx_muted != 1){
                        sound.play_click_music();
                    }
                    // std::cout << " detect a click " << Mix_VolumeMusic(-1) << std::endl;
                }
                else if( xMouse>545 && yMouse > 522 && xMouse < 545+selection_box_w && yMouse < 522+selection_box_h && current_screen==0){//user selects credits
                    current_screen = 3;
                    present_sprite_selected = 0; //resetting the sprite count
                    if (sfx_muted != 1){
                        sound.play_click_music();
                    }
                    // std::cout << " detect a click " << Mix_VolumeMusic(-1) << std::endl;
                }
                else if(xMouse > 544 && yMouse > 610 && xMouse < 544 + selection_box_w && yMouse < 610+selection_box_w &&current_screen == 0){//user selects exit
                    //exit!
                    if (sfx_muted != 1){
                        sound.play_click_music();
                    }
                    // std::cout << " detect a click " << Mix_VolumeMusic(-1) << std::endl;
                    present_sprite_selected = 0; //resetting the sprite count
                    menuactive = false;
                    quit_ = true;
                }
                else if (xMouse > 545 && xMouse < 545+selection_box_w && yMouse > 433 && yMouse <433+selection_box_h){
                    current_screen = 4;
                    present_sprite_selected = 0; //resetting the sprite count
                    if (sfx_muted != 1){
                        sound.play_click_music();
                    }
                    // std::cout << " detect a click " << Mix_VolumeMusic(-1) << std::endl;
                }
                break;
                }
            case 1:{
                if(xMouse>77 && xMouse <77+map_selection_box_width && yMouse >286 && yMouse <286+map_selection_box_height){
                    selected_map = 1;
                    current_screen =2;
                    present_sprite_selected = 0; //resetting the sprite count
                    if (sfx_muted != 1){
                        sound.play_click_music();
                    }
                    // std::cout << " detect a click " << Mix_VolumeMusic(-1) << std::endl;
                }
                else if (xMouse>392 && xMouse <392+map_selection_box_width && yMouse >286 && yMouse <286+map_selection_box_height){
                    selected_map = 2;
                    current_screen =2;
                    present_sprite_selected = 0; //resetting the sprite count
                    if (sfx_muted != 1){
                        sound.play_click_music();
                    }
                    // std::cout << " detect a click " << Mix_VolumeMusic(-1) << std::endl;
                }
                else if (xMouse>704 && xMouse <704+map_selection_box_width && yMouse >286 && yMouse <286+map_selection_box_height){
                    selected_map = 3;
                    current_screen =2;
                    present_sprite_selected = 0; //resetting the sprite count
                    if (sfx_muted != 1){
                        sound.play_click_music();
                    }
                }
                else if(xMouse>1018 && xMouse <1018+map_selection_box_width && yMouse >286 && yMouse <286+map_selection_box_height){
                    selected_map = 4;
                    current_screen =2;
                    present_sprite_selected = 0; //resetting the sprite count
                    if (sfx_muted != 1){
                        sound.play_click_music();
                    }
                }

                else if(xMouse >1192 && yMouse >638) //selects back
                {
                    current_screen = 0;
                    present_sprite_selected = 0; //resetting the sprite count
                    if (sfx_muted != 1){
                        sound.play_click_music();
                    }
                    // std::cout << " detect a click " << Mix_VolumeMusic(-1) << std::endl;
                }
                break;
            }

            case 2:{
                if(xMouse > 293 && yMouse >273 && xMouse < 293+player_selection_box_w && yMouse < 273+player_selection_box_h){//selects male!
                    menuactive = false;
                    present_sprite_selected = 0; //resetting the sprite count
                    if (sfx_muted != 1){
                        sound.play_click_music();
                    }
                    // std::cout << " detect a click " << Mix_VolumeMusic(-1) << std::endl;
                }
                else if (xMouse > 779 && yMouse >272 && xMouse < 779+player_selection_box_w && yMouse < 272+player_selection_box_h){ //selects female!
                     menuactive = false;
                     present_sprite_selected = 0; //resetting the sprite count
                     if (sfx_muted != 1){
                        sound.play_click_music();
                     }
                    //  std::cout << " detect a click " << Mix_VolumeMusic(-1) << std::endl;
                }
                else if(xMouse >1192 && yMouse >638) //selects back
                {
                    current_screen = 1;
                    present_sprite_selected = 0; //resetting the sprite count
                    if (sfx_muted != 1){
                        sound.play_click_music();
                    }
                    // std::cout << " detect a click " << Mix_VolumeMusic(-1) << std::endl;
                }
                break;
            }
            case 3:{
                if(xMouse >1192 && yMouse >638 && current_screen==3){//back from credits
                    current_screen = 0;
                    present_sprite_selected = 0; //resetting the sprite count
                    if (sfx_muted != 1){
                        sound.play_click_music();
                    }
                    // std::cout << " detect a click " << Mix_VolumeMusic(-1) << std::endl;
                }
                break;
            }
            case 4:{//settings
                if(xMouse >1192 && yMouse >638){
                    current_screen = 0;
                    present_sprite_selected = 0; //resetting the sprite count
                    if (sfx_muted != 1){
                        sound.play_click_music();
                    }
                    // std::cout << " detect a click " << Mix_VolumeMusic(-1) << std::endl;
                }
                else if (xMouse > 562 && yMouse > 323 && xMouse < 562 + mute_selection_box_w && yMouse < 323+mute_selection_box_h ){
                    if(bg_muted){
                        sound.resume_music();
                        bg_muted = 0;
                        sound.set_mute(bg_muted);
                    }
                    else{
                        sound.pause_music();
                        bg_muted = 1;
                        sound.set_mute(bg_muted);
                    }
                }
                else if(xMouse > 562 && yMouse > 420 && xMouse < 562 + mute_selection_box_w && yMouse < 420+mute_selection_box_h ){
                    if(sfx_muted){
                        sound.resume_sfx_music();
                        sfx_muted = 0;
                        sound.set_sfx_mute(sfx_muted);
                    }
                    else{
                        sound.pause_sfx_music();
                        sfx_muted = 1;
                        sound.set_sfx_mute(sfx_muted);
                    }
                }
                break;   
            }

        }
        
    }
}

bool Menu::quit_game(){
    return quit_;
}

int Menu::get_selected_map(){
    return selected_map;
}
Menu::~Menu(){
    // for(auto i = menu_sprites.begin(); i!=menu_sprites.end(); i++){
    //     for(auto j = (*i).begin(); j!=(*i).end(); i++){
    //         SDL_DestroyTexture(*j);
    //     }
    // }
}