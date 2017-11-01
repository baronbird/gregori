// Game_Object.cpp
//
// for Gregori
// class definition for general Game_Object
//
//      revision history
//      1-11-2017 ::  started
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

#include"Game_Object.h"

// constructor for Game_Object ////////////////////////////////////////////////

Game_Object::Game_Object() {}


// deconstructor for Game_Object //////////////////////////////////////////////

Game_Object::~Game_Object() {}


// Game_Object::updateHitbox //////////////////////////////////////////////////
//
// keeps hitbox inline with sprite using hitbox offsets

void Game_Object::updateHitbox() {
    for( auto hit : hitbox ) {
        hit.box.x = spriteLocation.x + hit.off.x;
        hit.box.y = spriteLocation.y + hit.off.y;
    }
}


// Gregori::isCollidingWith ///////////////////////////////////////////////////
//
// checks for collision between two Game_Objects
//
// @param object            the Game_Object to check for collision
// @return                  false if no collision exists
//                          true is collision exists
//
// TODO: implement collision between two dynamic objects

int Game_Object::isCollidingWith(Game_Object &object) {
    bool collision = false;

    for( auto hit : hitbox ) {
        for( auto obj_hit : object.hitbox ) {
            if( SDL_HasIntersection(&hit.box, &obj_hit.box) ) {
                collision = true;
                break;
            }
        }
        if( collision == true ) {
            break;
        }
    }
    
    return collision;
}


// Game_Object::get_spriteLocation ////////////////////////////////////////////
//
// returns the location of a Game_Object's sprite. used in main to render
// the object
//
// @return                  spriteLocation

SDL_Rect *Game_Object::get_spriteLocation() {
    return &spriteLocation;
}


// Game_Object::get_current_sprite ////////////////////////////////////////////
//
// returns the current sprite image
//
// @return                  current_sprite

std::string Game_Object::get_current_sprite() {
    return current_sprite;
}


// Gregori ////////////////////////////////////////////////////////////////////

// constructor for Gregori ////////////////////////////////////////////////////
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

    
// deconstructor for Gregori //////////////////////////////////////////////////
//
// nothing to clean up!

Gregori::~Gregori() {}


// Gregori::control ///////////////////////////////////////////////////////////
//
// given current key states and Gregori's current state, change Gregori's
// state
//
// @param currentKeyStates      an array containing the current key states

void Gregori::control(const Uint8 *currentKeyStates) {
    // TODO: implement key state controls
}


// Gregori::updateAnimation ///////////////////////////////////////////////////
//
// given Gregori's current animation frame and state, choose the next
// animation for Gregori

void Gregori::updateAnimation() {
    // TODO: implement FSM for animation. figure out when to trigger
}


// Gregori::updatePosition ////////////////////////////////////////////////////
//
// add Gregori's velocity to his position, checking for collisions along the
// way

void Gregori::updatePosition() {
    spriteLocation.x += velocity.x;
    spriteLocation.y += velocity.y;
    // TODO: add collision checking
}


// Platform ///////////////////////////////////////////////////////////////////

// constructor for Platform ////////////////////////////////////////////////
//
// places Platform at the given position
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
