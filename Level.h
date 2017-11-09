// Level.h
//
// for Gregori
// class definition for Level class
//      
//      revision history
//          11/8/2017 :: started
//
// baronbird //////////////////////////////////////////////////////////////////

#ifndef __LEVEL_H
#define __LEVEL_H

#include <vector>
#include <string>
#include "SDL_Context.h"
#include "Game_Object.h"

class Level {
    public:
        Level(std::string filename);
        ~Level();
        void render(SDL_Context &sdl);
        void update();

        Gregori greg = Gregori(0,0);

    private:
        std::vector<Game_Object *> world_state;
};

#endif
