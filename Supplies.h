#include <string>

using namespace std;
 #ifndef Supplies_H
 #define Supplies_H
class Supplies{
    //public members
    public:
        Supplies();
        Supplies(int money,int oxen,int food,int bullets,int wheels,int tongues,int axles,int wagons,int aidKit);
        void setMoney(int m);
        void setOxen(int o);
        void setBullets(int b);
        void setFood(int p);
        void setWheel(int w);
        void setTongue(int t);
        void setAxle(int a);
        void setWagon(int wagons);
        void setAidKit(int a);
        int getMoney();
        int getOxen();
        int getBullets();
        int getFood();
        int getWheel();
        int getTongue();
        int getAxle();
        int getWagon();
        int getAidKit();
        
    //private members
    private:
       int amtMoney;
       int numOxen;
       int poundsFood;
       int numBullets;
       int numWheels;
       int numAxle;
       int numTongues;
       int numWagons;
       int numAidKits;
       
        
        
};
#endif