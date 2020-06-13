#include "laboratory.hpp"

Laboratory::Laboratory(SDL_Texture * asset): Building(asset){
    setSize(175/2,  100/2); 
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