// Sprites.h
//
// for Gregori
// defines the Spritemap class, which stores the location of all sprites
//
//      revision history
//        9-8-2017 :: started
//       9-27-2017 :: added sprite locations
//       11-3-2017 :: converted to class for nicer interface
//
// baronbird //////////////////////////////////////////////////////////////////

#ifndef SPRITES_H
#define SPRITES_H

#include<SDL2/SDL.h>
#include<map>

// spritemap class definition /////////////////////////////////////////////////

class Spritemap {
    public:
        Spritemap();
        SDL_Rect operator[](std::string);

    private:
        std::map<std::string, SDL_Rect> spritemap;
};

#endif
