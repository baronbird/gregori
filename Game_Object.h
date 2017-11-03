// Game_Object.h
//
// for Gregori
// class definition for general Game_Object
//
//      revision history
//      1-11-2017 ::  started (as Gregori object)
//      1-12-2017 ::  improved collision
//                    added directional "place" functions
//      2-16-2017 ::  added struct "plant" to help with different plant
//                          types
//       9-8-2017 ::  documented and cleaned up code
//                ::  replaced the directional move and place functions
//                          with single functions that handle multiple
//                          directions
//      9-26-2017 ::  started generalizing class
//
// baronbird //////////////////////////////////////////////////////////////////

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include<SDL2/SDL.h>
#include<vector>
#include<string>

struct hitbox_part {
    SDL_Rect box;
    SDL_Point off;
};

// Game_Object ////////////////////////////////////////////////////////////////
//
// class interface for any in-game objects

class Game_Object {
    public:
        Game_Object();
        ~Game_Object();
        void        updateHitbox();
        int         isCollidingWith(Game_Object &);
        SDL_Rect   *get_spriteLocation();
        std::string get_current_sprite();
    protected:
        SDL_Rect                    spriteLocation;
        std::vector<hitbox_part>    hitbox;
        std::string                 current_sprite;
};


// Gregori ////////////////////////////////////////////////////////////////////
//
// inherited class to represent Gregori

class Gregori : public Game_Object {
    public:
        Gregori(int, int);
        ~Gregori();
        void control(const Uint8*);
        void updateAnimation();
        void updatePosition();
        
    private:
        SDL_Point velocity;
        int num_seeds;

};


// Platform ///////////////////////////////////////////////////////////////////
//
// inherited class to represent a platform

class Platform : public Game_Object {
    public:
        Platform(int, int);
        ~Platform();
        
};

#endif
