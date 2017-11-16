// Level.cpp
//
// for Gregori
// 
//      
//      revision history
//          11/8/2017 :: started
//
// baronbird //////////////////////////////////////////////////////////////////

#include <fstream>
#include "Level.h"

// constructor for Level //////////////////////////////////////////////////////
//
// opens file stream and loads level from provided file
//
// @param filename      name of level file

Level::Level(std::string filename) {
    std::ifstream loader(filename);

    char object_type;
    while(loader >> object_type) {
        int x, y;
        switch(object_type) {
            case 'g':
                loader >> x >> y;
                greg = Gregori(x, y);
                break;
            case 's':
                loader >> x >> y;
                world_state.push_back(new Platform(x, y));
                break;
            default:
                printf("Level file formatted incorrectly");
                // TODO(sam): exit with an error
        }
    }
}

// deconstructor for Level ////////////////////////////////////////////////////
//
// deletes any objects in world_state

Level::~Level() {
    for(auto object : world_state) {
        delete object;
    }
}

// render /////////////////////////////////////////////////////////////////////
//
// renders objects in world state and gregori
//
// @param sdl      sdl context to render in

void Level::render(SDL_Context &sdl) {
    world_state.push_back(&greg);
    sdl.render(world_state);
    world_state.pop_back();
}
    
// render /////////////////////////////////////////////////////////////////////
//
// updates objects in world state and gregori

void Level::update() {
    // for (auto &object : world_state) {
        // object->updatePosition();
    // }
    greg.updatePosition();
}
