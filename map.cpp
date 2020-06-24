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
void Map::add_grid_point(){
    // int map_x = src.x;
    // int map_y = src.y;
    // int x_abs = x_relative_coordinate+map_x;
    // int y_abs = y_relative_coordinate+map_y;
    // std::cout << "original x: " << x_abs<<std::endl;
    // std::cout << "original y: " << y_abs <<std::endl;
    int x = 2496; //starting coordinate of the center
    int y = 249 - GRID_HEIGHT/2; //starting ccordinate of the center y
    int nextx, nexty;
    grid_x.push_back(x);
    grid_y.push_back(y);
    for(int i = 0; i<10; i++){
        nextx = x - i*GRID_WIDTH/2;
        nexty = y + i*GRID_HEIGHT/2; 
        int innerx; 
        for(int j = 0; j<i+1 ; j++){
             std::cout << "i = " << i << std::endl <<"j = " << j <<std::endl;
             innerx  = nextx +GRID_WIDTH*j;
             grid_x.push_back(innerx);
             grid_y.push_back(nexty);
             std::cout << "grid ka x: "<<innerx <<std::endl;
             std::cout << "grid ka y: " <<nexty <<std::endl; 
        }
    }
    x = nextx; 
    y = nexty; 
    for(int i = 1; i<10; i++){
        nextx = x + i*GRID_WIDTH/2;
        nexty = y + i*GRID_HEIGHT/2; 
        int innerx; 
        for(int j = 0; j<10 - i ; j++){
            std::cout << "i = " << i << std::endl <<"j = " << j <<std::endl;
            innerx  = nextx +GRID_WIDTH*j;
            grid_x.push_back(innerx);
            grid_y.push_back(nexty);
            std::cout << "grid ka x: "<<innerx <<std::endl;
            std::cout << "grid ka y: " <<nexty <<std::endl; 
        }
    }

}
void Map::check_grid(int &x, int&y){
    //check the nearest block to fit the object in!:
    int minx = 99999; //inf value
    int miny = 99999;  //inf value
    int min_dis = 99999;
    int temp_dis;  
    int obj_xabs =  x+src.x;
    int obj_yabs = y + src.y;
    for(int i = 0; i<grid_x.size(); i++){
        temp_dis = sqrt(pow(grid_x[i] - obj_xabs, 2) + pow(grid_y[i] - obj_yabs, 2));
        if (temp_dis <min_dis){
            min_dis = temp_dis; 
            minx = grid_x[i];
            miny = grid_y[i]; 
            std::cout << "minx: " <<minx <<"\n" << "miny: " << miny << std::endl;
        }
        // if(x > grid_x[i] && )

    }

    int obj_rx = minx - src.x;
    int obj_ry = miny - src.y;
   
    x = obj_rx;
    y = obj_ry;
    
    //hardcoding the coordiates for testing purposes

    // if( x < map_xr +GRID_WIDTH/3 && x>map_xr-GRID_WIDTH/3  && y < map_yr +GRID_HEIGHT/3 && y>map_yr-GRID_HEIGHT/3){
        
    // }

}
void Map::get_relative_coordinates(int &xr, int &yr){
    xr = src.x;
    yr = src.y;
}
void Map::set_relative_coordinates(int xr, int yr){
    src.x = xr; 
    src. y = yr; 
}

Map::~Map(){
    
}