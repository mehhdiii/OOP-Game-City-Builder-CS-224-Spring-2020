#include "game.hpp"
#include<iostream>
#include <typeinfo>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
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
		gWindow = SDL_CreateWindow( "City Builder", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				//initialize audio
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
				//intialize text
				if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
			}
		}
	}

	return success;
}
bool Game::loadMenu(){
	bool success = true;
	int menu_sprite_range = 6;
	string spritename;
	SDL_Texture * tex = NULL;
	//loading mainmenu
	for(int i=1; i<=menu_sprite_range; i++){
		spritename = "";
		spritename = "mainmenu/Main_Menu_" + to_string(i) + ".png";
		cout << spritename <<endl; 
		tex = loadTexture(spritename);
		if (tex!=NULL){
			menu->add_sprite(tex, 0); 
		}
		else{
			success = false;
		}
	}
	//loading map menu
	for(int i=1; i<=menu_sprite_range; i++){
		spritename = "";
		spritename = "mainmenu/Select_Map_" + to_string(i) + ".png";
		cout << spritename <<endl; 
		tex = loadTexture(spritename);
		if(tex!= NULL){
			menu->add_sprite(tex, 1); 
		}
		else{
			success = false;
		}
		
	}
	menu_sprite_range = 4;
	for(int i =1; i<=menu_sprite_range;i++){
		spritename = "";
		spritename = "mainmenu/Select_Player_" + to_string(i) + ".png";
		cout << spritename <<endl; 
		tex = loadTexture(spritename);
		if(tex!=NULL){
			menu->add_sprite(tex, 2); 
		}
		else{
			cout <<"failed to load texture" <<endl;
			success = false;
		}
	}
	menu_sprite_range = 2;
	for(int i = 1; i<=menu_sprite_range; i++){
		spritename = "";
		spritename = "mainmenu/credits_" + to_string(i) + ".png";
		tex = loadTexture(spritename);
		if(tex!=NULL){
			menu->add_sprite(tex, 3);
		}
		else{
			success= false;
		}
	}
	menu_sprite_range = 4;
	for(int i = 1; i<=menu_sprite_range; i++){
		spritename = "";
		spritename = "mainmenu/settings_" + to_string(i) + ".png";
		tex = loadTexture(spritename);
		if(tex!=NULL){
			menu->add_sprite(tex, 4);
		}
		else{
			success= false;
		}
	}
	
	menu_sprite_range = 2;
	for(int i = 1; i<=menu_sprite_range; i++){
		spritename = "";
		spritename = "mainmenu/back_" + to_string(i) + ".png";
		tex = loadTexture(spritename);
		if(tex!=NULL){
			menu->add_sprite(tex, 4);
		}
		else{
			success= false;
		}
	}	
	success = sound.load_menu_background_music();
	success = sound.load_all_SFX_music();
	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	SDL_Texture * tex = NULL;
	//Open the font
    gFont = TTF_OpenFont( "fonts/EvilEmpire-4BBVK.ttf", 28 );
    if( gFont == NULL )
    {
        printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
	//loading option bar:
	tex = loadTexture("bars/Shop_new.png");
	if(tex!=NULL){
		optionBar = new OptionBar(tex);
	}
	else{
		printf("Unable to load texture");
		success= false;
	}
	//loading top bar:
	tex = loadTexture("bars/Top_Bar_new.png");
	if(tex!=NULL){
		cout << "checking for initialization" <<(gFont==NULL) <<endl;
		topbar = new Topbar(tex); //main top bar sprite
	}
	else{
		success = false;
		printf("Unable to load texture");
	}
	//now load the statics sprites on the topbar;
	string spritename = "";
	
	for(int i=0; i<5; i++){
		spritename = "";
		spritename = "bars/Scores/" + to_string(i+1) + "_Pink.png";
		cout << spritename <<endl; 
		tex = loadTexture(spritename);
		if(tex!=NULL){
			topbar->add_static_sprite(tex, 0); 
		}
		else{
			success = false;
			printf("Unable to load texture");
		}
	}
	for(int i=0; i<5; i++){
		spritename = "";
		spritename = "bars/Scores/" + to_string(i+1) + "_Gold.png";
		cout << spritename <<endl; 
		tex = loadTexture(spritename);
		if(tex!=NULL){
			topbar->add_static_sprite(tex, 1); 
		}
		else{
			success = false;
			printf("Unable to load texture");
		}
		
	}
	for(int i=0; i<5; i++){
		spritename = "";
		spritename = "bars/Scores/" + to_string(i+1) + "_Green.png";
		cout << spritename <<endl; 
		tex = loadTexture(spritename);
		if(tex!=NULL){
			topbar->add_static_sprite(tex, 2); 
		}
		else{
			success = false;
			printf("Unable to load texture");
		}
		
	}
	for(int i=0; i<5; i++){
		spritename = "";
		spritename = "bars/Scores/" + to_string(i+1) + "_Blue.png";
		cout << spritename <<endl; 
		tex = loadTexture(spritename);
		if(tex != NULL){
			topbar->add_static_sprite(tex, 3);
		}
		else{
			success = false;
			printf("Unable to load texture");
		}
		 
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
	if(forest_texture==NULL||house_texture==NULL||bank_texture==NULL||industry_texture==NULL||lab_texture==NULL||man_texture==NULL||park_texture==NULL||scientist_texture==NULL||tree_texture==NULL||turbine_texture==NULL||vehicle_texture==NULL||worker_texture==NULL){
		success = false;
		printf("Unable to load texture");
	}

	scientist_texture = loadTexture("images/Scientist.png");

	//create scientist object;
	if(scientist_texture!=NULL){
		scientist_obj = new Scientist(scientist_texture);
	}
	else{
		success = false;
		printf("Unable to load texture");
	}
	

    gTexture = loadTexture("maps/test_map.png");
	
	//checking which map to load and then loading that respective map:
	spritename = "";
	spritename = "maps/map" + to_string(menu->get_selected_map()) + ".png";
	map_texture = loadTexture(spritename);

	if(map_texture!=NULL){
		map = new Map(map_texture);
	}
	else{
		success = false;
		printf("Unable to load texture");
	}
	map->add_grid_point(); //adding grids to the map

	
    // else
    // {
    //     //Render text
    //     SDL_Color textColor = { 0, 0, 0 };
    //     if( !gTextTexture.loadFromRenderedText( "The quick brown fox jumps over the lazy dog", textColor ) )
    //     {
    //         printf( "Failed to render text texture!\n" );
    //         success = false;
    //     }
    // }
	
	// if(gTexture==NULL || gTexture==NULL)
    // {
    //     printf("Unable to run due to error: %s\n",SDL_GetError());
    //     success =false;
    // }

	//loading all music for the game:

	// eggy = Mix_LoadWAV( "eggy_splash.wav" );
	success = sound.load_game_background_music();
	// game_background_music = Mix_LoadMUS("game_sounds/Game_Background.wav");
	// bird1 = Mix_LoadWAV("Waltz-music-loop/bird1.wav");
	// // bird2 = Mix_LoadWAV("Waltz-music-loop/bird2.wav");
	// if(game_background_music ==NULL )
	// {
	// 	cout<<"back ground music loading failed"<<endl;
	// 	printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
	// 	success = false;
	// }
	// cout<<"back ground music loading sccessful"<<endl;

	return success;
}

void Game::close()
{
	
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

		// cout<< "User has given input "<<input_from_user<<endl;
		if (XP_level/200 >= 1){
			XP_level -= 200;
			P_level += 1;
			main_cash += 10000;
			// cout<<"Welcome to level "<<P_level<<" !"<<endl;
		}
		// cout<<"Main Cash : "<<main_cash<<endl;
		// cout<<"XP_level : "<<XP_level<<endl;
		// cout<<"Player level : "<<P_level<<endl;
	}

}



template<typename Mytype>
void Game::Coordinate_sorting(vector<Mytype> &vec){
	

	sort(vec.begin(), vec.end(), sortbyC<Mytype>());
}


void Game::draw_all(SDL_Renderer * gRenderer){
	SDL_RenderClear(gRenderer); //removes everything from renderer

		green_energy = 0;
			

		map->draw(gRenderer);
		// SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		


		//sort all objects wrt their y coordines using the template coordinatesorting
		Coordinate_sorting(all_objects);
		for(auto i = all_objects.begin(); i!=all_objects.end(); i++){

			(*i)->draw(gRenderer);
		}

		// for( auto i = farms.begin(); i<farms.end(); i++){
		// 	// cout << "this caused" <<endl;
		// 	(*i)->draw(gRenderer);
		// }
		// for( auto i = banks.begin(); i<banks.end(); i++){
		// 	// cout << "this caused" <<endl;
		// 	(*i)->draw(gRenderer);
		// }
		// for( auto i = houses.begin(); i<houses.end(); i++){
		// 	// cout << "this caused" <<endl;
		// 	(*i)->draw(gRenderer);
		// }
		// for( auto i = laboratories.begin(); i<laboratories.end(); i++){
		// 	// cout << "this caused" <<endl;
		// 	(*i)->draw(gRenderer);
		// }
		for( auto i = industries.begin(); i<industries.end(); i++){
			// cout << "this caused" <<endl;
			// (*i)->draw(gRenderer);
			green_energy += (*i)->get_green_energy();
		}
		// for( auto i = parks.begin(); i<parks.end(); i++){
		// 	// cout << "this caused" <<endl;
		// 	(*i)->draw(gRenderer);
		// }
		// for( auto i = trees.begin(); i<trees.end(); i++){
		// 	// cout << "this caused" <<endl;
		// 	(*i)->draw(gRenderer);
		// }
		// for( auto i = solarpanels.begin(); i<solarpanels.end(); i++){
		// 	// cout << "this caused" <<endl;
		// 	(*i)->draw(gRenderer);
		// }
		// for( auto i = vehicles.begin(); i<vehicles.end(); i++){
		// 	// cout << "this caused" <<endl;
		// 	(*i)->draw(gRenderer);
		// }
		// for( auto i = workers.begin(); i<workers.end(); i++){
		// 	// cout << "this caused" <<endl;
		// 	(*i)->draw(gRenderer);
		// }
		// for(auto i = turbines.begin(); i<turbines.end(); i++){
		// 	(*i)->draw(gRenderer);
		// }
		if (temp_object!=NULL){
			temp_object->draw(gRenderer);
		}


		if (optionBar->enabled){
			optionBar->draw(gRenderer);
		}
		// topbar->draw(gRenderer);
		topbar->draw_modified(gRenderer, main_cash,XP_level, P_level, green_energy);
		// SDL_RenderCopy(gRenderer, assets, &src, &mover);//Draws background to renderer
		// (obj).draw(gRenderer);
		// texts_object.setCoordinates(140, 9);
		// texts_object.draw(gRenderer); 
		SDL_RenderPresent(gRenderer); //displays the updated renderer
}

void Game::select_object_in_optionbar(int xMouse, int yMouse){
	
	int object_to_draw = optionBar->detect_selection(xMouse, yMouse); //this variable stores the int for recognizing the object type <1=farm, 2=building, ....fill it up>
	//0->
	switch (object_to_draw)
	{
		case 0:

			{
				if (main_cash >= 2500){
					if(temp_object!=NULL){
						// cout << "here" <<endl;
						delete temp_object;
						temp_object = NULL;
					}
					Industry * newindustry = new Industry(industry_texture);
					newindustry->setCoordinates(xMouse+100, yMouse-100);
					temp_object = newindustry;
					// farms.push_back(newfarm);
				}
				else{
					cout<< "You do not have enough cash to buy an industry."<<endl;
				}
			break;
			}
			

	case 1:
		{
			if (main_cash >= 1500){
				if(temp_object!=NULL){
					// cout << "here" <<endl;
					delete temp_object;
					temp_object = NULL;
				}
				Bank * newobject = new Bank(bank_texture);
				newobject->setCoordinates(xMouse+100, yMouse-100);
				temp_object = newobject;
				// farms.push_back(newfarm);
			}
			else{
				cout<< "You do not have enough cash to buy a bank."<<endl;
			}
		break;
		}

		case 2:
			{
				if (main_cash>=2000){
					if(temp_object!=NULL){
						// cout << "here" <<endl;
						delete temp_object;
						temp_object = NULL;
					}
					Laboratory * newlaboratory = new Laboratory(lab_texture);
					newlaboratory->setCoordinates(xMouse+100, yMouse-100);
					temp_object = newlaboratory;
					// farms.push_back(newfarm);
				}
				else{
					cout<< "You do not have enough cash to buy a laboratory."<<endl;
				}
			break;
			}

		case 3:
			{
				if (main_cash>=650){
					if(temp_object!=NULL){
						// cout << "here" <<endl;
						delete temp_object;
						temp_object = NULL;
					}
					House * newhouse = new House(house_texture);
					newhouse->setCoordinates(xMouse+100, yMouse-100);
					temp_object = newhouse;
					// farms.push_back(newfarm);
				}
				else{
					cout<< "You do not have enough cash to buy a house."<<endl;
				}
			break;
			}

		case 4:
			{
				if (main_cash>=600){
					if(temp_object!=NULL){
						// cout << "here" <<endl;
						delete temp_object;
						temp_object = NULL;
					}
					Park * newpark = new Park(park_texture);
					newpark->setCoordinates(xMouse+100, yMouse-100);
					temp_object = newpark;
					// farms.push_back(newfarm);
				}
				else{
					cout<< "You do not have enough cash to buy a park."<<endl;
				}
			break;
			}

		case 5:
			{
				if (main_cash>=550){
					if(temp_object!=NULL){
						// cout << "here" <<endl;
						delete temp_object;
						temp_object = NULL;
					}
					Farm * newfarm = new Farm(forest_texture);
					newfarm->setCoordinates(xMouse+100, yMouse-100);
					temp_object = newfarm;
					// farms.push_back(newfarm);
				}
				else{
					cout<< "You do not have enough cash to buy a farm."<<endl;
				}
			break;
			}

		case 6:
			{
				if (main_cash>=500){
					if(temp_object!=NULL){
						// cout << "here" <<endl;
						delete temp_object;
						temp_object = NULL;
					}
					Tree * newtree = new Tree(tree_texture);
					newtree->setCoordinates(xMouse+100, yMouse-100);
					temp_object = newtree;
					// farms.push_back(newfarm);
				}
				else{
					cout<< "You do not have enough cash to buy a tree."<<endl;
				}
			break;
			}

	case 7:
		{
			if (main_cash>=300){
				if(temp_object!=NULL){
					// cout << "here" <<endl;
					delete temp_object;
					temp_object = NULL;
				}
				Vehicle * newvehicle = new Vehicle(vehicle_texture);
				newvehicle->setCoordinates(xMouse+100, yMouse-100);
				temp_object = newvehicle;
				// farms.push_back(newfarm);
			}
			else{
				cout<< "You do not have enough cash to buy a vehicle."<<endl;
			}
		break;
		}

	case 8:
		{
			if (main_cash>=2500){
				if(temp_object!=NULL){
					// cout << "here" <<endl;
					delete temp_object;
					temp_object = NULL;
				}
				Turbine * newturbine = new Turbine(turbine_texture);
				newturbine->setCoordinates(xMouse+100, yMouse-100);
				temp_object = newturbine;
				// farms.push_back(newfarm);
			}
			else{
				cout<< "You do not have enough cash to buy a turbine."<<endl;
			}
		break;
		}
	}
}

void Game::hover_object_with_cursor(){
	if(temp_object!=NULL){
		int xMouse, yMouse; 
		SDL_GetMouseState(&xMouse, &yMouse);
		map->check_grid(xMouse, yMouse);
		temp_object->setCoordinates(xMouse - (temp_object->getw())/2, yMouse - (temp_object->geth())/2); //centralizing the hovering operation as unit does not include the overridden centralizing setCoordinate function of inAnimate
	}
}


template<typename mytype> //template to store a generic type of object vector for passing into the function
bool Game::helper_detect_collision(int x, int y, vector<mytype*> obj) //helper function for detect collision using template
{
	for(auto i = obj.begin(); i!= obj.end(); i++){
		if ((*(*i)==temp_object)){ //overloaded operator
			return 1;
        }
    }
	return 0; 
}

void Game::display_object_description(int xMouse, int yMouse){ 	// this function will be used to display thefunctionality of objects.
	// int xMouse, yMouse; 
	// SDL_GetMouseState(&xMouse, &yMouse);
	cout << "In display object "<<endl;
	cout << "Before grid " << "x mouse "<<xMouse <<" y "<<yMouse<<endl;
	map->check_grid(xMouse, yMouse);
	cout << "After grid " << "x mouse "<<xMouse <<" y "<<yMouse<<endl;
	bool box_flag = 0; 	// no box panel is drawn
	string boxname = "";
	SDL_Texture * tex = NULL;

	for( auto i = farms.begin(); i<farms.end(); i++){
		cout << "get x " << (*i)->getx() << " get y "<<(*i)->gety() << " get h " << (*i)->geth() << " get w "<<(*i)->getw()<<endl;
		if (xMouse > (*i)->getx() && xMouse < ((*i)->getx()+(*i)->getw()) && yMouse > (*i)->gety() && yMouse < ((*i)->gety()+(*i)->geth())){
			cout << "Got a match "<<endl;
			if (box_flag == 0){	// we need to draw the panel
				box_flag = 1;
				boxname = "";
				boxname = "info_boxes/Farm.png";
				cout<<boxname <<endl;
				tex = loadTexture(boxname);
				if(tex != NULL){
					(*i)->set_box_flag(box_flag);
					(*i)->load_description_texture(tex, gRenderer);
				}
				else{
					// success = false;
					printf("Unable to load texture");
				}				
			}
			else {
				box_flag = 0;
				(*i)->set_box_flag(box_flag);
			}
		}
	}
	// for( auto i = banks.begin(); i<banks.end(); i++){
	// 	if ((*i)->getx() == xMouse && (*i)->gety() == yMouse){
	// 		if ((*i)->name == "bank"){
	// 			boxname = "";
	// 			boxname = "info_boxes/Bank_1.png";
	// 			tex = loadTexture(boxname);
	// 			(*i)->load_description_texture(tex, gRenderer);
	// 		}
	// 	}
	// }
	// for( auto i = houses.begin(); i<houses.end(); i++){
	// 	if ((*i)->getx() == xMouse && (*i)->gety() == yMouse){
	// 		if ((*i)->name == "house"){
	// 			boxname = "";
	// 			boxname = "info_boxes/House.png";
	// 			tex = loadTexture(boxname);
	// 			(*i)->load_description_texture(tex, gRenderer);
	// 		}
	// 	}
	// }
	// for( auto i = laboratories.begin(); i<laboratories.end(); i++){

	// }
	// for( auto i = industries.begin(); i<industries.end(); i++){

	// }
	// for( auto i = parks.begin(); i<parks.end(); i++){
	// 	if ((*i)->getx() == xMouse && (*i)->gety() == yMouse){
	// 		if ((*i)->name == "park"){
	// 			boxname = "";
	// 			boxname = "info_boxes/Park.png";
	// 			tex = loadTexture(boxname);
	// 			(*i)->load_description_texture(tex, gRenderer);
	// 		}
	// 	}
	// }
	// for( auto i = trees.begin(); i<trees.end(); i++){
	// 	if ((*i)->getx() == xMouse && (*i)->gety() == yMouse){
	// 		if ((*i)->name == "tree"){
	// 			boxname = "";
	// 			boxname = "info_boxes/Tree.png";
	// 			tex = loadTexture(boxname);
	// 			(*i)->load_description_texture(tex, gRenderer);
	// 		}
	// 	}
	// }
	// for( auto i = vehicles.begin(); i<vehicles.end(); i++){
	// 	if ((*i)->getx() == xMouse && (*i)->gety() == yMouse){
	// 		if ((*i)->name == "vehicle"){
	// 			boxname = "";
	// 			boxname = "info_boxes/Vehicle.png";
	// 			tex = loadTexture(boxname);
	// 			(*i)->load_description_texture(tex, gRenderer);
	// 		}
	// 	}
	// }
	// for(auto i = turbines.begin(); i<turbines.end(); i++){
	// 	if ((*i)->getx() == xMouse && (*i)->gety() == yMouse){
	// 		if ((*i)->name == "turbine"){
	// 			boxname = "";
	// 			boxname = "info_boxes/Turbine.png";
	// 			tex = loadTexture(boxname);
	// 			(*i)->load_description_texture(tex, gRenderer);
	// 		}
	// 	}
	// }	
}

bool Game::detect_collision(int x, int y){
	// bool Collision = 0;
		// int startingpoint_of_static_object, endingpoint_of_static_object;
	// moving object square

	bool f1 = helper_detect_collision <Farm>(x, y, farms);
	bool f2 = helper_detect_collision <Bank>(x,y, banks);
	bool f3 = helper_detect_collision <House>(x,y,houses);
	bool f4 = helper_detect_collision <Industry>(x,y, industries);
	bool f5 = helper_detect_collision <Laboratory>(x,y, laboratories);
	bool f6 = helper_detect_collision <Park>(x,y, parks);
	bool f7 = helper_detect_collision <SolarPanel>(x,y, solarpanels);
	bool f8 = helper_detect_collision <Tree>(x,y, trees);
	bool f9 = helper_detect_collision <Turbine>(x,y, turbines);
	bool f10 = helper_detect_collision <Vehicle>(x,y, vehicles);
	// cout << f1 << f2<<f3<<f4<<f5<<f6<<f7<<f8<<f9<<f10 <<endl;
	// helper_detect_collision(x,y, workers);
	return (f1||f2||f3||f4||f5||f6||f7||f8||f9||f10);

	
}



void Game::scroll_objects(bool xL,bool  xR, bool yU, bool yD){
	for(auto i = farms.begin(); i!=farms.end(); i++){
		if (xL){
			(*i)->refresh_coordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->refresh_coordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}

	for(auto i = houses.begin(); i!=houses.end(); i++){
		if (xL){
			(*i)->refresh_coordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->refresh_coordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}
	for(auto i = laboratories.begin(); i!=laboratories.end(); i++){
		if (xL){
			(*i)->refresh_coordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->refresh_coordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}
	for(auto i = industries.begin(); i!=industries.end(); i++){
		if (xL){
			(*i)->refresh_coordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->refresh_coordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}
	for(auto i = parks.begin(); i!=parks.end(); i++){
		if (xL){
			(*i)->refresh_coordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->refresh_coordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}
	for(auto i = trees.begin(); i!=trees.end(); i++){
		if (xL){
			(*i)->refresh_coordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->refresh_coordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}

	for(auto i = solarpanels.begin(); i!=solarpanels.end(); i++){
		if (xL){
			(*i)->refresh_coordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->refresh_coordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}

	for(auto i = vehicles.begin(); i!=vehicles.end(); i++){
		if (xL){
			(*i)->refresh_coordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->refresh_coordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}
	// for(auto i = workers.begin(); i!=workers.end(); i++){
	// 	if (xL){
	// 		(*i)->setCoordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
	// 	}
	// 	else if (xR){
	// 		(*i)->refresh_coordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
	// 	}
	// 	else if (yU){
	// 		(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
	// 	}
	// 	else if (yD){
	// 		(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
	// 	}
	// }
	for(auto i = banks.begin(); i!=banks.end(); i++){
		if (xL){
			(*i)->refresh_coordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->refresh_coordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}
	for(auto i = turbines.begin(); i!=turbines.end(); i++){
		if (xL){
			(*i)->refresh_coordinates((*i)->getx()-SCROLL_SPEED, (*i)->gety());
		}
		else if (xR){
			(*i)->refresh_coordinates((*i)->getx()+SCROLL_SPEED, (*i)->gety());
		}
		else if (yU){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() -SCROLL_SPEED);
		}
		else if (yD){
			(*i)->refresh_coordinates((*i)->getx(), (*i)->gety() +SCROLL_SPEED);
		}
	}


}




void Game::run_menu(){

	bool click; 
	
	SDL_Event e;
	while(menu->menuactive){
		// if (true){
		
		// currentTime = SDL_GetTicks();
		// cout<< "Main menu running "<< currentTime / 1000 << " seconds." << endl;



	

		//check for keyboard event
		while( SDL_PollEvent( &e ) != 0 ){
			// cout << " Mix_PlayingMusic() : "<<Mix_PlayingMusic()<<endl;

			// playing menu background music
			sound.play_menu_background_music();
			// sound.play_hover_music();
			// if( Mix_PlayingMusic() == 0 )
			// {
			// 	//Play the music
			// 	Mix_PlayMusic( menu_background_music, -1 );
			// }
			if( e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYDOWN))
			{
				menu->menuactive = false;
				break;
			}
			
			int xMouse, yMouse;
			SDL_GetMouseState(&xMouse,&yMouse);

			SDL_RenderClear(gRenderer); //removes everything from renderer
			
			if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT){
				click =1;
			}
			// cout << "going into the refresh menu" <<endl;
			menu->refresh(gRenderer, xMouse, yMouse, click, sound);
			
			SDL_RenderPresent(gRenderer);
			click =0;

		}
	}
	sound.stop_music();
}
void Game::close_menu(){
	
	
	delete menu;

}

bool Game::exit_from_menu(){
	cout << "exit pressed: " << menu->quit_game() <<endl;
	return menu->quit_game();
}

void Game::run( )
{
    SDL_RenderClear( gRenderer );
	//Main loop flag
	bool quit = false;
	bool pause = false;
	
	// stopping the menu background music
	
	// Mix_HaltMusic();
	cout<<"Main Cash : "<<main_cash<<endl;
	cout<<"XP_level : "<<XP_level<<endl;
	cout<<"Player level : "<<P_level<<endl;

	unsigned int lastTime = 0, currentTime = 0;
	// update_parameters();
	// cout<<"calling update parameters." << endl;
	bool option_bar_flag = false; // option is disabled


	//Event handler
	SDL_Event e;

	

	cout << "quit " <<quit <<endl;
	//While application is running
	while( !quit )
	{
		//play the background music

		currentTime = SDL_GetTicks()/1000; //time in seconds
		// cout<< "Game running "<< currentTime / 1000 << " seconds." << endl;
		
		// play game back music here

		if (sound.check_mute() != 1){
			sound.play_game_background_music();
		}
		
		// cout<< "game mix playing music : "<<Mix_PlayingMusic()<<endl;
		// if( Mix_PlayingMusic() == 0 )
		// {
		// 	SDL_Delay(2500);
		// 	//Play the music
		// 	Mix_PlayMusic( game_background_music, -1 );
		// }		

		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			// updating scores
			if (XP_level/200 >= 1){
				XP_level -= 200;
				P_level += 1;
				main_cash += 5000;
				cout<<"Congratulations you are promoted to the next level. Level "<<P_level << " ."<<endl;
				cout << "You also receive a cash bonus of 5000."<< endl;
			}
			//User requests quit
			if( e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYDOWN))
			{
				quit = true;
				break;
			}
			//check if user requests save game:
			if(e.key.keysym.sym == SDLK_s && e.type == SDL_KEYDOWN){
				// save_game();
				
			}
			else if(e.key.keysym.sym == SDLK_l && e.type == SDL_KEYDOWN){
				// load_game();
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
						// cout << "upper pressed" <<endl;
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

				display_object_description(xMouse, yMouse); // displaying box for info
				
				// cout << "X : "<< xMouse << " Y : " << yMouse <<endl;
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
				else if(temp_object!=NULL && yMouse < SCREEN_HEIGHT - 300  &&  !detect_collision( xMouse, yMouse)){
					
					// cout << "Before grid " << "x mouse "<<xMouse <<" y "<<yMouse<<endl;
					map->check_grid(xMouse, yMouse); //corrects the mouse coordinates according to the grid. 
					// cout << "After grid " << "x mouse "<<xMouse <<" y "<<yMouse<<endl;
					all_objects.push_back(temp_object); // store the object in a master all_object vector, 

					// make individual class functions to update cash and XP_level
					// industry and lab chezein bnaein unsy paisay mileingy
					// industry product ki progress front end py show krni h
					if (temp_object->name == "farm"){
						// cout<< detect_collision( xMouse, yMouse) <<endl;
						if (sound.check_sfx_mute() != 1){
							sound.play_positive_music();
						}
						Farm * myfarm = dynamic_cast<Farm *>(temp_object);
						myfarm->setCoordinates(xMouse, yMouse);
						myfarm->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for farm
						myfarm->set_creation_time(currentTime);
						farms.push_back(myfarm);
						temp_object = NULL;	
					}
					//check other objects here!
					else if (temp_object->name == "bird"){
						// cout<< detect_collision( xMouse, yMouse) <<endl;
						if (sound.check_sfx_mute() != 1){
							sound.play_positive_music();
						}
						Bird * mybird = dynamic_cast<Bird *>(temp_object);
						mybird->setCoordinates(xMouse, yMouse);
						mybird->set_creation_time(currentTime);
						mybird->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for bird
						birds.push_back(mybird);
						temp_object = NULL;
					}
					
					else if (temp_object->name == "building"){
						// cout<< detect_collision( xMouse, yMouse) <<endl;
						if (sound.check_sfx_mute() != 1){
							sound.play_positive_music();
						}
						Building * mybuilding = dynamic_cast<Building *>(temp_object);
						mybuilding->setCoordinates(xMouse, yMouse);
						mybuilding->set_creation_time(currentTime);
						mybuilding->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for building
						buildings.push_back(mybuilding);
						temp_object = NULL;
					}

					else if (temp_object->name == "bank"){
						// cout<< detect_collision( xMouse, yMouse) <<endl;
						if (sound.check_sfx_mute() != 1){
							sound.play_positive_music();
						}
						Bank * mybank = dynamic_cast<Bank *>(temp_object);
						mybank->setCoordinates(xMouse, yMouse);
						mybank->set_creation_time(currentTime);
						mybank->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for bank
						banks.push_back(mybank);
						temp_object = NULL;
					}

					else if (temp_object->name == "house"){
						// cout<< detect_collision( xMouse, yMouse) <<endl;
						if (sound.check_sfx_mute() != 1){
							sound.play_positive_music();
						}
						House * myhouse = dynamic_cast<House *>(temp_object);
						myhouse->setCoordinates(xMouse, yMouse);
						myhouse->set_creation_time(currentTime);
						myhouse->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for house
						houses.push_back(myhouse);
						temp_object = NULL;
					}

					else if (temp_object->name == "industry"){
						// cout<< detect_collision( xMouse, yMouse) <<endl;
						if (sound.check_sfx_mute() != 1){
							sound.play_positive_music();
						}
						Industry * myindustry = dynamic_cast<Industry *>(temp_object);
						myindustry->setCoordinates(xMouse, yMouse);
						myindustry->set_creation_time(currentTime);
						myindustry->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for industryt
						industries.push_back(myindustry);
						temp_object = NULL;
					}

					else if (temp_object->name == "laboratory"){
						// cout<< detect_collision( xMouse, yMouse) <<endl;
						if (sound.check_sfx_mute() != 1){
							sound.play_positive_music();
						}
						Laboratory * mylaboratory = dynamic_cast<Laboratory *>(temp_object);
						mylaboratory->setCoordinates(xMouse, yMouse);
						mylaboratory->set_creation_time(currentTime);
						mylaboratory->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for laboratory
						laboratories.push_back(mylaboratory);
						temp_object = NULL;
					}

					else if (temp_object->name == "park"){
						// cout<< detect_collision( xMouse, yMouse) <<endl;
						if (sound.check_sfx_mute() != 1){
							sound.play_positive_music();
						}
						Park * mypark = dynamic_cast<Park *>(temp_object);
						mypark->setCoordinates(xMouse, yMouse);
						mypark->set_creation_time(currentTime);
						mypark->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for park
						parks.push_back(mypark);
						temp_object = NULL;
					}

					else if (temp_object->name == "scientist"){
						// cout<< detect_collision( xMouse, yMouse) <<endl;
						if (sound.check_sfx_mute() != 1){
							sound.play_positive_music();
						}
						Scientist * myscientist = dynamic_cast<Scientist *>(temp_object);
						myscientist->setCoordinates(xMouse, yMouse);
						myscientist->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for scientist
						scientists.push_back(myscientist);
						myscientist->set_creation_time(currentTime);
						scientist_obj->increase_scientist();
						scientist_obj->show_scientist_count();
						temp_object = NULL;
					}

					else if (temp_object->name == "solarpanel"){
						// cout<< detect_collision( xMouse, yMouse) <<endl;
						if (sound.check_sfx_mute() != 1){
							sound.play_positive_music();
						}
						SolarPanel * mysolarpanel = dynamic_cast<SolarPanel *>(temp_object);
						mysolarpanel->setCoordinates(xMouse, yMouse);
						mysolarpanel->set_creation_time(currentTime);
						mysolarpanel->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for solarpanel
						solarpanels.push_back(mysolarpanel);
						temp_object = NULL;
					}

					else if (temp_object->name == "tree"){
						// cout<< detect_collision( xMouse, yMouse) <<endl;
						if (sound.check_sfx_mute() != 1){
							sound.play_positive_music();
						}
						Tree * mytree = dynamic_cast<Tree *>(temp_object);
						mytree->setCoordinates(xMouse, yMouse);
						mytree->set_creation_time(currentTime);
						mytree->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for tree
						trees.push_back(mytree);
						temp_object = NULL;
					}

					else if (temp_object->name == "turbine"){
						// cout<< detect_collision( xMouse, yMouse) <<endl;
						if (sound.check_sfx_mute() != 1){
							sound.play_positive_music();
						}
						Turbine * myturbine = dynamic_cast<Turbine *>(temp_object);
						myturbine->setCoordinates(xMouse, yMouse);
						myturbine->set_creation_time(currentTime);
						myturbine->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for turbine
						turbines.push_back(myturbine);
						temp_object = NULL;
					}

					else if (temp_object->name == "vehicle"){
						// cout<< detect_collision( xMouse, yMouse) <<endl;
						if (sound.check_sfx_mute() != 1){
							sound.play_positive_music();
						}
						Vehicle * myvehicle = dynamic_cast<Vehicle *>(temp_object);
						myvehicle->setCoordinates(xMouse, yMouse);
						myvehicle->set_creation_time(currentTime);
						myvehicle->update_scores(main_cash, XP_level);	// updates the values of cash and XP_level for vehicle
						vehicles.push_back(myvehicle);
						temp_object = NULL;
					}

					else if (temp_object->name == "worker"){
						// cout<< detect_collision( xMouse, yMouse) <<endl;
						if (sound.check_sfx_mute() != 1){
							sound.play_positive_music();
						}
						Worker * myworker = dynamic_cast<Worker *>(temp_object);
						myworker->setCoordinates(xMouse, yMouse);
						myworker->set_creation_time(currentTime); 
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
	// cout<< "Total number of laboratories in the city : "<< laboratories.size()<<endl;
	// cout<<"END"<<endl;
	// cout<<"Main Cash : "<<main_cash<<endl;
	// cout<<"XP_level : "<<XP_level<<endl;
	// cout<<"Player level : "<<P_level<<endl;
}

Game::~Game(){
	
}