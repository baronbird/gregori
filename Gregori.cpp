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
#include"Gregori.h"

// constructor for Gregori /////////////////////////////////////////////////
//
// makes Gregori at the given position
//
// @param x         x location
// @param y         y location

Gregori::Gregori(int x, int y) {
    spriteLocation = { x, y, 35, 35 };
    velocity = { 0, 0 };
    current_sprite = "GREG_IDLE";
    hitbox.push_back( { { 0, 0, 25, 20 }, { 5, 0 } } );
    hitbox.push_back( { { 0, 0, 15, 10 }, { 10, 25 } } );
    updateHitbox();
}

    
// deconstructor for Gregori ///////////////////////////////////////////////
//
// nothing to clean up!

Gregori::~Gregori() {}


// Gregori::control ////////////////////////////////////////////////////////
//
// given current key states and Gregori's current state, change Gregori's
// state
//
// @param currentKeyStates      an array containing the current key states

void Gregori::control(const Uint8 *currentKeyStates) {
    // TODO: implement key state controls
}


// Gregori::updateAnimation ////////////////////////////////////////////////
//
// given Gregori's current animation frame and state, choose the next
// animation for Gregori

void Gregori::updateAnimation() {
    // TODO: implement FSM for animation. figure out when to trigger
}


// Gregori::updatePosition /////////////////////////////////////////////////
//
// add Gregori's velocity to his position, checking for collisions along the
// way

void Gregori::updatePosition() {
    spriteLocation.x += velocity.x;
    spriteLocation.y += velocity.y;
    // TODO: add collision checking
}
