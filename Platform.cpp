// Gregori.cpp
//
// for Gregori
// member function definitions for Gregori
//
// revision history:
//          10/09/2017 :: started
//
// baronbird ///////////////////////////////////////////////////////////////

// #include<SDL2/SDL.h> might want this for controls
#include"Platform.h"

// constructor for Platform ////////////////////////////////////////////////
//
// makes Gregori at the given position
//
// @param x         x location
// @param y         y location

Platform::Platform(int x, int y) {
    spriteLocation = { x, y, 80, 15 };
    current_sprite = "PLATFORM";
    hitbox.push_back( { { 0, 0, 80, 15 }, { 0, 0 } } );
    updateHitbox();
}

    
// deconstructor for Platform //////////////////////////////////////////////
//
// nothing to clean up!

Platform::~Platform() {}
