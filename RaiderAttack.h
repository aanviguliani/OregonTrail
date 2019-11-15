#include <string>
#include "Supplies.h"
#include "Miles.h"

using namespace std;
 #ifndef RaiderAttack_H
 #define RaiderAttack_H
class RaiderAttack{
    //public members
    public:
        RaiderAttack();
        RaiderAttack(Supplies initialSupplies, Miles miles);
        Supplies isRaiderAttack();
        void raiderAttackFunction();
        
        
    //private members
    private:
        Supplies raiderAttackSupplies;
        Miles raiderAttackMiles;
        int probability;
        
};
#endif