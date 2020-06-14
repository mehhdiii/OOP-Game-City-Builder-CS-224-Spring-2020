#include "menu.hpp"


Menu::Menu(){
    current_screen = 0; //game starts at screen 0
    
    
    for(int i = 0; i<4; i++){
        std::vector<SDL_Texture*> * v1 = new std::vector<SDL_Texture*>;
        menu_sprites.push_back(*v1); 
    }
    // for(int i = 0; i<4; i++){
    //     std::vector<int > * v1 = new std::vector<SDL_Texture*>;
    //     menu_sprites.push_back(*v1); 
    // }


}

void Menu::add_sprite(SDL_Texture* sprite_texture, int screen_number){
    // std::vector <SDL_Texture *> temp = menu_sprites[0];
    // temp.push_back(sprite_texture);
    (menu_sprites[screen_number]).push_back(sprite_texture);
   
    
}
void Menu::refresh(SDL_Renderer * gRenderer, int xMouse, int yMouse, bool click){
    // std::cout << "came here" <<std::endl;
    switch (current_screen)
    {
        case 0:
        if(xMouse > 545 && xMouse < 810 && yMouse > 315 && yMouse <380){ //first
            SDL_RenderCopy(gRenderer, (menu_sprites[0])[1], NULL, NULL);//Draws background to renderer
        }
        else if (xMouse > 545 && xMouse < 810 && yMouse > 402 && yMouse <402+65) {//second
            SDL_RenderCopy(gRenderer, (menu_sprites[0])[2], NULL, NULL);//Draws background to renderer
        
        }
        else if (xMouse > 545 && xMouse < 810 && yMouse > 490 && yMouse <490+65) {//second
            SDL_RenderCopy(gRenderer, (menu_sprites[0])[3], NULL, NULL);//Draws background to renderer
        
        }
        else if (xMouse > 545 && xMouse < 810 && yMouse > 578 && yMouse <578+65) {//second
            SDL_RenderCopy(gRenderer, (menu_sprites[0])[4], NULL, NULL);//Draws background to renderer
        
        }
        else{
            SDL_RenderCopy(gRenderer, (menu_sprites[0])[0], NULL, NULL);
        }
        
        break;
    
        case 1:
        SDL_RenderCopy(gRenderer, (menu_sprites[1])[0], NULL, NULL);

        break;
    }
    

    //detect a click
    if (click){
        //check mouse location
        if(xMouse > 545 && xMouse < 810 && yMouse > 315 && yMouse <380){
             current_screen+=1;
        }
    }
}

Menu::~Menu(){
    //for(auto i = menu_sprites.begin(); i<menu_sprites.end(); i++){
        // delete  (*i);
    //}
}