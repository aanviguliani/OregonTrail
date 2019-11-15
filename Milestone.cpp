//include statements
#include <iostream>
#include <iomanip>
#include "Milestone.h"
#include "Player.h"
#include "Miles.h"
#include "Supplies.h"

using namespace std;

//split function
int split(string str, char c, string array[], int size)
 {
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count ;
 }

Milestone::Milestone()
{
    
}

//parameterized constructor
Milestone::Milestone(Miles mileage,Supplies supply,Player play)
{
    milestoneMilesObject = mileage;
    milestoneSupplyObject = supply;
    milestonePlayerObject = play;
}

//check to see if it is milestone
bool Milestone::isMilestone(int milestoneMiles,int milesTravelled)
{
    if(milesTravelled > milestoneMiles)
    {
        numMilestonesPassed++;
        return true;
    }
    
    else
        return false;
}

//get the number of miles to next milestone
int Milestone::getNextMilestone()
{
    ifstream myfilestream;
    string line;
    string milestoneMilesString;
    string arr[3];
    string nextMilestone;
    myfilestream.open("Milestones.txt");
    for(int i = 0; i < 10; i++)
    {
        getline(myfilestream,line);
        if(numMilestonesPassed == i)
        {
            nextMilestone = line;
            break;
        }
    }

    split(nextMilestone,',',arr,3);
    
    milestoneMilesString = arr[1];
    int milestoneMiles = stoi(milestoneMilesString);
    
    return milestoneMiles;
}

//store if milestone is fort
void Milestone::milestoneStore()
{
    int amtMoney = 1000;
    int numOxen = 0;
    int numYokes = 0;
    int poundsFood = 0;
    int numBullets = 0;
    int numParts = 0;
    int numWagons = 1;
    int numAidKits = 0;
    int bill = 0;
    
    do{
        //yokes
        cout << "There are 2 oxen in a yoke and the price of each yoke is $50.0." << endl;
        cout << "How many yokes do you wish to purchase?: ";
        cin >> numYokes;
        cout << endl;
        numOxen = numYokes * 2;
        bill = numYokes * 50;
        cout << endl;
        cout << "Your current bill is: " << bill << endl;
        
        //pounds food
        cout << "Food is $0.625 per pound. Remember the wagon cannot hold more than 1000 lbs. of food. " << endl;
        do
        {
            cout << "How many pounds of food do you wish to purchase?:";
            cin >> poundsFood;
            
        }
        while(poundsFood > 1000);
        cout << endl;
        bill = bill + (0.625* poundsFood);
        cout << endl;
        cout << "Your current bill is: " << bill << endl;
        
        //bullets
        cout << "A box of 20 bullets costs $2.5." << endl;
        cout << "How many boxes do you wish to purchase?: ";
        cin >> numBullets;
        cout << endl;
        cout << endl;
        bill = bill + (numBullets * 2.5);
        cout << endl;
        cout << "Your current bill is: " << bill << endl;
        
        //parts
        cout << "A wagon part (wheels, axels, tongues) costs $12.5." << endl;
        cout << "How many parts do you wish to purchase?: ";
        cin >> numParts;
        cout << endl;
        bill = bill + (numParts * 12.5);
        cout << endl;
        cout << "Your current bill is: " << bill << endl;
        
        //aid kit
        cout << "A medical aid kit costs $18.75." << endl;
        cout << "How many kits do you wish to purchase?: ";
        cin >> numAidKits;
        bill = bill + (numAidKits * 18.75);
        cout << endl;
        cout << endl;
        cout << "Your final bill is: " << bill << endl;
        
        amtMoney = amtMoney - bill;
        cout << "You finally have: " << amtMoney << " Thank you for visiting the store " << endl;
    }
    while(bill > 1000);
}

