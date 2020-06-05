#include"fountain.hpp"
#include<iostream>
// #include"pigeon.hpp"

Fountain::Fountain (SDL_Texture * tex): Building(tex){
    // public:
    assets = tex;
    src = {0, 0, 360, 400};
    mover = {50, 50, 25, 25};
    // kill_count = 0;
}

void Fountain::draw(SDL_Renderer* renderer){
    
    // if (!broken){ //if egg is broken then do not chage its coordinates
    //     mover.y+=15;
    //     SDL_RenderCopyEx(renderer, assets, &src, &mover, rand(), NULL, SDL_FLIP_NONE);
    // }
    // else{
        std::cout << "hello" <<std::endl;
    SDL_RenderCopy(renderer, assets, NULL, NULL);
    // }
    
}




// bool Egg::operator>=(Pigeon *myobj){
//     return mover.x >= myobj->mover.x && mover.y >= myobj->mover.y ;
// }

// bool Egg::operator<=(Pigeon *myobj){
//     return mover.x <= myobj->mover.x && mover.y <= myobj->mover.y;
// }

// bool Egg::operator==(Pigeon *myobj){
//     return mover.x <= myobj->mover.x && mover.y <= myobj->mover.y;
// }