// Gregori.h
//
// for Gregori
// inherited class from Game_Object that represents Gregori
//
// revision history:
//          10/08/2017 :: started
//
// baronbird ///////////////////////////////////////////////////////////////

#include"Game_Object.h"

class Gregori : public Game_Object {
    public:
        Gregori(int, int);
        ~Gregori();
        void control(const Uint8*);
        void updateAnimation();
        void updatePosition();
        
    private:
        SDL_Point velocity;
        int num_seeds;

};
