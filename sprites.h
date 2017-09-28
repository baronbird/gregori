// sprites.h
//
// for Gregori
// defines the spritemap, which stores the location of any sprite we could ever want!
//
//      revision history
//        9-8-2017 :: started
//       9-27-2017 :: added sprite locations
//
// baronbird //////////////////////////////////////////////////////////////////////////////////

#ifndef SPRITES_H
#define SPRITES_H

#include<map>

// spritemap /////////////////////////////////////////////////////////////////////////////////

std::map<std::string, SDL_Rect> spritemap;

// insert all sprite locations to spritemap //////////////////////////////////////////////////

// gregori
spritemap.insert( std::pair<std::string, SDL_Rect>( "GREG_IDLE", {0,0,7,7} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "GREG_RUN_RIGHT1", {7,0,7,7} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "GREG_RUN_RIGHT2", {14,0,7,7} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "GREG_RUN_LEFT1", {21,0,7,7} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "GREG_RUN_LEFT2", {28,0,7,7} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "GREG_CLIMB_VERT_RIGHT1", {35,0,7,7} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "GREG_CLIMB_VERT_RIGHT2", {42,0,7,7} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "GREG_CLIMB_RIGHT", {49,0,7,7} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "GREG_CLIMB_VERT_LEFT1", {56,0,7,7} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "GREG_CLIMB_VERT_LEFT2", {63,0,7,7} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "GREG_CLIMB_LEFT", {70,0,7,7} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "GREG_CLIMB_VERT1", {77,0,7,7} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "GREG_CLIMB_VERT2", {84,0,7,7} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "GREG_CLIMB_IDLE", {94,0,7,7} ) );

// platform
spritemap.insert( std::pair<std::string, SDL_Rect>( "PLATFORM", {0,7,16,3} ) );

// title
spritemap.insert( std::pair<std::string, SDL_Rect>( "TITLE", {0,10,69,26} ) );

// prompts
spritemap.insert( std::pair<std::string, SDL_Rect>( "PROMPT_X", {0,36,52,26} ) );

// vine
spritemap.insert( std::pair<std::string, SDL_Rect>( "VINE_POTTED_PLANT", {98,0,7,9} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "VINE_SEED", {105,0,4,5} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "VINE_GROWING1", {69,10,5,40} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "VINE_GROWING2", {74,10,5,40} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "VINE_GROWING3", {79,10,5,40} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "VINE_FULL_SIZE", {84,10,5,40} ) );

// mushvine
spritemap.insert( std::pair<std::string, SDL_Rect>( "MUSHVINE_POTTED_PLANT", {98,9,7,9} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "MUSHVINE_SEED", {105,9,4,5} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "MUSHVINE_GROWING1", {0,63,9,44} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "MUSHVINE_GROWING2", {9,63,9,44} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "MUSHVINE_GROWING3", {18,63,9,44} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "MUSHVINE_GROWING4", {27,63,9,44} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "MUSHVINE_GROWING5", {36,63,9,44} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "MUSHVINE_GROWING6", {45,63,9,44} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "MUSHVINE_GROWING7", {54,63,9,44} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "MUSHVINE_GROWING8", {63,63,9,44} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "MUSHVINE_GROWING9", {72,63,9,44} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "MUSHVINE_GROWING10", {81,63,9,44} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "MUSHVINE_GROWING11", {90,63,9,44} ) );
spritemap.insert( std::pair<std::string, SDL_Rect>( "MUSHVINE_FULL_SIZE", {99,63,9,44} ) );

#endif
