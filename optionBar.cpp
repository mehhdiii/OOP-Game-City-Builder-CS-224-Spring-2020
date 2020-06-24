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
    // std::cout << " In option bar " << std::endl;
    y = y  - (SCREEN_HEIGHT-250);
    // std::cout << "x: "<< x << " y: "<< y << std::endl;
    if(x >19 && x <85 && y> 56 && y<139){   // industry
        std::cout<<"Industry" << std::endl;
        return 0;
    }

    else if(x >97 && x <163 && y> 56 && y<139){   // bank
        std::cout<<"Bank" << std::endl;
        return 1;
    }

    else if(x >176 && x <242 && y> 56 && y<139){   // Lab
        std::cout<<"lab" << std::endl;
        return 2;
    }

    else if(x >255 && x <321 && y> 56 && y<139){   // House
        std::cout<<"House" << std::endl;
        return 3;
    }

    else if(x >333 && x <399 && y> 56 && y<139){   // Park
        std::cout<<"Park" << std::endl;
        return 4;
    }

    else if(x >411 && x <477 && y> 56 && y<139){   // Farm
        std::cout<<"Farm" << std::endl;
        return 5;
    }

    else if(x >489 && x <555 && y> 56 && y<139){   // trees
        std::cout<<"Trees" << std::endl;
        return 6;
    }

    else if(x >568 && x <634 && y> 56 && y<139){   // vehicle
        std::cout<<"Vehicle" << std::endl;
        return 7;
    }

    else if(x >646 && x <712 && y> 56 && y<139){   // turbine
        std::cout<<"Turbine" << std::endl;
        return 8;
    }

    // bottom part

    else if(x >19 && x <85 && y> 149 && y<227){   // scientist
        std::cout<<"scientist" << std::endl;
        return 9;
    }

    else if(x >97 && x <163 && y> 149 && y<227){   // worker
        std::cout<<"worker" << std::endl;
        return 10;
    }

    else if(x >176 && x <242 && y> 149 && y<227){   // man
        std::cout<<"man" << std::endl;
        return 11;
    }

    else if(x >255 && x <321 && y> 149 && y<227){   // animal
        std::cout<<"animal" << std::endl;
        return 12;
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
OptionBar::~OptionBar(){
    
}
