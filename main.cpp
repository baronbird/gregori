// main.cpp
//
// for Gregori
// without this we don't have a game
//
//      revision history
//      1-11-2017 ::  started
//                    added movement
//                    added animation
//      1-12-2017 ::  added title
//                    added climbing
//                    improved collision
//      2-16-2017 ::  added seed interactions
//      2-17-2017 ::  fixed jumping on vines
//       5-1-2017 ::  started adding hybrid plants
//      9-16-2017 ::  start completely refactoring main
//      11-3-2017 ::  introduced new spritemap interface
//
// baronbird //////////////////////////////////////////////////////////////////

// includes
#include<stdio.h>
#include<fstream>
#include"SDL_Context.h"
#include"Game_Object.h"
#include"Sprites.h"
#include"Level.h"

// macros
#define FRAME_LENGTH 1000.0/60.0
#define ANIMATION_FRAMES 4

// globals
Spritemap spritemap;

// main execution /////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
    // create new SDL context
    SDL_Context sdl;

    // make sure initialization did not fail
    if( sdl.initializationFailed() ) {
        printf("Could not create SDL_Context\n");
    }
    else if( !sdl.loadMedia() ) {
        printf("Could not load spritesheets\n");
    }
    else {
        const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);
        int animation_counter = 0;

        Level lvl("level.txt");

        while( !sdl.quit() ) {
            lvl.greg.control(currentKeyStates);

            if(animation_counter == ANIMATION_FRAMES) {
                lvl.greg.updateAnimation();
                animation_counter = 0;
            }
            else {
                animation_counter++;
            }

            lvl.update();
            lvl.render(sdl);
            
            SDL_Delay(FRAME_LENGTH);
        }
    }

    return EXIT_SUCCESS;
}