//milestone function that interrupts regular flow of game
void Milestone::milestoneFunction(int milestoneMiles,int numMilestonesPassed)
{
    //cout << numMilestonesPassed << endl;
    ifstream myfilestream;
    myfilestream.open("Milestones.txt");
    string line;
    string nextMilestone;
    string arr[3];
    string milestoneMilesString;
    
    for(int i = 0; i < 10; i++)
    {
        getline(myfilestream,line);
        
        if(numMilestonesPassed == i)
        {
            nextMilestone = line;
            break;
        }
    }
    //cout << nextMilestone << endl;

    split(nextMilestone,',',arr,3);
    
    milestoneName = arr[0];
    milestoneMilesString = arr[1];
    bool isItRiver = isRiver(milestoneName);
    int riverDepth = 0;
    if(isItRiver)
    {
        riverDepth = stoi(arr[2]);
    }
    
    
    cout << "On the way, you have reached the " << milestoneName << ". You have only travelled " << milestoneMiles << " miles." << endl;
    cout << endl;
    int newNumDays = milestoneMilesObject.getDay() + 14;
    int newMonth = milestoneMilesObject.getMonth();
    int newYear = milestoneMilesObject.getYear();
    milestoneMilesObject.setDate(newNumDays,newMonth,newYear);
    int newMiles = milestoneMilesObject.getNumMiles() + milestoneMiles;
    milestoneMilesObject.setNumMiles(newMiles);
    int newNextMilestone = getNextMilestone() -milestoneMilesObject.getNumMiles();
    int newFood = milestoneSupplyObject.getFood() - (14 * milestonePlayerObject.getNumPlayers() * 3);
    milestoneSupplyObject.setFood(newFood);
    
    //display current status
    cout << "------- CURRENT STATUS -------" << endl;
    cout << "Current Date: " << milestoneMilesObject.getYear() << "-" << milestoneMilesObject.getMonth() << "-" << milestoneMilesObject.getDay() << "|";
    cout << " Miles Travelled: " << milestoneMilesObject.getNumMiles() << "|";
    cout << " Next Landmark: " << newNextMilestone << "|";
    cout << " Food: " << milestoneSupplyObject.getFood() << "|";
    cout << " Bullets: " << milestoneSupplyObject.getBullets() << "|";
    cout << " Cash: " << milestoneSupplyObject.getMoney() << endl;
    
    cout << milestoneMilesObject.getYear() << "-" << milestoneMilesObject.getMonth() << "-" << milestoneMilesObject.getDay() << endl;
    cout << "You have arrived at: " << milestoneName << endl;
    bool isRiverMilestone = isRiver(milestoneName);
    if(isRiverMilestone)
    {
        
        cout << "This is a river. It is " << riverDepth << " ft deep." << endl;
        
        int riverCrossChoice = 0;
        do{
            cout << "1. Rest; 2. Cross" << endl;
            cin >> riverCrossChoice;
        
            if(riverCrossChoice == 1)
            {
                cout << "You have chosen to rest for one day. Food will be consumed accordingly" << endl;
                int numPlayers = milestonePlayerObject.getNumPlayers();
                int newFoodMilestone = milestoneSupplyObject.getFood() - (3 * numPlayers);
                milestoneSupplyObject.setFood(newFoodMilestone);
            }
        }
        while (riverCrossChoice != 2);
        
        if(riverCrossChoice ==2)
        {
            if(riverDepth >= 3)
            {
                cout << "You will need a ferry for $10 per player to cross this river" << endl;
                int newMoney = milestoneSupplyObject.getMoney() - (10 * milestonePlayerObject.getNumPlayers());
                milestoneSupplyObject.setMoney(newMoney);
            }
            
            else
            {
                cout << "You have crossed the river!" << endl;
            }
        }
        
        int newFood = milestoneSupplyObject.getFood() - (14 * 3 * milestonePlayerObject.getNumPlayers());
        int newDay = milestoneMilesObject.getDay() + 14;
        milestoneMilesObject.setDate(newDay,milestoneMilesObject.getMonth(),milestoneMilesObject.getYear());
        milestoneSupplyObject.setFood(newFood);
    }
    
    else
    {
        int fortRestChoice = 0;
        cout << "This is a fort." << endl;
        do{
            cout << "1. Rest; 2. Visit Store; 3. Continue" << endl;
            cin >> fortRestChoice;
        
            if(fortRestChoice == 1)
            {
                cout << "You have chosen to rest for one day. Food will be consumed accordingly" << endl;
                int numPlayers = milestonePlayerObject.getNumPlayers();
                int newFoodMilestone = milestoneSupplyObject.getFood() - (3 * numPlayers);
                milestoneSupplyObject.setFood(newFoodMilestone);
            }
        }
        while (fortRestChoice == 1);
        
        if(fortRestChoice == 2)
        {
            milestoneStore();
        }
        
        else if(fortRestChoice == 3)
        {
            cout << "You have chosen to continue" << endl;
            int newNumDays = milestoneMilesObject.getDay() + 14;
            int newMonth = milestoneMilesObject.getMonth();
            int newYear = milestoneMilesObject.getYear();
            milestoneMilesObject.setDate(newNumDays,newMonth,newYear);
            int newMiles = milestoneMilesObject.getNumMiles() + milestoneMiles;
            milestoneMilesObject.setNumMiles(newMiles);
            int newNextMilestone = getNextMilestone() -milestoneMilesObject.getNumMiles();
            int newFood = milestoneSupplyObject.getFood() - (14 * milestonePlayerObject.getNumPlayers() * 3);
            milestoneSupplyObject.setFood(newFood);
            
            //display current status
            cout << "------- CURRENT STATUS -------" << endl;
            cout << "Current Date: " << milestoneMilesObject.getYear() << "-" << milestoneMilesObject.getMonth() << "-" << milestoneMilesObject.getDay() << "|";
            cout << " Miles Travelled: " << milestoneMilesObject.getNumMiles() << "|";
            cout << " Next Landmark: " << newNextMilestone << "|";
            cout << " Food: " << milestoneSupplyObject.getFood() << "|";
            cout << " Bullets: " << milestoneSupplyObject.getBullets() << "|";
            cout << " Cash: " << milestoneSupplyObject.getMoney() << endl;
        }
    }
    
    
}

