#include "worker.hpp"

Worker::Worker(SDL_Texture * asset): Animate(asset){
    setSize(175/2,  100/2); 
}

void Worker::set_work_power(int input){
    work_power = input;
}

void Worker::deploy(){
    
}

void Worker::show_all_features(){

}