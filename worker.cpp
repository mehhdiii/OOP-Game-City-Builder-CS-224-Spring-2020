#include "worker.hpp"

Worker::Worker(SDL_Texture * asset): Animate(asset){
    setSize(175/2,  100/2); 
    name = "worker";
}


void Worker::set_work_power(int input){
    work_power = input;
}

void Worker::deploy(){
    
}

void Worker::show_all_features(){

}

void Worker::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}
