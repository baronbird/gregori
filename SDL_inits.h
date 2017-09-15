// SDL_inits.h
//
// for Gregori
// SDL initialization functions
// much borrowed from  Lazy Foo's SDL tutorials (http://lazyfoo.net/tutorials/SDL/index.php)
//
//        revision history
//        1-11-2017 :: started
//         9-8-2017 :: documented and cleaned up code
//
// baronbird ////////////////////////////////////////////////////////////////////////////////

#ifndef SDL_INITS_H
#define SDL_INITS_H

// global variables (TODO: restructure so these are not necessary)
SDL_Window* gameWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* spriteSheet = NULL;


// init /////////////////////////////////////////////////////////////////////////////////////
//
// initializes SDL, creates window, creates renderer
// 
// @return              true on successful completion, false on some error

bool init() {
    bool success = true;

    // initialize SDL with only the video subsystems
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialize SDL. SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else {
        // create game window with specified settings
        gameWindow = SDL_CreateWindow("Gregori",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
        if(gameWindow == NULL) {
            printf("Could not create window. SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else {
            // create accelerated renderer
            gRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
            if(gRenderer == NULL) {
                printf("Could not create renderer. SDL_Error: %s\n", SDL_GetError() );
                success = false;
            }
            else {
                // initialize SDL_image to load PNGs (our spritesheet is a png)
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) && imgFlags ) ) {
                    printf("Could not initialize SDL_image. IMG_Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}


// loadTexture //////////////////////////////////////////////////////////////////////////////
//
// helper function for loadMedia() :: creates a texture from a .png file
//
// @param path          std::string path of the .png file
// @return              pointer to SDL_Texture created

SDL_Texture* loadTexture(std::string path) {
    // will point to the texture we create
    SDL_Texture* imageTexture = NULL;

    // load the image as a surface
    SDL_Surface* imageSurface = IMG_Load(path.c_str() );

    if(imageSurface == NULL) {
        printf("Could not load image. IMG_Error: %s\n", IMG_GetError() );
    }
    else {
        // convert surface into texture
        imageTexture = SDL_CreateTextureFromSurface(gRenderer,imageSurface);
        if(imageTexture == NULL) {
            printf("Could not create texture. SDL_Error: %s\n", SDL_GetError() );
        }
    }
    // free the image surface
    SDL_FreeSurface(imageSurface);

    return imageTexture;
}


// loadMedia ////////////////////////////////////////////////////////////////////////////////
//
// loads all necessary textures (currently only one!)
//
// @return              true on successful completion, false on some error

bool loadMedia() {
    bool success = true;

    spriteSheet = loadTexture("gregoriassets.png");
    if(spriteSheet == NULL) {
        printf("Could not load sprite sheet.\n");
        success = false;
    }

    return success;
}


// close ///////////////////////////////////////////////////////////////////////////////////
// 
// frees all resources allocated on the heap, because no one like memory leaks, especially
// not me!

void close() {
    SDL_DestroyTexture(spriteSheet);
    spriteSheet = NULL;

    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gameWindow);
    gRenderer = NULL;
    gameWindow = NULL;
}

#endif
