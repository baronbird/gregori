// gregori.h
//
// for Gregori
// class definition for Gregori (singleton class)
//
//      revision history
//      1-11-2017 ::  started
//      1-12-2017 ::  improved collision
//                    added directional "place" functions

class Gregori
{
  public:
    Gregori();
    ~Gregori();
    void updatePosition();
    int isCollidingWith(SDL_Rect &);
    bool canClimbOn(SDL_Rect &);
    void moveHorizontally(int);
    void moveVertically(int);
    void placeOn(SDL_Rect &);
    void placeBelow(SDL_Rect &);
    void placeLeftOf(SDL_Rect &);
    void placeRightOf(SDL_Rect &);
    void placeAt(int,int);
    SDL_Rect getRenderRect();
  private:
    SDL_Rect renderRect;
    SDL_Rect head;
    SDL_Rect legs;
    SDL_Rect climbRect;
};

Gregori::Gregori()
{
  renderRect.x = renderRect.y = 0; renderRect.w = renderRect.h = 35;
  head.w = 25; head.h = 20; legs.w = 15; legs.h = 10;
  climbRect.w = 25; climbRect.h = 10;
  updatePosition();
}

Gregori::~Gregori() {}

void Gregori::updatePosition()
{
  head.x = renderRect.x + 5; head.y = renderRect.y;
  legs.x = renderRect.x + 10; legs.y = renderRect.y + 25;
  climbRect.x = renderRect.x + 5; climbRect.y = renderRect.y + 20;
}

int Gregori::isCollidingWith(SDL_Rect &theRect)
{
  int colliding = 0;
  SDL_Rect headResult{0,0,0,0}, legsResult{0,0,0,0};

  if( SDL_IntersectRect(&head,&theRect,&headResult) ) 
  {
    colliding = 1;
    if( headResult.x == theRect.x && head.y <theRect.y + theRect.h - 6)
      colliding = 3;
    else if(head.y < theRect.y + theRect.h - 6)
      colliding = 4;;
  }
  if( SDL_HasIntersection(&legs,&theRect) ) colliding = 2;

  return colliding;
}

bool Gregori::canClimbOn(SDL_Rect &theIvy)
{
  bool climbable = false;
  SDL_Rect headResult{0,0,0,0}, legsResult{0,0,0,0};
  int area = 0;
  if(SDL_IntersectRect(&head,&theIvy,&headResult) || SDL_IntersectRect(&legs,&theIvy,&legsResult) )
    area = headResult.w * headResult.h + legsResult.w * legsResult.h;

  if( SDL_HasIntersection(&climbRect,&theIvy) ) climbable = true;
  if( area > 175 ) climbable = true;

  return climbable;
}
  


void Gregori::moveHorizontally(int deltaX)
{
  renderRect.x += deltaX;
  updatePosition();
}

void Gregori::moveVertically(int deltaY)
{
  renderRect.y += deltaY;
  updatePosition();
}

void Gregori::placeOn(SDL_Rect &thePlatform)
{
  renderRect.y = thePlatform.y - renderRect.h + 1;
  updatePosition();
}

void Gregori::placeBelow(SDL_Rect &thePlatform)
{
  renderRect.y = thePlatform.y + thePlatform.h;
  updatePosition();
}

void Gregori::placeLeftOf(SDL_Rect &thePlatform)
{
  renderRect.x = thePlatform.x - renderRect.w + 6;
  updatePosition();
}

void Gregori::placeRightOf(SDL_Rect &thePlatform)
{
  renderRect.x = thePlatform.x + thePlatform.w - 6;
  updatePosition();
}

void Gregori::placeAt(int x,int y)
{
  renderRect.x = x; renderRect.y = y;
  updatePosition();
}

SDL_Rect Gregori::getRenderRect()
{
  return renderRect;
}
