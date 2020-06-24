#include "SDL.h"
#include "unit.hpp"
#include<iostream>
#include<SDL_ttf.h>
#include<vector>
#pragma once
namespace boost {
namespace serialization {
class access;
}
}
class InAnimate: public Unit{
    
    private:
        
        int width;
        int height;
        int price;
         //serialization template
        friend class boost::serialization::access;
        template<typename Archive>
        void serialize(Archive& ar, const unsigned version) {
            ar & width & height & price;  // Simply serialize the data members of Obj
        }
    protected:
        int OBJECT_WIDHT = 5*80;
        int OBJECT_HEIGHT =  5* 0.5625*80;
    public:
        
        InAnimate(SDL_Texture *);
        void draw(SDL_Renderer *);
        void setCoordinates(int, int); //overriding the default setCoordinates to centralize the object coordinates
        void refresh_coordinates(int, int); //refreshes the position of the static object
        // void setfont(TTF_Font*);
        ~InAnimate();

};