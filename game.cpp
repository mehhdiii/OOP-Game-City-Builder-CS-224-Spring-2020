#include "game.hpp"
#include<iostream>
#include <typeinfo>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
#include<list>


void Game::update_parameters(){
	// Objects : 1. birds - 2. building - 3. farm - 4. house - 5. laboratory - 6. industry - 7. park - 8. vehicle 
	// - 9. worker - 10. scientist.
	cout<<"Updating parameters :-)"<<endl;
	int money = 10000; // dollars
	int electricity = 250; // MegaWatts
	int XP_level = 0;
	int P_level = 1; // first level

	int input_from_user; 	

	for (int i = 0 ; i <= 10 ; i++){
		/* initialize random seed: */
  		srand (time(NULL));

  		/* generate secret number between 1 and 10: */
  		input_from_user = rand() % 10 + 1;

		cout<< "User has given input "<<input_from_user<<endl;
		if (XP_level/200 >= 1){
			XP_level -= 200;
			P_level += 1;
			money += 10000;
			cout<<"Welcome to level "<<P_level<<" !"<<endl;
		}

		if (input_from_user == 1){		// this means the user has selected bird
			//we create a bird object
			cout<<" Creating a bird object. "<<endl;
			// Bird * bird = new Bird(assets);  // we have created a bird object

			// (*bird).draw(gRenderer); 	// drawn the bird.

			// houses.push_back(house);

			money = money -50; // updated the money | deduct the amount of buying a bird i.e. 50.

			XP_level = XP_level + 2; // updated the XP_level | it adds 2 XP to buy a bird i.e. exhaustion to your character.
		}

		else if (input_from_user == 2){		// this means the user has selected building
			//we create a building object
			cout<<" Creating a building object. "<<endl;
			// Building * Building = new Building(assets);  // we have created a building object

			// (*building).draw(gRenderer); 	// drawn the building.

			// houses.push_back(house);

			money = money -1000; // updated the money | deduct the amount of buying a buiding i.e. 1000.

			XP_level = XP_level + 25; // updated the XP_level | it adds 25 XP to buy a building i.e. exhaustion to your character.
		}

		else if (input_from_user == 3){		// this means the user has selected farm
			//we create a farm object
			cout<<" Creating a farm object. "<<endl;
			// Farm * farm = new Farm(assets);  // we have created a farm object

			// (*farm).draw(gRenderer); 	// drawn the farm.

			// houses.push_back(house);

			money = money -550; // updated the money | deduct the amount of buying a farm i.e. 550.

			XP_level = XP_level + 15; // updated the XP_level | it adds 15 XP to buy a farm i.e. exhaustion to your character.
		}

		else if (input_from_user == 4){		// this means the user has selected house
			//we create a house object
			cout<<" Creating a house object. "<<endl;
			// House * house = new House(assets);  // we have created a house object

			// (*house).draw(gRenderer); 	// drawn the house.

			// houses.push_back(house);

			money = money - 650; // updated the money | deduct the amount of buying a house i.e. 650.

			XP_level = XP_level + 20; // updated the XP_level | it adds 20 XP to buy a house i.e. exhaustion to your character.
		}

		else if (input_from_user == 5){		// this means the user has selected laboratory
			//we create a laboratory object
			cout<<" Creating a laboratory object. "<<endl;
			// Laboratory * laboratory = new Laboratory(assets);  // we have created a laboratory object

			// (*laboratory).draw(gRenderer); 	// drawn the laboratory.

			// houses.push_back(house);

			money = money - 1200; // updated the money | deduct the amount of buying a laboratory i.e. 1200.

			XP_level = XP_level + 30; // updated the XP_level | it adds 30 XP to buy a laboratory i.e. exhaustion to your character.
		}

		else if (input_from_user == 6){		// this means the user has selected industry
			//we create a industry object
			cout<<" Creating a industry object. "<<endl;
			// Industry * industry = new Industry(assets);  // we have created a industry object

			// (*industry).draw(gRenderer); 	// drawn the industry.

			// houses.push_back(house);

			money = money - 1500; // updated the money | deduct the amount of buying a industry i.e. 1500.

			XP_level = XP_level + 25; // updated the XP_level | it adds 25 XP to buy a industry i.e. exhaustion to your character.
		}

		else if (input_from_user == 7){		// this means the user has selected park
			//we create a park object
			cout<<" Creating a park object. "<<endl;
			// Park * park = new Park(assets);  // we have created a park object

			// (*park).draw(gRenderer); 	// drawn the park.

			// houses.push_back(house);

			money = money - 450; // updated the money | deduct the amount of buying a park i.e. 450.

			XP_level = XP_level + 15; // updated the XP_level | it adds 15 XP to buy a park i.e. exhaustion to your character.
		}

		else if (input_from_user == 8){		// this means the user has selected vehicle
			//we create a vehicle object
			cout<<" Creating a vehicle object. "<<endl;
			// Vehicle * vehicle = new Vehicle(assets);  // we have created a vehicle object

			// (*vehicle).draw(gRenderer); 	// drawn the vehicle.

			// houses.push_back(house);

			money = money - 300; // updated the money | deduct the amount of buying a vehicle i.e. 300.

			XP_level = XP_level + 5; // updated the XP_level | it adds 5 XP to buy a vehicle i.e. exhaustion to your character.
		}

		else if (input_from_user == 9){		// this means the user has selected worker
			//we create a worker object
			cout<<" Creating a worker object. "<<endl;
			// Worker * worker = new Worker(assets);  // we have created a worker object

			// (*worker).draw(gRenderer); 	// drawn the worker.

			// houses.push_back(house);

			money = money - 150; // updated the money | deduct the amount of buying a worker i.e. 150.

			XP_level = XP_level + 20; // updated the XP_level | it adds 30 XP to buy a worker i.e. exhaustion to your character.
		}

		else if (input_from_user == 10){		// this means the user has selected scientist
			//we create a scientist object
			cout<<" Creating a scientist object. "<<endl;
			// Scientist * scientist = new Scientist(assets);  // we have created a scientist object

			// (*scientist).draw(gRenderer); 	// drawn the scientist.

			// houses.push_back(house);

			money = money - 250; // updated the money | deduct the amount of buying a scientist i.e. 250.

			XP_level = XP_level + 35; // updated the XP_level | it adds 25 XP to buy a scientist i.e. exhaustion to your character.
		}
		cout<<"Money : "<<money<<endl;
		cout<<"XP_level : "<<XP_level<<endl;
		cout<<"Player level : "<<P_level<<endl;
	}

}

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
	
	//loading menu
	//creating  menu object:
	
	int menu_sprite_range = 6;
	string spritename;
	//loading mainmenu
	for(int i=1; i<menu_sprite_range; i++){
		spritename = "";
		spritename = "mainmenu/Main_Menu_" + to_string(i) + ".png";
		cout << spritename <<endl; 
		menu.add_sprite(loadTexture(spritename), 0); 
	}
	//loading map menu
	for(int i=1; i<menu_sprite_range; i++){
		spritename = "";
		spritename = "mainmenu/Select_Map_" + to_string(i) + ".png";
		cout << spritename <<endl; 
		menu.add_sprite(loadTexture(spritename), 1); 
	}

	//loading option bar:
	optionBar = new OptionBar(loadTexture("optionbar/OptionBar2.png"));


	//loading other sprites

	assets = loadTexture("images/car-front-02.svg");

	// assets = loadTexture("images/car-front-02.svg");
	// assets2 = loadTexture("images/house-02.svg");
	forest_texture = loadTexture("images/Farm.png");
	house_texture = loadTexture("images/House.png");
	bank_texture = loadTexture("images/Bank.png");
	industry_texture = loadTexture("images/Industry.png");
	lab_texture = loadTexture("images/Lab.png");
	man_texture = loadTexture("images/Man.png");
	park_texture = loadTexture("images/Park.png");
	scientist_texture = loadTexture("images/Scientist.png");
	tree_texture = loadTexture("images/Trees.png");
	turbine_texture = loadTexture("images/Turbine.png");
	vehicle_texture = loadTexture("images/Vehicle.png");
	worker_texture = loadTexture("images/Worker.png");


    gTexture = loadTexture("maps/map1.png");


	if(gTexture==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }

	//loading all music for the game:
	// eggy = Mix_LoadWAV( "eggy_splash.wav" );
	// background_music = Mix_LoadMUS("music/inception.wav");
	// bird1 = Mix_LoadWAV("Waltz-music-loop/bird1.wav");
	// bird2 = Mix_LoadWAV("Waltz-music-loop/bird2.wav");
	// if(background_music ==NULL )
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


