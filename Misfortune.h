#include <string>
#include "Supplies.h"
#include "Player.h"

using namespace std;
 #ifndef Misfortune_H
 #define Misfortune_H
class Misfortune{
    //public members
    public:
        Misfortune();
        Misfortune(Supplies initialSupplies,Player player,Miles miles);
        void isOxenAlive();
        void isWheelPopped();
        void isSick();
        bool isAlive(int probability,string playerName,string disease);
        bool isMisfortune();
        Player returnPlayerObject();
        Supplies returnMisfortuneSupplies();

    //private members
    private:
        Player misfortunePlayer;
        Supplies misfortuneSupplies;
        Miles  milesMisfortune;
};
#endif