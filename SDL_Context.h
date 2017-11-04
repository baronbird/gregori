// SDL_Context.h
//
// for Gregori
// define SDL_Context class
// represents a context for SDL to run in (a window, a renderer, and any
// textures)
//
//        revision history
//        9-18-2017 :: started
//
// baronbird //////////////////////////////////////////////////////////////////

#ifndef SDL_INITS_H
#define SDL_INITS_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<string>
#include<vector>
#include"Game_Object.h"

class SDL_Context {
    public:
        SDL_Context();
        ~SDL_Context();
        bool          quit();
        bool          loadMedia();
        SDL_Texture  *loadTexture(std::string);
        void          render(std::vector<Game_Object*>);
        bool          initializationFailed();

    private:
        SDL_Window   *window;
        SDL_Renderer *renderer;
        SDL_Texture  *spriteSheet;
        SDL_Event     event;
        SDL_Rect      camera;
        bool          init_success;
};

#endif
