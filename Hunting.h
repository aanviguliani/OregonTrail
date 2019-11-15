#include <string>
#include "Supplies.h"
#include "Player.h"

using namespace std;
 #ifndef Hunting_H
 #define Hunting_H
class Hunting{
    //public members
    public:
        Hunting();
        Hunting(Supplies initialSupplies,Player playerObject); //hunting parameterized constructor
        void isFoxHunt(); //check if fox is hunted
        void isDeerHunt(); //check if der is hunted
        void isRabbitHunt(); //check if rabbit hunted
        void isMooseHunt();//check if moose hunted
        void isBearHunt();//check if bear hunted
        Supplies goHunting();//hunting function
        
    //private members
    private:
        int deer;
        int fox;
        int rabbit;
        int bear;
        int moose;
        int numBullets;
        int pounds;
        int poundsHunted;
        Supplies huntingSupplies;
        Player huntingPlayer;
        
        
};
#endif