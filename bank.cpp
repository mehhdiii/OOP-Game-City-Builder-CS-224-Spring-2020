#include"bank.hpp"

Bank::Bank(SDL_Texture * asset): Building(asset) {
    setSize(175/2,  100/2);
    name = "bank";
}

void Bank::update_scores(int & main_cash, int & XP_level){  // updates the values of cash and XP_level
    std::cout << "You have bought a bank costing 1500."<<std::endl;
    main_cash = main_cash -1500; // updated the money | deduct the amount of buying a bank i.e. 1000.
	XP_level = XP_level + 12; // updated the XP_level | it adds 25 XP to buy a bank i.e. exhaustion to your character.
}

void Bank::loan(int& main_cash){  // it gives the user the option to take loan from the bank on interest
    if (active_loan == false){
        loan_taken_time = SDL_GetTicks()/1000; // current time in seconds //3:16:05
        active_loan = true;
        int loan_required;
        if (loan_required == 2500){
            time_margin_given = 1200;   //twenty minutes in seconds
            deadline_time = loan_taken_time + time_margin_given;
            main_cash += 1000;    // it gives a loan of twenty five hundred to the user.
            std::cout << "You have twenty minutes to return the loan, otherwise, an increase of 2% will be add every 5 minutes." << std::endl; 
        }
        else if (loan_required == 5000){
            time_margin_given = 2400;   //forty minutes in seconds
            deadline_time = loan_taken_time + time_margin_given;
            main_cash += 2500;    // it gives a loan of five thousand to the user.
            std::cout << "You have forty minutes to return the loan, otherwise, an increase of 2% will be add every 7 minutes." << std::endl;
        }
        else if (loan_required == 7500){
            time_margin_given = 3600;   //sixty minutes in seconds
            deadline_time = loan_taken_time + time_margin_given;
            main_cash += 5000;    // it gives a loan of seventy five hundred to the user.
            std::cout << "You have sixty minutes to return the loan, otherwise, an increase of 2% will be add every 10 minutes." << std::endl;
        }
    }
    else {
        std::cout << "You already have an outstanding loan." << std::endl;
    }
}

bool Bank::check_outstanding_loan(){
    if (active_loan == true){
        float current_time = SDL_GetTicks()/1000; // current time in seconds //3:16:05
        if (current_time >= deadline_time){
            std::cout << "First pay your dues!" << std::endl;
            return false; // you can not buy any thing now..
        }
        else {
            return true; // you still have time to pay the loan.
        }
    }
    else{
        std::cout << "No outstanding loan."<<std::endl;
        return true;
    }
    return true;
}
// void Bank::setPeoplecount(int people){
//     peopleCount = people;
// }


// void Bank::setPrice(int house_price){
//     pricing = house_price;
// }

void Bank::set_creation_time(int c_t){
    creation_time = c_t/1000; //creation time in seconds
}