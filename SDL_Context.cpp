// SDL_Context.cpp
//
// for Gregori
// function definitions for SDL_Context class
//
// much borrowed from Lazy Foo's SDL tutorials
// (http://lazyfoo.net/tutorials/SDL/index.php)
//
//        revision history
//        9-18-2017 :: started
//
// baronbird //////////////////////////////////////////////////////////////

#include<stdio.h>
#include<map>
#include"SDL_Context.h"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

extern std::map<std::string, SDL_Rect> spritemap;

// SDL_Context constructor /////////////////////////////////////////////////
//
// initializes SDL, creates window, creates renderer

SDL_Context::SDL_Context() {
    // initialize all to null pointers for error checking
    window = NULL;
    renderer = NULL;
    spriteSheet = NULL;
    initializationFailed = false;

    // initialize SDL with only the video subsystems
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialize SDL. SDL_Error: %s\n",
                SDL_GetError() );
        initializationFailed = true;
    }
    else {
        // create game window with specified settings
        window = SDL_CreateWindow("Gregori",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
        if(window == NULL) {
            printf("Could not create window. SDL_Error: %s\n",
                    SDL_GetError() );
            initializationFailed = true;
        }
        else {
            // create accelerated renderer
            renderer = SDL_CreateRenderer(window, -1,
                    SDL_RENDERER_ACCELERATED);

            if(renderer == NULL) {
                printf("Could not create renderer. SDL_Error: %s\n",
                        SDL_GetError() );
                initializationFailed = true;
            }
            else {
                // initialize SDL_image to load PNGs
                int imgFlags = IMG_INIT_PNG;

                if( !( IMG_Init( imgFlags ) && imgFlags ) ) {
                    printf("Could not init SDL_image. IMG_Error: %s\n",
                            IMG_GetError() );
                    initializationFailed = true;
                }
            }
        }
    }
}


// SDL_Context deconstructor ///////////////////////////////////////////////
// 
// frees all resources allocated on the heap, because no one like memory
// leaks, especially not me!

SDL_Context::~SDL_Context() {
    SDL_DestroyTexture(spriteSheet);
    spriteSheet = NULL;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;

    SDL_Quit();
}


// SDL_Context::quit ///////////////////////////////////////////////////////
//
// check if we received a quit event
//
// @return              true if quit event received, false otherwise

bool SDL_Context::quit() {
    while( SDL_PollEvent(&event) != 0 ) {
        if( event.type == SDL_QUIT ) {
            return true;
        }
    }
    
    return false;
}


// SDL_Context::loadMedia //////////////////////////////////////////////////
//
// loads all necessary textures (currently only one!)
//
// @return              true on successful completion, false on some error

bool SDL_Context::loadMedia() {
    bool success = true;

    spriteSheet = loadTexture("gregoriassets.png");
    if(spriteSheet == NULL) {
        printf("Could not load sprite sheet.\n");
        success = false;
    }

    return success;
}


// SDL_Context::loadTexture ////////////////////////////////////////////////
//
// helper function for loadMedia() :: creates a texture from a .png file
//
// @param path          std::string path of the .png file
// @return              pointer to SDL_Texture created

SDL_Texture* SDL_Context::loadTexture(std::string path) {
    // will point to the texture we create
    SDL_Texture* imageTexture = NULL;

    // load the image as a surface
    SDL_Surface* imageSurface = IMG_Load(path.c_str() );

    if(imageSurface == NULL) {
        printf("Could not load image. IMG_Error: %s\n", IMG_GetError() );
    }
    else {
        // convert surface into texture
        imageTexture = SDL_CreateTextureFromSurface(renderer,imageSurface);
        if(imageTexture == NULL) {
            printf("Could not create texture. SDL_Error: %s\n",
                    SDL_GetError() );
        }
    }
    // free the image surface
    SDL_FreeSurface(imageSurface);

    return imageTexture;
}


// SDL_Context::render /////////////////////////////////////////////////////
//
// renders the current world state

void SDL_Context::render(std::vector<Game_Object> state) {
    SDL_RenderClear(renderer);
    for(auto it = state.begin(); it != state.end(); it++) {
        SDL_RenderCopy(renderer, spriteSheet,
                &spritemap[it->get_current_sprite()],
                it->get_spriteLocation());
    }
    SDL_RenderPresent(renderer);
}
