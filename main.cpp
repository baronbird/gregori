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
//
///////////////////////////////////////////////////////////////////////////////////////////////

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdio.h>
#include<unistd.h>
#include<string>
#include<cmath>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define ANIMAX 4
#include"SDL_inits.h"
#include"gregori.h"

int main(int argc, char* argv[])
{
  if(!init() )
  {
    printf("Could not initialize SDL. SDL_Error: %s\n", SDL_GetError() );
  }
  else if(!loadMedia() )
  {
    printf("Could not load media. SDL_Error: %s\n", SDL_GetError() );
  }
  else
  {
    // control variables
    bool quit{false}, noControls{true}, specialAnimation{false};
    SDL_Event e;
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    int animation = ANIMAX;

    // Gregori's variables
    Gregori greg;
    SDL_Rect gregSrc{0,0,7,7}, gregDst;
    int frame{0}, deltaX{0}, deltaY{0}, jumps{2};
    bool onPlatform{false}, inTheIvy{false}, jumping{false}, animation_switch{false};
    bool onTheIvy{false}, climbing{false}, interacting{false};

    // plant variables
    plant titlePlant;
    titlePlant.dst = {575,351,35,45};
    titlePlant.src = {98,0,7,9};
    titlePlant.type = 'g';
    titlePlant.numseeds = 3;

    // seed inventory
    plant seeds[8];
    for(int i = 0; i < 8; i++)
    {
      seeds[i].dst = {15 + 25 * i,435,20,25};
      seeds[i].src = {0,0,0,0};
      seeds[i].type = 0;
    }

    // platform variables
    SDL_Rect platformDst[10], platformSrc{0,7,16,3};
    for(int i = 0; i < 10; i++)
    {
      platformDst[i].x = -40 + (80 * i);
      platformDst[i].y = 395;
      platformDst[i].w = 80;
      platformDst[i].h = 15;
    }
    platformDst[9].x = 280;
    platformDst[9].y = 315;

    // ivy variables
    SDL_Rect titleDst{147,70,345,130}, titleSrc{0,10,69,26}, ivyRect[7];
    ivyRect[0].x = titleDst.x + 10; ivyRect[0].y = titleDst.y + 45;
    ivyRect[0].w = 60; ivyRect[0].h = 30;
    ivyRect[1].x = titleDst.x + 75; ivyRect[1].y = titleDst.y + 35;
    ivyRect[1].w = 35; ivyRect[1].h = 5;
    ivyRect[2].x = titleDst.x + 115; ivyRect[2].y = titleDst.y + 40;
    ivyRect[2].w = 45; ivyRect[2].h = 30;
    ivyRect[3].x = titleDst.x + 165; ivyRect[3].y = titleDst.y + 65;
    ivyRect[3].w = 25; ivyRect[3].h = 15;
    ivyRect[4].x = titleDst.x + 190; ivyRect[4].y = titleDst.y + 80;
    ivyRect[4].w = 10; ivyRect[4].h = 15;
    ivyRect[5].x = titleDst.x + 175; ivyRect[5].y = titleDst.y + 100;
    ivyRect[5].w = 45; ivyRect[5].h = 20;

    // text box variables
    SDL_Rect enterDst{501,285,104,52}, enterSrc{0,36,52,26};
    int textBoxFrame{0};

    //status updates
    SDL_SetRenderDrawColor(gRenderer,0x00,0x00,0x00,0x00);
    greg.placeAt(30,361);

    while(!quit)
    {
      // event controls
      while(SDL_PollEvent(&e) != 0)
      {
        if(e.type == SDL_QUIT)
        {
          quit = true;
          noControls = false;
        }
      }

      // key state controls
      if(currentKeyStates[SDL_SCANCODE_UP])
      {
        if(onTheIvy && !inTheIvy)
        {
          inTheIvy = true;
        }
        if(inTheIvy)
        {
          deltaY = -1;
        }
        noControls = false;
      }
      else if(currentKeyStates[SDL_SCANCODE_DOWN])
      {
        if(inTheIvy)
        {
          deltaY = 1;
        }
        else
        {
          if(animation == 0) if(deltaY < 10) deltaY ++;
        }
        noControls = false;
      }
      if(currentKeyStates[SDL_SCANCODE_LEFT])
      {
        if(inTheIvy)
        {
          deltaX = -1;
        }
        else
        {
          deltaX -= 3;
        }
        noControls = false;
      }
      else if(currentKeyStates[SDL_SCANCODE_RIGHT])
      {
        if(inTheIvy)
        {
          deltaX = 1;
        }
        else
        {
          deltaX += 3;
        }
        noControls = false;
      }
      if(currentKeyStates[SDL_SCANCODE_Z])
      {
        if(inTheIvy)
        {
          inTheIvy = false;
          if(!currentKeyStates[SDL_SCANCODE_DOWN])
          {
            greg.moveVertically(-1);
            deltaY = - 5;
            animation = 2;
          }
        }
        else if(!jumping && jumps > 0)
        {
          greg.moveVertically(-1);
          deltaY = -5;
          jumps--;
          animation = 2;
        }
        jumping = true;
        noControls = false;
      }
      if(currentKeyStates[SDL_SCANCODE_X])
      {
        if(greg.isCollidingWith(titlePlant.dst))
        {
          if(titlePlant.numseeds > 0)
          {
            if(!interacting)
            {
              for(int i = 0; i < 8; i++)
              {
                if(seeds[i].type == 0)
                {
                  seeds[i].type = titlePlant.type;
                  titlePlant.numseeds--;
                  break;
                }
              }
            }
          }
        }
        else
        {
          if(!interacting)
          {
            if(seeds[0].type != 0)
            {
              printf("planted seed!\n");
              for(int i = 0; i < 7; i++)
              {
                seeds[i].type = seeds[i+1].type;
              }
              seeds[7].type = 0;
            }
          }
        }
        interacting = true;
      }

      if(!inTheIvy && !onPlatform) noControls = false;

      // physics
      if(animation == 0)
      {
        if(!inTheIvy)
        {
          if(deltaY < 10) deltaY++;
        }
      }

      greg.moveVertically(deltaY);
      greg.moveHorizontally(deltaX);
      
      onPlatform = false;
      for(int i = 0; i < 10; i++)
      {
        if(greg.isCollidingWith(platformDst[i]) )
        {
          if(greg.isCollidingWith(platformDst[i]) == 2)
          {
            greg.placeOn(platformDst[i]);
            jumps = 2;
            onPlatform = true;
            deltaY = 0;
          }
          else if(greg.isCollidingWith(platformDst[i]) == 1)
          {
            greg.placeBelow(platformDst[i]);
            if(deltaY < 0) deltaY = 0;
          }
          else if(greg.isCollidingWith(platformDst[i]) == 3)
          {
            greg.placeLeftOf(platformDst[i]);
            deltaX = 0;
          }
          else if(greg.isCollidingWith(platformDst[i]) == 4)
          {
            greg.placeRightOf(platformDst[i]);
            deltaX = 0;
            if(currentKeyStates[SDL_SCANCODE_LEFT]) specialAnimation = true;
          }
        }
      }

      onTheIvy = false;
      for(int i = 0; i < 7; i++)
      {
        if(greg.canClimbOn(ivyRect[i]) )
        {
          onTheIvy = true;
        }
      }
      if(!onTheIvy)
      {
        if(inTheIvy)
        {
          greg.moveHorizontally(-deltaX);
          onTheIvy = false;
          for(int i = 0; i < 7; i++)
          {
            if(greg.canClimbOn(ivyRect[i]) )
              onTheIvy = true;
          }
          if(!onTheIvy)
          {
            greg.moveVertically(-deltaY);;
            greg.moveHorizontally(deltaX);
            onTheIvy = false;
            for(int i = 0; i < 7; i++)
            {
              if(greg.canClimbOn(ivyRect[i]) )
                onTheIvy = true;
            }
            if(!onTheIvy)
            {
              greg.placeAt(gregDst.x,gregDst.y);
            }
          }
        }
      }

      // update animations
      if(onPlatform)
      {
        if(deltaX < 0) frame = ((animation_switch) ? 3 : 4);
        else if(deltaX > 0) frame = ((animation_switch) ? 1 : 2);
        else frame = 0;
      }
      else if(inTheIvy)
      {
        if(deltaX < 0)
        {
          if(deltaY > 0) frame = ((climbing) ? 5 : 13);
          else if(deltaY < 0) frame = ((climbing) ? 8 : 13);
          else frame = ((climbing) ? 9 : 10);
        }
        else if(deltaX > 0)
        {
          if(deltaY > 0) frame = ((climbing) ? 8 : 13);
          else if(deltaY < 0) frame = ((climbing) ? 5 : 13);
          else frame = ((climbing) ? 6 : 7);
        }
        else
        {
          if(deltaY != 0) frame = ((climbing) ? 11 : 12);
          else if(frame < 11) frame = 13;
        }
      }
      else
      {
        if(deltaX < 0 || specialAnimation) frame = 3;
        else frame = 1;
      }

      gregSrc.x = frame * 7;

      for(int i = 0; i < 8; i++)
      {
        if(seeds[i].type == 'g')
        {
          seeds[i].src = {105,0,4,5};
        }
        else if(seeds[i].type == 0)
        {
          seeds[i].src = {0,0,0,0};
        }
      }

      // catch edges
      gregDst = greg.getRenderRect();
      if(gregDst.x >= 610)
      {
        if(deltaX > 0) deltaX = 0;
        greg.placeAt(610,gregDst.y);
      }
      else if(gregDst.x <= -5)
      {
        if(deltaX < 0) deltaX = 0;
        greg.placeAt(-5,gregDst.y);
      }

      // update position
      gregDst = greg.getRenderRect();
      enterDst.y = 285 + 3 * sin(textBoxFrame * M_PI/60);

      // render to screen
      SDL_RenderClear(gRenderer);
      if(greg.isCollidingWith(titlePlant.dst) && titlePlant.numseeds > 0)
        SDL_RenderCopy(gRenderer,spriteSheet,&enterSrc,&enterDst);
      SDL_RenderCopy(gRenderer,spriteSheet,&titleSrc,&titleDst);
      SDL_RenderCopy(gRenderer,spriteSheet,&titlePlant.src,&titlePlant.dst);
      for(int i = 0; i < 10; i++)
      {
        SDL_RenderCopy(gRenderer,spriteSheet,&platformSrc,&platformDst[i]);
      }
      for(int i = 0; i < 8; i++)
      {
        SDL_RenderCopy(gRenderer,spriteSheet,&seeds[i].src,&seeds[i].dst);
      }
      SDL_RenderCopy(gRenderer,spriteSheet,&gregSrc,&gregDst);
      SDL_RenderPresent(gRenderer);

      //status updates
      deltaX = 0;
      if(inTheIvy) deltaY = 0;
      if(!currentKeyStates[SDL_SCANCODE_Z])
        jumping = false;
      if(!currentKeyStates[SDL_SCANCODE_X])
        interacting = false;
      if(animation == 0)
      {
        if(animation_switch) climbing = !climbing;
        animation_switch = !animation_switch;
        animation = ANIMAX;
      } else if(!noControls) animation--;
      if(textBoxFrame == 119)
      {
        textBoxFrame = 0;
      } else textBoxFrame++;
      specialAnimation = false;

      // wait
      usleep(16666);
    }
  }

  close();
}
