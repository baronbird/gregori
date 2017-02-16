// SDL_inits.h
//
// for Gregori
// don't clog up main with SDL initialization
//
//        revision history
//        1-11-2017 :: started
//
//////////////////////////////////////////////////////////////////////////////////////////////

SDL_Window* gameWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* spriteSheet = NULL;

bool init()
{
  bool success = true;

  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("Could not initialize SDL. SDL_Error: %s\n", SDL_GetError() );
    success = false;
  }
  else
  {
    gameWindow = SDL_CreateWindow("Gregori",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
    if(gameWindow == NULL)
    {
      printf("Could not create window. SDL_Error: %s\n", SDL_GetError() );
      success = false;
    }
    else
    {
      gRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
      if(gRenderer == NULL)
      {
        printf("Could not create renderer. SDL_Error: %s\n", SDL_GetError() );
        success = false;
      }
      else
      {
        SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);

        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) && imgFlags ) )
        {
          printf("Could not initialize SDL_image. IMG_Error: %s\n", IMG_GetError() );
          success = false;
        }
      }
    }
  }

  return success;
}

SDL_Texture* loadTexture(std::string path)
{
  SDL_Texture* newTexture = NULL;
  SDL_Surface* loaded = IMG_Load(path.c_str() );
  if(loaded == NULL)
  {
    printf("Could not load image. IMG_Error: %s\n", IMG_GetError() );
  }
  else
  {
    newTexture = SDL_CreateTextureFromSurface(gRenderer,loaded);
    if(newTexture == NULL)
    {
      printf("Could not create texture. SDL_Error: %s\n", SDL_GetError() );
    }
  }
  SDL_FreeSurface(loaded);

  return newTexture;
}

bool loadMedia()
{
  bool success = true;

  spriteSheet = loadTexture("gregoriassets.png");
  if(spriteSheet == NULL)
  {
    printf("Could not load sprite sheet.\n");
    success = false;
  }

  return success;
}

void close()
{
  SDL_DestroyTexture(spriteSheet);
  spriteSheet = NULL;

  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gameWindow);
  gRenderer = NULL;
  gameWindow = NULL;
}
