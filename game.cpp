#include "game.hpp"
#include<iostream>
#include <typeinfo>
using namespace std;
#include<list>
bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Green City", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool Game::loadMedia()

{
	//Loading success flag
	bool success = true;
	
	assets = loadTexture("man01.svg");
    gTexture = loadTexture("hu.png");
	if(gTexture==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }

	//loading all music for the game:
	// eggy = Mix_LoadWAV( "eggy_splash.wav" );
	// background_music = Mix_LoadMUS("Waltz-music-loop/Waltz-music-loop.wav");
	// bird1 = Mix_LoadWAV("Waltz-music-loop/bird1.wav");
	// bird2 = Mix_LoadWAV("Waltz-music-loop/bird2.wav");
	// if( eggy == NULL || background_music ==NULL || bird1==NULL || bird2==NULL)
	// {
	// 	printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
	// 	success = false;
	// }
	
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assets);
	assets=NULL;
	SDL_DestroyTexture(gTexture);
	//free sound:

	// Mix_FreeChunk(eggy);
	// Mix_FreeMusic(background_music);
	// background_music =NULL;
	// eggy =NULL;
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}


void Game::run( )
{
    SDL_RenderClear( gRenderer );
	//Main loop flag
	bool quit = false;
	bool pause = false;
	bool egg_constraint = false; //if games needs to end
	//Event handler
	SDL_Event e;
	
	//While application is running
	while( !quit )
	{
		//play the background music
		if( Mix_PlayingMusic() == 0 )
				{
				//Play the music
				// Mix_PlayMusic( background_music, 1 );
		}
		
		
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			//user requests pause
			if (e.type==SDL_KEYDOWN ){
				if (e.key.keysym.sym == SDLK_ESCAPE){
					pause = !pause;
					if(pause){ //pause the music 
						Mix_PauseMusic();
					}
					else{ //play the music
						Mix_ResumeMusic();
					}
				}

			}

			if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT &&!pause){
				//this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				
                
               
				
			}
			// if (e.type == SDL_KEYDOWN && !pause){ //handling keyboard events
			// 	switch (e.key.keysym.sym)
			// 	{
			// 	case SDLK_m:
					
			// 		if( Mix_PausedMusic() == 1 ) //if music is paused
			// 		{
						
			// 			//Resume the music
			// 			Mix_ResumeMusic();
			// 		}
			// 		//If the music is playing
			// 		else
			// 		{
			// 			//Pause the music
			// 			Mix_PauseMusic();
			// 		}
			// 	break;
				
			// 	}

			// }
			
		}
		if (!pause){
            SDL_RenderClear(gRenderer); //removes everything from renderer
            SDL_RenderCopy(gRenderer, assets, NULL, NULL);//Draws background to renderer
            // SDL_RenderCopy(gRenderer, assets, &src, &mover);//Draws background to renderer

            // (obj).draw(gRenderer);
            SDL_RenderPresent(gRenderer); //displays the updated renderer
		}
		SDL_Delay(180);	//causes sdl engine to delay for specified miliseconds
		
		
	}
			
}
