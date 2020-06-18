#include "game.hpp"
#include<iostream>
#include <typeinfo>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
#include<list>

// int main_cash = 10000; // dollars
int electricity = 250; // MegaWatts
int XP_level = 0;
int P_level = 1; // first level

void Game::update_parameters(){
	// Objects : 1. birds - 2. building - 3. farm - 4. house - 5. laboratory - 6. industry - 7. park - 8. vehicle 
	// - 9. worker - 10. scientist.
	// cout<<"Updating parameters :-)"<<endl;
	// main_cash = 10000; // dollars
	// int electricity = 250; // MegaWatts
	// int XP_level = 0;
	// int P_level = 1; // first level
	// int money = 10000; // dollars
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
			main_cash += 10000;
			cout<<"Welcome to level "<<P_level<<" !"<<endl;
		}
		cout<<"Main Cash : "<<main_cash<<endl;
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
	optionBar = new OptionBar(loadTexture("bars/Shop.png"));

	//loading top bar:
	topbar = new Topbar(loadTexture("bars/Top_Menu.png")); //main top bar sprite
	//now load the statics sprites on the topbar;

	// for(int i=0; i<4; i++){
	spritename = "";
	spritename = "bars/scorebar/Empty.png";
	cout << spritename <<endl; 
	topbar->add_static_sprite(loadTexture(spritename), -1); 
	// }
	for(int i=0; i<4; i++){
		spritename = "";
		spritename = "bars/scorebar/" + to_string(i+1) + "_Pink.png";
		cout << spritename <<endl; 
		topbar->add_static_sprite(loadTexture(spritename), 0); 
	}
	for(int i=0; i<4; i++){
		spritename = "";
		spritename = "bars/scorebar/" + to_string(i+1) + "_Gold.png";
		cout << spritename <<endl; 
		topbar->add_static_sprite(loadTexture(spritename), 1); 
	}
	for(int i=0; i<4; i++){
		spritename = "";
		spritename = "bars/scorebar/" + to_string(i+1) + "_Green.png";
		cout << spritename <<endl; 
		topbar->add_static_sprite(loadTexture(spritename), 2); 
	}
	for(int i=0; i<4; i++){
		spritename = "";
		spritename = "bars/scorebar/" + to_string(i+1) + "_Blue.png";
		cout << spritename <<endl; 
		topbar->add_static_sprite(loadTexture(spritename), 3); 
	}

	// topbar->add_static_sprite(loadTexture("bars/scorebar/Scores.png"));

	



	//loading other sprites

	// assets = loadTexture("images/car-front-02.svg");

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
	scientist_texture = loadTexture("images/Scientist.png");

	//create scientist object;
	scientist_obj = new Scientist(scientist_texture);

    gTexture = loadTexture("maps/map1.png");
	map_texture = loadTexture("maps/test_map.png");

	if(map_texture!=NULL){
		map = new Map(map_texture);
	}
	
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
	// SDL_DestroyTexture(assets);
	// assets=NULL;
	SDL_DestroyTexture(gTexture);
	//free sound:
	delete optionBar;
	delete topbar;

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

		map->draw(gRenderer);
		// SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		
	
		

		for( auto i = farms.begin(); i<farms.end(); i++){
			// cout << "this caused" <<endl;
			(*i)->draw(gRenderer);
		}
		for( auto i = banks.begin(); i<banks.end(); i++){
			// cout << "this caused" <<endl;
			(*i)->draw(gRenderer);
		}
		for( auto i = houses.begin(); i<houses.end(); i++){
			// cout << "this caused" <<endl;
			(*i)->draw(gRenderer);
		}
		for( auto i = laboratories.begin(); i<laboratories.end(); i++){
			// cout << "this caused" <<endl;
			(*i)->draw(gRenderer);
		}
		for( auto i = industries.begin(); i<industries.end(); i++){
			// cout << "this caused" <<endl;
			(*i)->draw(gRenderer);
		}
		for( auto i = parks.begin(); i<parks.end(); i++){
			// cout << "this caused" <<endl;
			(*i)->draw(gRenderer);
		}
		for( auto i = trees.begin(); i<trees.end(); i++){
			// cout << "this caused" <<endl;
			(*i)->draw(gRenderer);
		}
		for( auto i = solarpanels.begin(); i<solarpanels.end(); i++){
			// cout << "this caused" <<endl;
			(*i)->draw(gRenderer);
		}
		for( auto i = vehicles.begin(); i<vehicles.end(); i++){
			// cout << "this caused" <<endl;
			(*i)->draw(gRenderer);
		}
		for( auto i = workers.begin(); i<workers.end(); i++){
			// cout << "this caused" <<endl;
			(*i)->draw(gRenderer);
		}
		if (temp_object!=NULL){
			temp_object->draw(gRenderer);
		}


		if (optionBar->enabled){
			optionBar->draw(gRenderer);
		}
		topbar->draw(gRenderer);
		
		// SDL_RenderCopy(gRenderer, assets, &src, &mover);//Draws background to renderer
		// (obj).draw(gRenderer);
		SDL_RenderPresent(gRenderer); //displays the updated renderer
}

