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
//
// baronbird /////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include"SDL_Context.h"

int main(int argc, char* argv[]) {
    // create new SDL context
    SDL_Context sdl;

    // make sure initialization did not fail
    if( sdl.initializationFailed ) {
        printf("Could not create SDL_Context\n");
    }
    else if( !sdl.loadMedia() ) {
        printf("Could not load spritesheets\n");
    }
    else {
        while( !sdl.quit() ) {

            sdl.render();

            SDL_Delay(50);
        }
    }

    return EXIT_SUCCESS;
}
