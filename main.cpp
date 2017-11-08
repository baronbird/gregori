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

// macros
#define FRAME_LENGTH 1000.0/60.0

// globals
Spritemap spritemap;

// main execution /////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
    // create new SDL context
    SDL_Context sdl;

    // TODO(sam): class to handle loading and storing of level data
    std::ifstream level_loader("level.txt");

    // make sure initialization did not fail
    if( sdl.initializationFailed() ) {
        printf("Could not create SDL_Context\n");
    }
    else if( !sdl.loadMedia() ) {
        printf("Could not load spritesheets\n");
    }
    else {
        std::vector<Game_Object *> world_state;
        Gregori greg(0,0);
        const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);

        // TODO(sam): see above
        char object_type;
        while(level_loader >> object_type) {
            int x, y;
            switch(object_type) {
                case 'g':
                    level_loader >> x >> y;
                    greg = Gregori(x, y);
                    break;
                case 's':
                    level_loader >> x >> y;
                    world_state.push_back(new Platform(x, y));
                    
                    break;
                default:
                    printf("Level file formatted incorrectly\n");
            }
        }

        while( !sdl.quit() ) {
            greg.control(currentKeyStates);

            world_state.push_back(&greg);
            for(auto &object : world_state) {
                object->updatePosition();
            }
            sdl.render(world_state);
            world_state.pop_back();
            
            SDL_Delay(FRAME_LENGTH);
        }
    }

    return EXIT_SUCCESS;
}