void Game::select_object_in_optionbar(int xMouse, int yMouse){
	
	int object_to_draw = optionBar->detect_selection(xMouse, yMouse); //this variable stores the int for recognizing the object type <1=farm, 2=building, ....fill it up>
	//0->
	switch (object_to_draw)
	{
		case 0:
			{
			if(temp_object!=NULL){
				// cout << "here" <<endl;
				delete temp_object;
				temp_object = NULL;
			}
			Industry * newindustry = new Industry(industry_texture);
			newindustry->setCoordinates(xMouse+100, yMouse-100);
			temp_object = newindustry;
			// farms.push_back(newfarm);
			break;
			}

	case 1:
		{
		if(temp_object!=NULL){
			// cout << "here" <<endl;
			delete temp_object;
			temp_object = NULL;
		}
		Bank * newobject = new Bank(bank_texture);
		newobject->setCoordinates(xMouse+100, yMouse-100);
		temp_object = newobject;
		// farms.push_back(newfarm);
		break;
		}

		case 2:
			{
			if(temp_object!=NULL){
				// cout << "here" <<endl;
				delete temp_object;
				temp_object = NULL;
			}
			Laboratory * newlaboratory = new Laboratory(lab_texture);
			newlaboratory->setCoordinates(xMouse+100, yMouse-100);
			temp_object = newlaboratory;
			// farms.push_back(newfarm);
			break;
			}

		case 3:
			{
			if(temp_object!=NULL){
				// cout << "here" <<endl;
				delete temp_object;
				temp_object = NULL;
			}
			House * newhouse = new House(house_texture);
			newhouse->setCoordinates(xMouse+100, yMouse-100);
			temp_object = newhouse;
			// farms.push_back(newfarm);
			break;
			}

		case 4:
			{
			if(temp_object!=NULL){
				// cout << "here" <<endl;
				delete temp_object;
				temp_object = NULL;
			}
			Park * newpark = new Park(park_texture);
			newpark->setCoordinates(xMouse+100, yMouse-100);
			temp_object = newpark;
			// farms.push_back(newfarm);
			break;
			}

		case 5:
			{
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

		case 6:
			{
			if(temp_object!=NULL){
				// cout << "here" <<endl;
				delete temp_object;
				temp_object = NULL;
			}
			Tree * newtree = new Tree(tree_texture);
			newtree->setCoordinates(xMouse+100, yMouse-100);
			temp_object = newtree;
			// farms.push_back(newfarm);
			break;
			}

	case 7:
		{
		if(temp_object!=NULL){
			// cout << "here" <<endl;
			delete temp_object;
			temp_object = NULL;
		}
		Vehicle * newvehicle = new Vehicle(vehicle_texture);
		newvehicle->setCoordinates(xMouse+100, yMouse-100);
		temp_object = newvehicle;
		// farms.push_back(newfarm);
		break;
		}

	case 8:
		{
		if(temp_object!=NULL){
			// cout << "here" <<endl;
			delete temp_object;
			temp_object = NULL;
		}
		Turbine * newturbine = new Turbine(turbine_texture);
		newturbine->setCoordinates(xMouse+100, yMouse-100);
		temp_object = newturbine;
		// farms.push_back(newfarm);
		break;
		}
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
		// cout <<"xs: " << xChecksp <<endl;
		// cout << "xe: "<< xCheckep <<endl;
		// cout <<"ys: " << yChecksp <<endl;
		// cout << "ye: "<< yCheckep <<endl;

		// cout <<"temp: xs: " << sp_of_temp_obj_x <<endl;
		// cout << "temp: xe: "<< ep_of_temp_obj_x <<endl;
		// cout <<"temp: ys: " << sp_of_temp_obj_y<<endl;
		// cout << "temp: ye: "<< ep_of_temp_obj_y <<endl;
		// cout <<"static: xs: " << sp_of_static_obj_x <<endl;
		// cout << "static: xe: "<< ep_of_static_obj_x <<endl;
		// cout <<"static: ys: " << sp_of_static_obj_y<<endl;
		// cout << "static: ye: "<< ep_of_static_obj_y <<endl;
		// cout << (*i)->geth() <<endl;
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



void Game::scroll_objects(bool xL,bool  xR, bool yU, bool yD){
	for(auto i = farms.begin(); i!=farms.end(); i++){
		if (xL){
			(*i)->setCoordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->setCoordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}

	for(auto i = houses.begin(); i!=houses.end(); i++){
		if (xL){
			(*i)->setCoordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->setCoordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}
	for(auto i = laboratories.begin(); i!=laboratories.end(); i++){
		if (xL){
			(*i)->setCoordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->setCoordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}
	for(auto i = industries.begin(); i!=industries.end(); i++){
		if (xL){
			(*i)->setCoordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->setCoordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}
	for(auto i = parks.begin(); i!=parks.end(); i++){
		if (xL){
			(*i)->setCoordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->setCoordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}
	for(auto i = trees.begin(); i!=trees.end(); i++){
		if (xL){
			(*i)->setCoordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->setCoordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}

	for(auto i = solarpanels.begin(); i!=solarpanels.end(); i++){
		if (xL){
			(*i)->setCoordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->setCoordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}

	for(auto i = vehicles.begin(); i!=vehicles.end(); i++){
		if (xL){
			(*i)->setCoordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->setCoordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}
	for(auto i = workers.begin(); i!=workers.end(); i++){
		if (xL){
			(*i)->setCoordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->setCoordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->setCoordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}


}

void Game::run( )
{
    SDL_RenderClear( gRenderer );
	//Main loop flag
	bool quit = false;
	bool pause = false;
	bool menuactive = true;

	cout<<"Main Cash : "<<main_cash<<endl;
	cout<<"XP_level : "<<XP_level<<endl;
	cout<<"Player level : "<<P_level<<endl;

	unsigned int lastTime = 0, currentTime = 0;
	// update_parameters();
	// cout<<"calling update parameters." << endl;
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
		// cout<< "Game running "<< currentTime / 1000 << " seconds." << endl;
		
		
		if( Mix_PlayingMusic() == 0 )
		{
			//Play the music
			// Mix_PlayMusic( background_music, 1 );
		}		
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			// updating scores
			if (XP_level/150 >= 1){
				XP_level -= 150;
				P_level += 1;
				main_cash += 10000;
				cout<<"Welcome to level "<<P_level<<" !"<<endl;
			}
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
			//scrolling the map!:
			if(e.type == SDL_KEYDOWN){
				switch (e.key.keysym.sym)
				{
				case SDLK_RIGHT:
						if(map->scrolling_flag(0, 1, 0, 0)){
							scroll_objects(1, 0, 0, 0); //scroll the object opposite to the map!
							map->scroll(0, 1, 0, 0);
						}
							
					break;
				case SDLK_LEFT:
						if(map->scrolling_flag(1, 0, 0, 0))
						{
							scroll_objects(0, 1, 0, 0);
							map->scroll(1, 0, 0, 0);
						}
					break;
				case SDLK_UP:
						cout << "upper pressed" <<endl;
						if(map->scrolling_flag(0,0,1,0)){
							scroll_objects(0, 0, 0, 1);
							map->scroll(0,0,1,0);
						}
					break;
						

				case SDLK_DOWN:
						if(map->scrolling_flag(0,0,0,1)){
							scroll_objects(0, 0, 1, 0);
							map->scroll(0,0,0,1);
						}
					break;
				default:
					break;
				}
			}


			//checking mouse clicks
			if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT &&!pause){
				
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);

				// cout << xMouse << " " << yMouse <<endl;
				//checking for option bar
				if (optionBar->enabled){
					select_object_in_optionbar(xMouse, yMouse);
					
				}
				//toggling option_bar
				if (xMouse >SCREEN_WIDTH-80 && yMouse < 80  && !optionBar->enabled){ // to enable option bar when clicked at a specific point
					optionBar->enabled = true; // option bar is enabled
				}
				else if (xMouse >SCREEN_WIDTH-80 && yMouse < 80 && optionBar->enabled){ // to disable option bar
					optionBar->enabled = false; // option bar is disabled
				}

				//fix the object if the user clicks on the map with the object selected:
				if(temp_object!=NULL && yMouse < SCREEN_HEIGHT - 300  &&  !detect_collision( xMouse, yMouse)){
					
					// make individual class functions to update cash and XP_level
					// industry and lab chezein bnaein unsy paisay mileingy
					// industry product ki progress front end py show krni h
					if (temp_object->name == "farm"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Farm * myfarm = dynamic_cast<Farm *>(temp_object);
						myfarm->setCoordinates(xMouse, yMouse);
						myfarm->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for farm
						farms.push_back(myfarm);
						temp_object = NULL;
					}
					//check other objects here!
					else if (temp_object->name == "bird"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Bird * mybird = dynamic_cast<Bird *>(temp_object);
						mybird->setCoordinates(xMouse, yMouse);
						mybird->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for bird
						birds.push_back(mybird);
						temp_object = NULL;
					}
					
					else if (temp_object->name == "building"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Building * mybuilding = dynamic_cast<Building *>(temp_object);
						mybuilding->setCoordinates(xMouse, yMouse);
						mybuilding->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for building
						buildings.push_back(mybuilding);
						temp_object = NULL;
					}

					else if (temp_object->name == "bank"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Bank * mybank = dynamic_cast<Bank *>(temp_object);
						mybank->setCoordinates(xMouse, yMouse);
						mybank->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for bank
						banks.push_back(mybank);
						temp_object = NULL;
					}

					else if (temp_object->name == "house"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						House * myhouse = dynamic_cast<House *>(temp_object);
						myhouse->setCoordinates(xMouse, yMouse);
						myhouse->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for house
						houses.push_back(myhouse);
						temp_object = NULL;
					}

					else if (temp_object->name == "industry"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Industry * myindustry = dynamic_cast<Industry *>(temp_object);
						myindustry->setCoordinates(xMouse, yMouse);
						myindustry->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for industryt
						industries.push_back(myindustry);
						temp_object = NULL;
					}

					else if (temp_object->name == "laboratory"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Laboratory * mylaboratory = dynamic_cast<Laboratory *>(temp_object);
						mylaboratory->setCoordinates(xMouse, yMouse);
						mylaboratory->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for laboratory
						laboratories.push_back(mylaboratory);
						temp_object = NULL;
					}

					else if (temp_object->name == "park"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Park * mypark = dynamic_cast<Park *>(temp_object);
						mypark->setCoordinates(xMouse, yMouse);
						mypark->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for park
						parks.push_back(mypark);
						temp_object = NULL;
					}

					else if (temp_object->name == "scientist"){
						cout<< detect_collision( xMouse, yMouse) <<endl;

						Scientist * myscientist = dynamic_cast<Scientist *>(temp_object);
						myscientist->setCoordinates(xMouse, yMouse);
						myscientist->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for scientist
						scientists.push_back(myscientist);
						scientist_obj->increase_scientist();
						scientist_obj->show_scientist_count();
						temp_object = NULL;
					}

					else if (temp_object->name == "solarpanel"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						SolarPanel * mysolarpanel = dynamic_cast<SolarPanel *>(temp_object);
						mysolarpanel->setCoordinates(xMouse, yMouse);
						mysolarpanel->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for solarpanel
						solarpanels.push_back(mysolarpanel);
						temp_object = NULL;
					}

					else if (temp_object->name == "tree"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Tree * mytree = dynamic_cast<Tree *>(temp_object);
						mytree->setCoordinates(xMouse, yMouse);
						mytree->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for tree
						trees.push_back(mytree);
						temp_object = NULL;
					}

					else if (temp_object->name == "turbine"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Turbine * myturbine = dynamic_cast<Turbine *>(temp_object);
						myturbine->setCoordinates(xMouse, yMouse);
						myturbine->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for turbine
						turbines.push_back(myturbine);
						temp_object = NULL;
					}

					else if (temp_object->name == "vehicle"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Vehicle * myvehicle = dynamic_cast<Vehicle *>(temp_object);
						myvehicle->setCoordinates(xMouse, yMouse);
						myvehicle->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for vehicle
						vehicles.push_back(myvehicle);
						temp_object = NULL;
					}

					else if (temp_object->name == "worker"){
						cout<< detect_collision( xMouse, yMouse) <<endl;
						Worker * myworker = dynamic_cast<Worker *>(temp_object);
						myworker->setCoordinates(xMouse, yMouse);
						myworker->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for worker
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
	cout<< "Total number of laboratories in the city : "<< laboratories.size()<<endl;
	cout<<"END"<<endl;
	cout<<"Main Cash : "<<main_cash<<endl;
	cout<<"XP_level : "<<XP_level<<endl;
	cout<<"Player level : "<<P_level<<endl;
}