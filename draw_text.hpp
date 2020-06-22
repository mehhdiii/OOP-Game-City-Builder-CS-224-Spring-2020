#include "SDL.h"
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include<string>
#pragma once

class Draw_text
{
	public:
		//Initializes variables
		Draw_text();

		//Deallocates memory
		~Draw_text();
 
        void set_renderer(SDL_Renderer * );
        void set_font(TTF_Font *);
		//Loads image at specified path
    //    private:
		bool loadFromFile( std::string path );
    private:
		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );
		
		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
    public:
		//Gets image dimensions
		int getWidth();
		int getHeight();
        //draw function
        void draw(SDL_Renderer * );
        void setCoordinates(int, int);
        void setText(std::string );

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

        SDL_Renderer * gRenderer;
        TTF_Font * gFont;
		//Image dimensions
		int mWidth;
		int mHeight;
        int xCoordinate;
        int yCoordinate;
        std::string text="hello"; 

};