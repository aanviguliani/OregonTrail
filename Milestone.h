#include <string>
#include "Supplies.h"

using namespace std;
 #ifndef Milestone_H
 #define Milestone_H
class Milestone{
    //public members
    public:
        Milestone();
        Milestone(Miles mileage,Supplies supply,Player play);
        void setMilestonesPassed();
        int getMilestonesPassed();
        bool isMilestone(int milestoneMiles,int milesTravelled);
        void milestoneFunction(int milestoneMiles,int numMilestonesPassed);
        Supplies goToRiver();
        int getNextMilestone();
        bool isRiver(string milestoneName);
        void milestoneStore();
        void setMilestone(int numMilestones);
        void printNextMilestone();
        void getNextMilestoneRiver(string milestoneName,int milestoneMiles);
        void getNextMilestoneFort(string milestoneName,int milestoneMiles);
        Supplies returnSuppliesObject();
        Miles returnMilesObject();
        
        
    //private members
    private:
        Miles milestoneMilesObject;
        int numMilestonesPassed;
        Supplies milestoneSupplyObject;
        Player milestonePlayerObject;
        string milestoneName;

};
#endif