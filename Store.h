#include <string>
#include "Supplies.h"

using namespace std;
 #ifndef STORE_H
 #define STORE_H
class Store{
    //public members
    public:
        Store();
        Store(Supplies initialSupplies);
        Supplies goToStore();
        
        
    //private members
    private:
        Supplies storeSupplies;
};
#endif