#include "SDL.h"
#include "inanimate.hpp"
#include<iostream>
#pragma once
//creating serialization namespace
namespace boost {
namespace serialization {
class access;
}
}
class Building: public InAnimate{
    
    protected:

        int structure_level;
        int height;
        int price;
        int upgrade_cost = 100;
        float creation_time;
        float progress;
         //serialization template
        friend class boost::serialization::access;
        template<typename Archive>
        void serialize(Archive& ar, const unsigned version) {
            ar & structure_level & height & price & upgrade_cost;  // Simply serialize the data members of Obj
        }
    public:

        Building(SDL_Texture *);
        void update_scores(int &, int &);
        int upgrade_building(int & );
        int showStructureLevel();
        void set_creation_time(int);
        void show_progress();
        ~Building();

};