void Game::range_OptionBar(int xMouse, int yMouse){
	if (xMouse >= 70 && xMouse <= 80 && yMouse > 635){
		// we will make a house from here
		
	}
	else if (xMouse >= 80 && xMouse <= 90 && yMouse > 635){
		// we will make a car from here

	}
	else if (xMouse >= 90 && xMouse <= 100 && yMouse > 635){
		// we will make a factory from here
	
	}
	else if (xMouse >= 100 && xMouse <= 110 && yMouse > 635){
		// we will make a bird from here
	
	}
}

void Game::draw_all(SDL_Renderer * gRenderer){
	SDL_RenderClear(gRenderer); //removes everything from renderer

		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		
		
		if (optionBar->enabled){
			optionBar->draw(gRenderer);
		}

		for( auto i = farms.begin(); i<farms.end(); i++){
			// cout << "this caused" <<endl;
			(*i)->draw(gRenderer);
		}

		if (temp_object!=NULL){
			temp_object->draw(gRenderer);
		}


		
		// SDL_RenderCopy(gRenderer, assets, &src, &mover);//Draws background to renderer
		// (obj).draw(gRenderer);
		SDL_RenderPresent(gRenderer); //displays the updated renderer
}

void Game::select_object_in_optionbar(int xMouse, int yMouse){
	
	int object_to_draw = optionBar->detect_selection(xMouse, yMouse); //this variable stores the int for recognizing the object type <1=farm, 2=building, ....fill it up>
	switch (object_to_draw)
	{
	case 0:
		if(temp_object!=NULL){
			// cout << "here" <<endl;
			delete temp_object;
			temp_object = NULL;
		}
		Farm * newfarm = new Farm(forest_texture);
		newfarm->setCoordinates(xMouse+100, yMouse-100);
		temp_object = newfarm;
		// farms.push_back(newfarm);
		break;
	}
	// case 1: 


}

