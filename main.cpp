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
// baronbird ///////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fstream>
#include<map>
#include"SDL_Context.h"
#include"Gregori.h"
#include"Platform.h"
#include"Sprites.h"

extern std::map<std::string, SDL_Rect> spritemap;

int main(int argc, char* argv[]) {
    // create new SDL context
    SDL_Context sdl;
    spritemap_init();

    std::ifstream level_loader("level.txt");

    // make sure initialization did not fail
    if( sdl.initializationFailed ) {
        printf("Could not create SDL_Context\n");
    }
    else if( !sdl.loadMedia() ) {
        printf("Could not load spritesheets\n");
    }
    else {
        std::vector<Game_Object> world_state;

        char object_type;
        while(level_loader >> object_type) {
            int x, y;
            switch(object_type) {
                case 'g':
                    level_loader >> x >> y;
                    world_state.push_back(Gregori(x, y));
                    break;
                case 's':
                    level_loader >> x >> y;
                    world_state.push_back(Platform(x, y));
                    break;
                default:
                    printf("Level file formatted incorrectly\n");
            }
        }

        while( !sdl.quit() ) {
            
            sdl.render(world_state);
            
            SDL_Delay(50);
        }
    }

    return EXIT_SUCCESS;
}
