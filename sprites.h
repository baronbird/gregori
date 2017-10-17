// sprites.h
//
// for Gregori
// defines the spritemap, which stores the location of any sprite we could ever want!
//
//      revision history
//        9-8-2017 :: started
//       9-27-2017 :: added sprite locations
//
// baronbird ///////////////////////////////////////////////////////////////

#ifndef SPRITES_H
#define SPRITES_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

// spritemap helper functions //////////////////////////////////////////////

void spritemap_init();
void add_sprite(std::string, SDL_Rect);

#endif
