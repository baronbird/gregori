// SDL_Context.h
//
// for Gregori
// define SDL_Context class
// represents a context for SDL to run in (a window, a renderer, and any textures)
//
//        revision history
//        9-18-2017 :: started
//
// baronbird ////////////////////////////////////////////////////////////////////////////////

#ifndef SDL_INITS_H
#define SDL_INITS_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<string>

class SDL_Context {
    public:
        SDL_Context();
        ~SDL_Context();
        bool          initializationFailed();
        bool          loadMedia();
        SDL_Texture  *loadTexture(std::string);
        void          render();
    private:
        SDL_Window   *window;
        SDL_Renderer *renderer;
        SDL_Texture  *spriteSheet;
};

#endif
