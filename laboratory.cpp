#include "laboratory.hpp"


Laboratory::Laboratory(SDL_Texture * asset): Building(asset){
    setSize(80,  0.5625*80); 
    name = "laboratory";
}

void Laboratory::addScientist(){
    // we will be creating a scientist object here.. 
    Scientist * scientist = new Scientist(assets);
    (*scientist).set_associatedLabType(labType);
    (*scientist).set_associatedLabNo(labNo);

    // now we'll insert the scientist in the list 


    // lastly we'll draw the scientist on the screen
}

void Laboratory::assignWork(std::string given_task, int balance){    

    //checking whether player can buy the tech and also updating the money.
    int required_balance;
    int index = 0; 
    for (auto i=tech_list.begin(); i!=tech_list.end(); i++){
        if ((*i) == given_task){
            required_balance = technology_cost[index];
            if (balance>= required_balance){
                std::cout << "Laboratory will start developing your assigned task!"<< std::endl;
                currentTask = given_task;               //assigning the given task to the current task
                balance = balance - required_balance;
            }
            else
            {
                std::cout << "You donot have sufficient balance!"<<std::endl;
                break;
            }
            break;
        } 
        index++;
    }

    // I need to think of a mechanism for which each task will take how much time.

}

std::string Laboratory::getTechnology(){
    // we also need to show a small graphic or something to properly indicate that the task has been completed.
    return currentTask;
}

int Laboratory::getProgress(){
    return progress;
}

void Laboratory::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}

void Laboratory::show_progress(){
    float current_time = SDL_GetTicks()/1000; // current time in seconds
    int required_time = 120; // the time required for a work to be completed | 2 minutes
    progress = ((current_time-creation_time)/required_time)*100; // percentage of progress i.e. how much time-wise work should be completed.
    // std::cout << "Progress " << progress << std::endl;
    // std::cout << "Creation time " << creation_time << " seconds" << std::endl;
    // std::cout << "Current time " << current_time << " seconds" << std::endl;
    // std::cout << " current_time - creation_time " << current_time - creation_time << std::endl;
    // std::cout << "Required time " << required_time << " seconds" << std::endl;    
    if (progress >= 100){
        std::cout << "Your technology is ready! " << std::endl; 
        creation_time = SDL_GetTicks()/1000;    // resetting the creation time to current time in order start working on the next product.
    }
    else{
        std::cout << "Your technology is still in progress " << progress << " %." << std::endl; 
    }
}
