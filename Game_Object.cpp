// Game_Object.h
//
// for Gregori
// class definition for general Game_Object
//
//      revision history
//      1-11-2017 ::  started
//      1-12-2017 ::  improved collision
//                    added directional "place" functions
//      2-16-2017 ::  added struct "plant" to help with different plant types
//       9-8-2017 ::  documented and cleaned up code
//                ::  replaced the directional move and place functions with single
//                    functions that handled multiple directions
//      9-26-2017 ::  started generalizing class
//
// baronbird /////////////////////////////////////////////////////////////////////////////////

#include"Game_Object.h"

Game_Object::Game_Object() {}

Game_Object::~Game_Object() {}

// Game_Object::updateHitbox /////////////////////////////////////////////////////////////////
//
// keeps hitbox inline with sprite using hitbox offsets

void Game_Object::updateHitbox() {
    // TODO
    // for each hit in hitbox, off in hitbox_offsets
    //      hit.x = spriteLocation.x + off.x
    //      hit.y = spriteLocation.y + off.y
}


// Gregori::isCollidingWith //////////////////////////////////////////////////////////////////
//
// checks for collision between two Game_Objects
//
// @param object            the Game_Object to check for collision
// @return                  false if no collision exists
//                          true is collision exists
//
// TODO: implement collision between two dynamic objects

int Game_Object::isCollidingWith(Game_Object object) {
    bool collision = false;

    // TODO
    // for each hit in hitbox, box in object.hitbox
    //      if hit has collision with box
    //          collision = true
    
    return collision;
}


// Game_Object::get_spriteLocation ////////////////////////////////////////////////////////////
//
// returns the location of a Game_Object's sprite. used in main to render the object
//
// @return                  spriteLocation

SDL_Rect Game_Object::get_spriteLocation() {
    return spriteLocation;
}
