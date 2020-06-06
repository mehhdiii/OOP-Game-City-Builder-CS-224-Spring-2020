#include "game.hpp"

int main(int argc, char *argv[]){
    Game game; //create a game object
    // cout << "Im here" <<endl;
    srand(time(NULL)); //set the random seed
    if( !game.init() ){ //initialize the game object
		printf( "Failed to initialize!\n" );
        return 0;
	}
		//Load media
    if( !game.loadMedia() ){ //load all media
        printf( "Failed to load media!\n" );
        return 0;
    }
    
    game.run(); //run the main game loop
    game.close(); //destroy all sdl objects and close game

    return 0; //return 0 to confirm success
}