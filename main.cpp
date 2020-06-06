#include "game.hpp"
// void ToggleFullscreen(SDL_Window* Window) {
//     Uint32 FullscreenFlag = SDL_WINDOW_FULLSCREEN;
//     bool IsFullscreen = SDL_GetWindowFlags(Window) & FullscreenFlag;
//     SDL_SetWindowFullscreen(Window, IsFullscreen ? 0 : FullscreenFlag);
//     SDL_ShowCursor(IsFullscreen);
// }

int main(int argc, char *argv[]){
    Game game; //create a game object
    // cout << "Im here" <<endl;


    // SDL_Init(SDL_INIT_VIDEO);
    // SDL_Window* Window = SDL_CreateWindow("",
    //     SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

    // bool Exit = false;
    // for (SDL_Event Event; !Exit;) {
    //     SDL_WaitEvent(&Event);
    //     if (Event.type == SDL_KEYDOWN) {
    //         switch (Event.key.keysym.sym) {
    //             case SDLK_f: ToggleFullscreen(Window); break;
    //             case SDLK_q: Exit = true; break;
    //         }
    //     }
    // }
    // SDL_DestroyWindow(Window);
    // SDL_Quit();


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