void Game::hover_object_with_cursor(){
	if(temp_object!=NULL){
		int xMouse, yMouse; 
		SDL_GetMouseState(&xMouse, &yMouse);
		temp_object->setCoordinates(xMouse, yMouse);
	}
}


bool Game::detect_collision(int x, int y){
	// bool Collision = 0;
		// int startingpoint_of_static_object, endingpoint_of_static_object;
	// moving object square

	int sp_of_temp_obj_x = temp_object->getx();
	int sp_of_temp_obj_y = temp_object->gety();
	int ep_of_temp_obj_x = x+temp_object->getw();
	int ep_of_temp_obj_y = y + temp_object->geth();

	//static object
	int sp_of_static_obj_x, sp_of_static_obj_y, ep_of_static_obj_x, ep_of_static_obj_y; 
	
	bool yChecksp = 0;
	bool yCheckep = 0;
	bool xChecksp = 0;
	bool xCheckep = 0;
	for(auto i = farms.begin(); i!= farms.end(); i++){
		sp_of_static_obj_x = (*i)->getx();
		sp_of_static_obj_y = (*i)->gety();
		ep_of_static_obj_x = (*i)->getw() + (*i)->getx();
		ep_of_static_obj_y = (*i)->geth() + (*i)->gety();

		xChecksp = (sp_of_temp_obj_x  >= sp_of_static_obj_x && sp_of_temp_obj_x <= ep_of_static_obj_x);
		xCheckep = (ep_of_temp_obj_x >= sp_of_static_obj_x && ep_of_temp_obj_x <= ep_of_static_obj_x);
		yChecksp = (sp_of_temp_obj_y  >= sp_of_static_obj_y && sp_of_temp_obj_y <= ep_of_static_obj_y);
		yCheckep = (ep_of_temp_obj_y >= sp_of_static_obj_y && ep_of_temp_obj_y <= ep_of_static_obj_y);
		cout <<"xs: " << xChecksp <<endl;
		cout << "xe: "<< xCheckep <<endl;
		cout <<"ys: " << yChecksp <<endl;
		cout << "ye: "<< yCheckep <<endl;

		cout <<"temp: xs: " << sp_of_temp_obj_x <<endl;
		cout << "temp: xe: "<< ep_of_temp_obj_x <<endl;
		cout <<"temp: ys: " << sp_of_temp_obj_y<<endl;
		cout << "temp: ye: "<< ep_of_temp_obj_y <<endl;
		cout <<"static: xs: " << sp_of_static_obj_x <<endl;
		cout << "static: xe: "<< ep_of_static_obj_x <<endl;
		cout <<"static: ys: " << sp_of_static_obj_y<<endl;
		cout << "static: ye: "<< ep_of_static_obj_y <<endl;
		cout << (*i)->geth() <<endl;
		// xCheck = 
		if((xChecksp||xCheckep) && (yChecksp ||yCheckep)){
			
			break;
		}
			

		// cout << "width: "<<(*i)->getw() <<endl;
		// cout << "height: "<<(*i)->geth() <<endl;
		// cout << "x: " << (*i)->getx() <<endl;
		// cout << "y: " <<  (*i)->gety()  <<endl;
		// cout << "Mouse x: " << x << " Mouse y: " << y <<endl;
		// if (x >= (*i)->getx() && x <=  (*i)->getx()+(*i)->getw() ){
		// 	xCollision = 1;
		// }
		// if(y >= (*i)->gety() && y <=  (*i)->gety()+(*i)->geth() ){
		// 	yCollision = 1;
		// }
		// if(obj->getw() + x >= (*i)->getx() && obj->getw() + x<= (*i)->getw() ){
		// 	xCollision = 1;
		// }
		// if(obj->geth() + x >= (*i)->gety() && obj->geth() + x<= (*i)->geth() ){
		// 	yCollision = 1;
		// }


	}
	return ((xCheckep || xChecksp)&&(yCheckep||yChecksp)); 
}

