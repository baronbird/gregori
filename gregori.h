// gregori.h
//
// for Gregori
// class definition for Gregori and struct definition for plant
//
//      revision history
//      1-11-2017 ::  started
//      1-12-2017 ::  improved collision
//                    added directional "place" functions
//      2-16-2017 ::  added struct "plant" to help with different plant types
//       9-8-2017 ::  documented and cleaned up code
//                ::  replaced the directional move and place functions with single
//                    functions that handled multiple directions
//
// baronbird /////////////////////////////////////////////////////////////////////////////////

#ifndef GREGORI_H
#define GREGORI_H

// gregori ///////////////////////////////////////////////////////////////////////////////////
//
// class interface for the player character
//
// TODO: generalize to any object in the world
// TODO: reimplement Gregori as a child class of the general class

class Gregori {
    public:
        Gregori();
        ~Gregori();
        void updateHitbox();
        int isCollidingWith(SDL_Rect &);
        bool canClimbOn(SDL_Rect &);
        void move(int,int);
        void place(std::string, SDL_Rect &);
        void placeAt(int,int);
        SDL_Rect getRenderRect();
    private:
        // sprite location
        SDL_Rect renderRect;

        // separate rectangles to make collisions more believable
        // essentially, Gregori's "hitbox"
        SDL_Rect head;
        SDL_Rect legs;
        SDL_Rect arms;
};


// constructor for Gregori /////////////////////////////////////////////////////////////////
//
// creates Gregori in his initial size and location

Gregori::Gregori() {
    renderRect.x = renderRect.y = 0; renderRect.w = renderRect.h = 35;
    head.w = 25; head.h = 20; legs.w = 15; legs.h = 10;
    arms.w = 25; arms.h = 10;
    updateHitbox();
}


// deconstructor for Gregori //////////////////////////////////////////////////////////////

Gregori::~Gregori() {}


// Gregori::updateHitbox //////////////////////////////////////////////////////////////////
//
// member function that keeps Gregori's hitbox inline with his sprite

void Gregori::updateHitbox() {
    head.x = renderRect.x + 5; head.y = renderRect.y;
    legs.x = renderRect.x + 10; legs.y = renderRect.y + 25;
    arms.x = renderRect.x + 5; arms.y = renderRect.y + 20;
}


// Gregori::isCollidingWith //////////////////////////////////////////////////////////////
//
// checks for collision between Gregori and a given rectangle
//
// @param theRect           pointer to the rectangle
// @return                  0 if no collision exists
//                          1 if Gregori is colliding with the right side
//                          2 if Gregori is colliding with the top side
//                          3 if Gregori is colliding with the left side
//                          4 if Gregori is colliding with the bottom side
//
// TODO: allow collisions with non-rectangular objects
// TODO: improve current collision mechanics (e.g. the climbing clip)

int Gregori::isCollidingWith(SDL_Rect &theRect) {
    int collision = 0;
    
    // `SDL_IntersectRect` returns a rectangle that represents the intersection
    // between the two rectangles, these two variables are those
    SDL_Rect headResult{0,0,0,0}, legsResult{0,0,0,0};

    // if the head is colliding, we check to see which side is colliding
    if( SDL_IntersectRect(&head,&theRect,&headResult) ) {

        // if the x-coordinate of the collision is the same as that of the rectangle
        // we're checking for collision with, the collision was on the left
        if( headResult.x == theRect.x && head.y < theRect.y + theRect.h - 6) {
            collision = 3;
        }

        // if the head is below the rectangle, the collision was on the bottom
        else if(head.y < theRect.y + theRect.h - 6) {
            collision = 4;
        }

        // otherwise it was on the right side
        else {
            collision = 1;
        }
    }

    // if the legs are colliding, assume it's a collision with the top side of
    // the rectangle
    //
    // TODO: add more outcomes for leg collisions to avoid weird clips
    
    else if( SDL_HasIntersection(&legs,&theRect) ) {
        collision = 2;
    }

    return collision;
}


// Gregori::canClimbOn /////////////////////////////////////////////////////////////////////
//
// checks to see if Gregori can climb on a given rectangle
// Gregori can climb on an object if his arms overlap with it or if a sizeable portion of
// his body overlaps it
//
// @param theIvy            pointer to the rectangle
// @return                  true if Gregori can climb on the rectangle, false otherwise

bool Gregori::canClimbOn(SDL_Rect &theIvy) {
    bool climbable = false;
    
    // collision data variables
    SDL_Rect headResult{0,0,0,0}, legsResult{0,0,0,0};
    SDL_bool headIsColliding, legsAreColliding;
    int area = 0;

    headIsColliding = SDL_IntersectRect(&head,&theIvy,&headResult);
    legsAreColliding = SDL_IntersectRect(&legs,&theIvy,&legsResult);
    
    if( headIsColliding || legsAreColliding ) {
        // compute area of collisions
        area = headResult.w * headResult.h + legsResult.w * legsResult.h;
    }

    if( SDL_HasIntersection(&arms,&theIvy) || area > 175 ) {
        climbable = true;
    }

    return climbable;
}
  

// Gregori::move /////////////////////////////////////////////////////////////////////////////
//
// updates Gregori's position with the given deltaX and deltaY values
//
// @param deltaX            change in the x direction
// @param deltaY            change in the y direction

void Gregori::move(int deltaX, int deltaY) {
    renderRect.x += deltaX;
    renderRect.y += deltaY;
    updateHitbox();
}


// Gregori::place ////////////////////////////////////////////////////////////////////////////
//
// places Gregori in a location relative to a given rectangle
//
// @param where             relative location that Gregori is to be placed at
//                          can be "on", "below", "left of", and "right of"
// @param thePlatform       pointer to the rectangle

void Gregori::place(std::string where, SDL_Rect &thePlatform) {
    if(where == "on") {
        renderRect.y = thePlatform.y - renderRect.h + 1;
    }
    else if(where == "below") {
        renderRect.y = thePlatform.y + thePlatform.h;
    }
    else if(where == "left of") {
        renderRect.x = thePlatform.x - renderRect.w + 6;
    }
    else if(where == "right of") {
        renderRect.x = thePlatform.x + thePlatform.w - 6;
    }
    else {
        printf("'%s' is invalid option for Gregori::place", where.c_str());
    }

    updateHitbox();
}


// Gregori::placeAt //////////////////////////////////////////////////////////////////////////
// 
// place Gregori at specific x- and y-coordinates
//
// @param x                 x-coordinate
// @param y                 y-coordinate

void Gregori::placeAt(int x,int y) {
    renderRect.x = x; renderRect.y = y;
    updateHitbox();
}


// Gregori::getRenderRect ////////////////////////////////////////////////////////////////////
//
// returns the location of Gregori's sprite. to be used in main to render Gregori
//
// @return                  SDL_Rect that contains the size and location of Gregori
SDL_Rect Gregori::getRenderRect() {
    return renderRect;
}


// plant /////////////////////////////////////////////////////////////////////////////////////
//
// keeps track of the source and destination SDL_Rects for rendering, the type, and the
// number of seeds that can be taken from the plant
//
// TODO: restructure as a child of the general world object class
// but for now, a struct will do

struct plant {
    SDL_Rect dst, src;
    char type;
    int numseeds = 0;
};

#endif
