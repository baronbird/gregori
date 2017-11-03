// Sprites.cpp
//
// for Gregori
// defines the spritemap, which stores the location of any sprite we could
// ever want!
//
//      revision history
//        9-8-2017 :: started
//       9-27-2017 :: added sprite locations
//       11-3-2017 :: converted to class for nicer interface
//
// baronbird //////////////////////////////////////////////////////////////////

#include<map>
#include"SDL_Context.h"
#include"Sprites.h"


// Spritemap lookup operator //////////////////////////////////////////////////
// 
// get spritesheet location for the given sprite

SDL_Rect Spritemap::operator[](std::string sprite_name) {
    return spritemap[sprite_name];
}

// Spritemap constructor //////////////////////////////////////////////////////
//
// insert all sprite locations into the spritemap

Spritemap::Spritemap() {
    // gregori
    spritemap.emplace( "GREG_IDLE", (SDL_Rect){0,0,7,7} );
    spritemap.emplace( "GREG_RUN_RIGHT1", (SDL_Rect){7,0,7,7} );
    spritemap.emplace( "GREG_RUN_RIGHT2", (SDL_Rect){14,0,7,7} );
    spritemap.emplace( "GREG_RUN_LEFT1", (SDL_Rect){21,0,7,7} );
    spritemap.emplace( "GREG_RUN_LEFT2", (SDL_Rect){28,0,7,7} );
    spritemap.emplace( "GREG_CLIMB_VERT_RIGHT1", (SDL_Rect){35,0,7,7} );
    spritemap.emplace( "GREG_CLIMB_VERT_RIGHT2", (SDL_Rect){42,0,7,7} );
    spritemap.emplace( "GREG_CLIMB_RIGHT", (SDL_Rect){49,0,7,7} );
    spritemap.emplace( "GREG_CLIMB_VERT_LEFT1", (SDL_Rect){56,0,7,7} );
    spritemap.emplace( "GREG_CLIMB_VERT_LEFT2", (SDL_Rect){63,0,7,7} );
    spritemap.emplace( "GREG_CLIMB_LEFT", (SDL_Rect){70,0,7,7} );
    spritemap.emplace( "GREG_CLIMB_VERT1", (SDL_Rect){77,0,7,7} );
    spritemap.emplace( "GREG_CLIMB_VERT2", (SDL_Rect){84,0,7,7} );
    spritemap.emplace( "GREG_CLIMB_IDLE", (SDL_Rect){94,0,7,7} );

    // platform
    spritemap.emplace( "PLATFORM", (SDL_Rect){0,7,16,3} );

    // title
    spritemap.emplace( "TITLE", (SDL_Rect){0,10,69,26} );

    // prompts
    spritemap.emplace( "PROMPT_X", (SDL_Rect){0,36,52,26} );

    // vine
    spritemap.emplace( "VINE_POTTED_PLANT", (SDL_Rect){98,0,7,9} );
    spritemap.emplace( "VINE_SEED", (SDL_Rect){105,0,4,5} );
    spritemap.emplace( "VINE_GROWING1", (SDL_Rect){69,10,5,40} );
    spritemap.emplace( "VINE_GROWING2", (SDL_Rect){74,10,5,40} );
    spritemap.emplace( "VINE_GROWING3", (SDL_Rect){79,10,5,40} );
    spritemap.emplace( "VINE_FULL_SIZE", (SDL_Rect){84,10,5,40} );

    // mushvine
    spritemap.emplace( "MUSHVINE_POTTED_PLANT", (SDL_Rect){98,9,7,9} );
    spritemap.emplace( "MUSHVINE_SEED", (SDL_Rect){105,9,4,5} );
    spritemap.emplace( "MUSHVINE_GROWING1", (SDL_Rect){0,63,9,44} );
    spritemap.emplace( "MUSHVINE_GROWING2", (SDL_Rect){9,63,9,44} );
    spritemap.emplace( "MUSHVINE_GROWING3", (SDL_Rect){18,63,9,44} );
    spritemap.emplace( "MUSHVINE_GROWING4", (SDL_Rect){27,63,9,44} );
    spritemap.emplace( "MUSHVINE_GROWING5", (SDL_Rect){36,63,9,44} );
    spritemap.emplace( "MUSHVINE_GROWING6", (SDL_Rect){45,63,9,44} );
    spritemap.emplace( "MUSHVINE_GROWING7", (SDL_Rect){54,63,9,44} );
    spritemap.emplace( "MUSHVINE_GROWING8", (SDL_Rect){63,63,9,44} );
    spritemap.emplace( "MUSHVINE_GROWING9", (SDL_Rect){72,63,9,44} );
    spritemap.emplace( "MUSHVINE_GROWING10", (SDL_Rect){81,63,9,44} );
    spritemap.emplace( "MUSHVINE_GROWING11", (SDL_Rect){90,63,9,44} );
    spritemap.emplace( "MUSHVINE_FULL_SIZE", (SDL_Rect){99,63,9,44} );
}