void Game::run( )
{
    SDL_RenderClear( gRenderer );
	//Main loop flag
	bool quit = false;
	bool pause = false;
	bool menuactive = true;


	unsigned int lastTime = 0, currentTime = 0;
	// update_parameters();
	bool option_bar_flag = false; // option is disabled


	//Event handler
	SDL_Event e;
	//main menu running
	// int xMouse, yMouse;
	bool click; 
	// while(menuactive){
	// 	// if (true){
			
	// 	currentTime = SDL_GetTicks();
	// 	cout<< "Main menu running "<< currentTime / 1000 << " seconds." << endl;



	

	// 	//check for keyboard event
	// 	while( SDL_PollEvent( &e ) != 0 ){
	// 		if( Mix_PlayingMusic() == 0 )
	// 		{
	// 			//Play the music
	// 			Mix_PlayMusic( background_music, 1 );
	// 		}
	// 		if( e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
	// 		{
	// 			menuactive = false;
	// 			break;
	// 		}
			
	// 		SDL_GetMouseState(&xMouse,&yMouse);
	// 		// cout << "xMouse: " << xMouse <<endl;
	// 		// cout << "yMouse: " << yMouse <<endl;

	// 		SDL_RenderClear(gRenderer); //removes everything from renderer
			
	// 		if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT){
	// 			click =1;
	// 		}
	// 		menu.refresh(gRenderer, xMouse, yMouse, click);
	// 		SDL_RenderPresent(gRenderer);
	// 		click =0;

	// 	}
	// }

	//While application is running
	while( !quit )
	{
		//play the background music

		currentTime = SDL_GetTicks();
		cout<< "Game running "<< currentTime / 1000 << " seconds." << endl;
		
		
		if( Mix_PlayingMusic() == 0 )
		{
			//Play the music
			// Mix_PlayMusic( background_music, 1 );
		}		
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYDOWN))
			{
				
				quit = true;
				break;
			}
			//user requests pause
			// if (e.type==SDL_KEYDOWN ){
			// 	if (e.key.keysym.sym == SDLK_p){
			// 		pause = !pause;
			// 		if(pause){ //pause the music 
			// 			Mix_PauseMusic();
			// 		}
			// 		else{ //play the music
			// 			Mix_ResumeMusic();
			// 		}
			// 	}

			// }
			//checking mouse clicks
			if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT &&!pause){
				
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);

				cout << xMouse << " " << yMouse <<endl;
				//checking for option bar
				if (optionBar->enabled){
					select_object_in_optionbar(xMouse, yMouse);
					
				}
				//toggling option_bar
				if (xMouse >SCREEN_WIDTH-80 && yMouse >SCREEN_HEIGHT-80  && !optionBar->enabled){ // to enable option bar when clicked at a specific point
					optionBar->enabled = true; // option bar is enabled
				}
				else if (xMouse >SCREEN_WIDTH-80 && yMouse >SCREEN_HEIGHT-80 && optionBar->enabled){ // to disable option bar
					optionBar->enabled = false; // option bar is disabled
				}

				//fix the object if the user clicks on the map with the object selected:
				if(temp_object!=NULL && yMouse < SCREEN_HEIGHT - 300  &&  !detect_collision( xMouse, yMouse)){
					
					if (temp_object->name == "farm"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Farm * myfarm = dynamic_cast<Farm *>(temp_object);
						myfarm->setCoordinates(xMouse, yMouse);
						farms.push_back(myfarm);
						temp_object = NULL;
					}
					//check other objects here!
					else if (temp_object->name == "bird"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Bird * mybird = dynamic_cast<Bird *>(temp_object);
						mybird->setCoordinates(xMouse, yMouse);
						birds.push_back(mybird);
						temp_object = NULL;
					}
					
					else if (temp_object->name == "building"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Building * mybuilding = dynamic_cast<Building *>(temp_object);
						mybuilding->setCoordinates(xMouse, yMouse);
						buildings.push_back(mybuilding);
						temp_object = NULL;
					}

					else if (temp_object->name == "house"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						House * myhouse = dynamic_cast<House *>(temp_object);
						myhouse->setCoordinates(xMouse, yMouse);
						houses.push_back(myhouse);
						temp_object = NULL;
					}

					else if (temp_object->name == "industry"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Industry * myindustry = dynamic_cast<Industry *>(temp_object);
						myindustry->setCoordinates(xMouse, yMouse);
						industries.push_back(myindustry);
						temp_object = NULL;
					}

					else if (temp_object->name == "laboratory"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Laboratory * mylaboratory = dynamic_cast<Laboratory *>(temp_object);
						mylaboratory->setCoordinates(xMouse, yMouse);
						laboratories.push_back(mylaboratory);
						temp_object = NULL;
					}

					else if (temp_object->name == "park"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Park * mypark = dynamic_cast<Park *>(temp_object);
						mypark->setCoordinates(xMouse, yMouse);
						parks.push_back(mypark);
						temp_object = NULL;
					}

					else if (temp_object->name == "scientist"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Scientist * myscientist = dynamic_cast<Scientist *>(temp_object);
						myscientist->setCoordinates(xMouse, yMouse);
						scientists.push_back(myscientist);
						temp_object = NULL;
					}

					else if (temp_object->name == "solarpanel"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						SolarPanel * mysolarpanel = dynamic_cast<SolarPanel *>(temp_object);
						mysolarpanel->setCoordinates(xMouse, yMouse);
						solarpanels.push_back(mysolarpanel);
						temp_object = NULL;
					}

					else if (temp_object->name == "tree"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Tree * mytree = dynamic_cast<Tree *>(temp_object);
						mytree->setCoordinates(xMouse, yMouse);
						trees.push_back(mytree);
						temp_object = NULL;
					}

					else if (temp_object->name == "vehicle"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Vehicle * myvehicle = dynamic_cast<Vehicle *>(temp_object);
						myvehicle->setCoordinates(xMouse, yMouse);
						vehicles.push_back(myvehicle);
						temp_object = NULL;
					}

					else if (temp_object->name == "worker"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Worker * myworker = dynamic_cast<Worker *>(temp_object);
						myworker->setCoordinates(xMouse, yMouse);
						workers.push_back(myworker);
						temp_object = NULL;
					}
				}

			}
			//checking mouse hovering
			hover_object_with_cursor();


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
				
				// }

			// }
			
		}
		if (!pause){

			// cout << "here" <<endl;
            draw_all(gRenderer);
		}
		SDL_Delay(120);	//causes sdl engine to delay for specified miliseconds

	}
}
