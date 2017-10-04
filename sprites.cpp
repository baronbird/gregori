// sprites.cpp
//
// for Gregori
// defines the spritemap, which stores the location of any sprite we could ever want!
//
//      revision history
//        9-8-2017 :: started
//       9-27-2017 :: added sprite locations
//
// baronbird //////////////////////////////////////////////////////////////////////////////////

#include<map>
#include"SDL_Context.h"
#include"sprites.h"

// insert all sprite locations to spritemap //////////////////////////////////////////////////

void add_sprite(std::string name, SDL_Rect location) {
    spritemap.insert( std::pair<std::string, SDL_Rect>( name, location ) );
}

void init_spritemap() {
    // gregori
    add_sprite( "GREG_IDLE", {0,0,7,7} );
    add_sprite( "GREG_RUN_RIGHT1", {7,0,7,7} );
    add_sprite( "GREG_RUN_RIGHT2", {14,0,7,7} );
    add_sprite( "GREG_RUN_LEFT1", {21,0,7,7} );
    add_sprite( "GREG_RUN_LEFT2", {28,0,7,7} );
    add_sprite( "GREG_CLIMB_VERT_RIGHT1", {35,0,7,7} );
    add_sprite( "GREG_CLIMB_VERT_RIGHT2", {42,0,7,7} );
    add_sprite( "GREG_CLIMB_RIGHT", {49,0,7,7} );
    add_sprite( "GREG_CLIMB_VERT_LEFT1", {56,0,7,7} );
    add_sprite( "GREG_CLIMB_VERT_LEFT2", {63,0,7,7} );
    add_sprite( "GREG_CLIMB_LEFT", {70,0,7,7} );
    add_sprite( "GREG_CLIMB_VERT1", {77,0,7,7} );
    add_sprite( "GREG_CLIMB_VERT2", {84,0,7,7} );
    add_sprite( "GREG_CLIMB_IDLE", {94,0,7,7} );

    // platform
    add_sprite( "PLATFORM", {0,7,16,3} );

    // title
    add_sprite( "TITLE", {0,10,69,26} );

    // prompts
    add_sprite( "PROMPT_X", {0,36,52,26} );

    // vine
    add_sprite( "VINE_POTTED_PLANT", {98,0,7,9} );
    add_sprite( "VINE_SEED", {105,0,4,5} );
    add_sprite( "VINE_GROWING1", {69,10,5,40} );
    add_sprite( "VINE_GROWING2", {74,10,5,40} );
    add_sprite( "VINE_GROWING3", {79,10,5,40} );
    add_sprite( "VINE_FULL_SIZE", {84,10,5,40} );

    // mushvine
    add_sprite( "MUSHVINE_POTTED_PLANT", {98,9,7,9} );
    add_sprite( "MUSHVINE_SEED", {105,9,4,5} );
    add_sprite( "MUSHVINE_GROWING1", {0,63,9,44} );
    add_sprite( "MUSHVINE_GROWING2", {9,63,9,44} );
    add_sprite( "MUSHVINE_GROWING3", {18,63,9,44} );
    add_sprite( "MUSHVINE_GROWING4", {27,63,9,44} );
    add_sprite( "MUSHVINE_GROWING5", {36,63,9,44} );
    add_sprite( "MUSHVINE_GROWING6", {45,63,9,44} );
    add_sprite( "MUSHVINE_GROWING7", {54,63,9,44} );
    add_sprite( "MUSHVINE_GROWING8", {63,63,9,44} );
    add_sprite( "MUSHVINE_GROWING9", {72,63,9,44} );
    add_sprite( "MUSHVINE_GROWING10", {81,63,9,44} );
    add_sprite( "MUSHVINE_GROWING11", {90,63,9,44} );
    add_sprite( "MUSHVINE_FULL_SIZE", {99,63,9,44} );
}
