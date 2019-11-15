//include statements
#include <iostream>
#include <iomanip>
#include "Supplies.h"

using namespace std;

//constructor
Store::Store()
{
   storeSupplies.setAidKit(0);
   storeSupplies.setBullets(0);
   storeSupplies.setMoney(1000);
   storeSupplies.setOxen(0);
   storeSupplies.setFood(0);
   storeSupplies.setWagon(1);
   storeSupplies.setWheel(0);
   storeSupplies.setTongue(0);
   storeSupplies.setAxle(0);
   
}

Store::Store(Supplies initialSupplies){
    storeSupplies = initialSupplies;
    
}

Supplies Store::goToStore()
{
    //initialize vars
    int amtMoney = 1000;
    int numOxen = 0;
    int numYokes = 0;
    int poundsFood = 0;
    int numBullets = 0;
    int numParts = 0;
    int numWagons = 1;
    int numAidKits = 0;
    int bill = 0;
    
    //do while: repeats if end bill is greater than 1000
    do{
        cout << "YOU HAD SAVED $1200 TO SPEND FOR THE TRIP, AND YOU'VE INITIALLY PAID $200 FOR A WAGON. YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE FOLLOWING ITEMS: " << endl;
        cout << "- OXEN. YOU CAN SPEND $100-$200 ON YOUR TEAM. THE MORE YOU SPEND, THE FASTER YOU'LL GO BECAUSE YOU'LL HAVE BETTER ANIMALS" << endl;
        cout << "- FOOD. THE MORE YOU HAVE, THE LESS CHANCE THERE IS OF GETTING SICK" << endl;
        cout << "- BULLETS - $2 BUYS A BELT OF 20 BULLETS. YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS AND BANDITS, AND FOR HUNTING FOOD" << endl;
        cout << "- MISCELLANEOUS SUPPLIES. THIS INCLUDES MEDICINE AND OTHER THINGS YOU WILL NEED FOR SICKNESS AND EMERGENCY REPAIRS" << endl;
        cout << "YOU CAN SPEND ALL YOUR MONEY BEFORE YOU START YOUR TRIP, OR YOU CAN SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG THE WAY WHEN YOU RUN LOW. HOWEVER, ITEMS COST MORE AT THE FORTS. YOU CAN ALSO GO HUNTING ALONG THE WAY TO GET MORE FOOD. " << endl;
        cout << "Right now you have: $1000." << endl;
        cout << "You must spend between $100 to $200 dollars on oxen. There are 2 oxen in a yoke and the price of each yoke is $40.0." << endl;
        
        //yokes
        cout << "How many yokes do you wish to purchase?: ";
        cin >> numYokes;
        cout << endl;
        numOxen = numYokes * 2;
        bill = numYokes * 40;
        while(bill < 100)
        {
            cout << "You have chosen to spend less than $100 on yokes, please choose again. ";
            cout << "How many yokes do you wish to purchase?: " << endl;
            cin >> numYokes;
            bill = numYokes * 40;
        }
        while(bill > 200)
        {
            cout << "You have chosen to spend more than $200 on yokes, please choose again. ";
            cout << "How many yokes do you wish to purchase?: " << endl;
            cin >> numYokes;
            bill = numYokes * 40;
        }
        cout << endl;
        numOxen = numYokes * 2;
        storeSupplies.setOxen(numYokes);
        cout << "Your current bill is: " << bill << endl;
        
        //pounds food
        cout << "I recommend at least 200 lbs. per person at the price of $0.5 per pound. Remember the wagon cannot hold more than 1000 lbs. of food. " << endl;
        do
        {
            cout << "How many pounds of food do you wish to purchase?:";
            cin >> poundsFood;
            storeSupplies.setFood(poundsFood);
            
        }
        while(poundsFood > 1000);
        cout << endl;
        bill = bill + (0.5* poundsFood);
        cout << endl;
        cout << "Your current bill is: " << bill << endl;
        
        //bullets
        cout << "A box of 20 bullets costs $2.0." << endl;
        cout << "How many boxes do you wish to purchase?: ";
        cin >> numBullets;
        storeSupplies.setBullets(numBullets * 20);
        cout << endl;
        cout << endl;
        bill = bill + (numBullets * 2);
        cout << endl;
        cout << "Your current bill is: " << bill << endl;
        
        //parts
        cout << "A wagon part (wheels, axels, tongues) costs $10.0." << endl;
        cout << "How many parts do you wish to purchase?: ";
        cin >> numParts;
        storeSupplies.setWheel(numParts);
        storeSupplies.setAxle(numParts);
        storeSupplies.setTongue(numParts);
        cout << endl;
        bill = bill + (numParts * 10);
        cout << endl;
        cout << "Your current bill is: " << bill << endl;
        
        //aid kit
        cout << "A medical aid kit costs $15.0." << endl;
        cout << "How many kits do you wish to purchase?: ";
        cin >> numAidKits;
        storeSupplies.setAidKit(numAidKits);
        bill = bill + (numAidKits * 15);
        cout << endl;
        cout << endl;
        cout << "Your final bill is: " << bill << endl;
        
        amtMoney = amtMoney - bill;
        cout << "You finally have: " << amtMoney << " Thank you for visiting the store " << endl;
        storeSupplies.setMoney(amtMoney);
    }
    while(bill > 1000);
    
    return storeSupplies;
}