//set num milestones passed
void Milestone::setMilestone(int numMilestones)
{
    numMilestonesPassed = numMilestones;
}

//get num milestones passed
int Milestone::getMilestonesPassed()
{
    return numMilestonesPassed;
}



void Milestone::printNextMilestone()
{
    ifstream myfilestream;
    string nextMilestone;
    string line;
    string milestoneName;
    string milestoneMilesString;
    string arr[3];
    myfilestream.open("Milestones.txt");

    for(int i = 0; i < 10; i++)
    {
        getline(myfilestream,line);
        
        if(numMilestonesPassed == i)
        {
            nextMilestone = line;
            break;
        }
    }
    

    split(nextMilestone,',',arr,3);
    
    milestoneName = arr[0];
    milestoneMilesString = arr[1];
    bool isItRiver = isRiver(milestoneName);
    if(isItRiver)
    {
        int milestoneCrossingWidth = stoi(arr[2]);
    }
    int milestoneMiles = stoi(milestoneMilesString);
    
    
    
    if(isItRiver)
    {
        getNextMilestoneRiver(milestoneName,milestoneMiles);
    }
    
    else
    {
        getNextMilestoneFort(milestoneName,milestoneMiles);
    }
    
}

bool Milestone::isRiver(string milestoneName)
{
    bool isRiver;
    string isFort = milestoneName.substr(0,4);
    //cout << isFort << endl;
    
    if(isFort == "Fort")
    {
        isRiver = false;
    }
    else
    {
        isRiver = true;
    }
    
    return isRiver;
}

void Milestone::getNextMilestoneRiver(string milestoneName,int milestoneMiles)
{
    int milesToMilestone = milestoneMiles - milestoneMilesObject.getNumMiles();
    cout << "Next milestone is a river named: " << milestoneName << " and it is " << milesToMilestone << " miles away." << endl;
    return;
}

void Milestone::getNextMilestoneFort(string milestoneName,int milestoneMiles)
{
    int milesToMilestone = milestoneMiles - milestoneMilesObject.getNumMiles();
    cout << "Next milestone is a fort named: " << milestoneName << " and it is " << milesToMilestone << " miles away." << endl;
    return;
}

Supplies Milestone::returnSuppliesObject()
{
    return milestoneSupplyObject;
}

Miles Milestone::returnMilesObject()
{
    return milestoneMilesObject;
}