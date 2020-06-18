#include "worker.hpp"

Worker::Worker(SDL_Texture * asset): Animate(asset){
    setSize(OBJECT_WIDHT, OBJECT_HEIGHT); 
    name = "worker";
}

void Worker::update_scores(int & main_cash, int & XP_level){  // updates the values of cash and XP_level
    std::cout << "You have bought a worker costing 150."<<std::endl;
    main_cash = main_cash - 150; // updated the money | deduct the amount of buying a worker i.e. 150.
	XP_level = XP_level + 20; // updated the XP_level | it adds 30 XP to buy a worker i.e. exhaustion to your character.
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
