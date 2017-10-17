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
// baronbird ///////////////////////////////////////////////////////////////

#include"Game_Object.h"

Game_Object::Game_Object() {
    spriteLocation = { 575, 351, 35, 35 };
}


Game_Object::~Game_Object() {}


// Game_Object::updateHitbox ///////////////////////////////////////////////
//
// keeps hitbox inline with sprite using hitbox offsets

void Game_Object::updateHitbox() {
    for( auto hit : hitbox ) {
        hit.box.x = spriteLocation.x + hit.off.x;
        hit.box.y = spriteLocation.y + hit.off.y;
    }
}


// Gregori::isCollidingWith ////////////////////////////////////////////////
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


// Game_Object::get_spriteLocation /////////////////////////////////////////
//
// returns the location of a Game_Object's sprite. used in main to render
// the object
//
// @return                  spriteLocation

SDL_Rect *Game_Object::get_spriteLocation() {
    return &spriteLocation;
}


// Game_Object::get_current_sprite /////////////////////////////////////////
//
// returns the current sprite image
//
// @return                  current_sprite

std::string Game_Object::get_current_sprite() {
    return current_sprite;
}
