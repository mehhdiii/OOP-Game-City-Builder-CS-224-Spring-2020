#include "map.hpp"

Map::Map(SDL_Texture * asset): Unit(asset){
     setSize(SCREEN_WIDTH,  SCREEN_HEIGHT);
     setCoordinates(0, 0);
     //setting width and height of the image to render on screen
     src.w = SCREEN_WIDTH;
     src.h = SCREEN_HEIGHT;
     src.x = MAP_WIDTH/2 -200;
     src.y = MAP_HEIGHT/2 - 300;
    


}
void Map::draw(SDL_Renderer * gRenderer){
    SDL_RenderCopy(gRenderer, assets, &src, &mover );
}

void Map::scroll(bool xL, bool xR, bool yUp, bool yDown){
    if(xR){
        src.x+=SCROLL_SPEED;
    }
    if(xL){
        src.x-=SCROLL_SPEED;
    }
    if(yUp){
        // std::cout << "hello" <<std::endl;
        // std::cout << (src.y) <<std::endl;
        src.y = src.y - SCROLL_SPEED;
        // std::cout << src.y <<std::endl;
    }
    if(yDown){
        // std::cout << "down: ";
        // std::cout << (src.y) <<std::endl;
        src.y+=SCROLL_SPEED;
        // std::cout << (sr/c.y) <<std::endl;
    }

}

bool Map::scrolling_flag(bool xL, bool xR, bool yU, bool yD){
    
    
    if(src.x -SCROLL_SPEED >0 && xL){
        return true;
    }
    else if(src.x +SCROLL_SPEED < MAP_WIDTH- SCREEN_WIDTH && xR){
        return true;
    }
    else if(src.y-SCROLL_SPEED >0 && yU){
        return true;
    }
    else if(src.y+SCROLL_SPEED <MAP_HEIGHT-SCREEN_HEIGHT && yD){
        return true;
    }
    return false;
}
// void Map::set_creation_time(int c_t){
//     creation_time = c_t/1000; //creation time in seconds
// }