#include <iostream>
#include <iomanip>
using namespace std;

//include statements
#include "Hunting.h"
#include "Miles.h"
#include "Misfortune.h"
#include "Player.h"
#include "Supplies.h"
#include "Hunting.cpp"
#include "Miles.cpp"
#include "Misfortune.cpp"
#include "Player.cpp"
#include "Supplies.cpp"
#include "Store.h"
#include "Store.cpp"
#include "RaiderAttack.h"
#include "RaiderAttack.cpp"
#include "Milestone.cpp"
#include "Milestone.h"

int randomNumbers(int min, int max)
{
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}

int main()
{
    //create player object,miles object and initialize vars
    Player p1 = Player();
    string mainPlayerName;
    string player1;
    string player2;
    string player3;
    string player4;
    int numberMilestonesPassed = 0;
    Miles m1 = Miles();
    
    //prompt user to enter names of main player and companions and fill up player object
    cout << "What is your name?" << endl;
    cin >> mainPlayerName;
    p1.setMainPlayer(mainPlayerName);
    
    cout << "Please enter the names of your companions below:" << endl;
    cout << "1: ";
    cin >> player1;
    cout << endl;
    p1.setPlayer1(player1);
    
    cout << "2: ";
    cin >> player2;
    cout << endl;
    p1.setPlayer2(player2);
    
    cout << "3: ";
    cin >> player3;
    cout << endl;
    p1.setPlayer3(player3);
    
    cout << "4: ";
    cin >> player4;
    cout << endl;
    p1.setPlayer4(player4);
    cout << endl;
    
    //pass values into player object
    Player playerObject = Player(mainPlayerName,player1,player2,player3,player4,4,true,true,true,true,true);
    
    string choice;
    cout << "You are starting at mile: 0" << endl;
    cout << "There are 2040 that you must travel to reach your destination." << endl;
    cout << "Before the start of your trip, you can visit the store and buy supplies: food, oxen, bullets and wagon parts. Would you like to visit the store? Y / N" << endl;
    cin >> choice;
    
    int amtMoney = 1000;
    int numOxen = 0;
    int numYokes = 0;
    int poundsFood = 0;
    int numTongues = 0;
    int numAxle = 0;
    int numBullets = 0;
    int numWheels = 0;
    int numWagons = 1;
    int numAidKits = 0;
    int bill = 0;
    
    //create initial supplies object and pass object into store class
    Supplies initialSupplies = Supplies(amtMoney,numOxen,poundsFood,numBullets,numWheels,numTongues,numAxle,1,numAidKits);
    Store store(initialSupplies);
    
    //START STORE FUNCTION
    if(choice == "Y" || choice == "y")
    {
        initialSupplies = store.goToStore();
    }
    
    //END STORE FUNCTION
    cout << endl;
    
    //change depart date choice
    string choiceChangeDate;
    cout << "Your departure date currently is: 1847-03-28. Would you like to change it? Y / N" << endl;
    cin >> choiceChangeDate;
    
    int month = 0;
    int day = 0;
    int year = 0;
    int endDay = 0;
    int endMonth = 0;
    int endYear = 0;
    if(choiceChangeDate == "N" || choiceChangeDate=="n")
    {
        cout << "The final date of departure is: 1847-03-28" << endl;
        cout << "You must reach the Oregon City by 1847-11-30" << endl;
        m1.setDate(28,03,1847);
        m1.setEndDate(30,11,1847);
        month = 3;
        day = 28;
        year = 1847;
        endDay = 30;
        endMonth = 11;
        endYear = 1847;
    }
    
    else
    {
        do{
            cout << "Enter a month as a number (last month to leave is May): ";
            cin >> month;
        }
        while(month > 5 && month < 3);
        cout << endl;
        do{
        cout << "Enter a day: ";
        cin >> day;
        }
        while(day > 31);
        cout << endl;
        
        m1.setDate(month,day,1847);
        endMonth = m1.getMonth() + 9;
        
        if(endMonth > 12)
        {
            endMonth = month - 12;
            endYear++;
        }
        
        if(m1.getDay() > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
        {
            endDay = m1.getDay() -  30;
            endMonth++;
        }
    
        else if(m1.getDay() > 31 && (month == 1 || month ==3 ||month==5 || month ==7 || month == 8))
        {
            endDay = m1.getDay() - 31;
            endMonth++;
        }
    
        else if(m1.getDay() > 28 && month == 2 && year == 1847)
        {
            endDay = m1.getDay() - 28;
            endMonth++;
        }
        
        m1.setEndDate(endDay,endMonth,endYear);
        
        cout << "The final date of departure is: " << m1.getYear() << "-" << m1.getMonth() << m1.getDay() << endl;
        cout << "You must reach Oregon City by: " << m1.getEndYear() << "-" << m1.getEndMonth() << "-" << m1.getEndDay() << endl;
        
        cout << endl;
        cout << "Let the journey begin!" << endl;
        
        //initialize all of vars in classes
        m1.setNumMiles(0);
        p1.setNumPlayers(4);
        
    }
    //declare milesobject
    Miles milesObject = Miles(0,day,month,year,endDay,endMonth,endYear);
    
    int numMilestones = 0;
   
   
    //turn do while loop
        do
        {
            //create objects and initialize vars
            Milestone milestoneObject = Milestone(milesObject,initialSupplies,playerObject);
            Misfortune misfortuneObject = Misfortune(initialSupplies,playerObject,milesObject);
            milestoneObject.setMilestone(numMilestones);
            RaiderAttack raiderAttackObject = RaiderAttack(initialSupplies,milesObject);
            int restChoice = 0;
            int milesTravelled = 0;
            int foodConsumed = 0;
            int intChoice = 0;
            int numDays = 0;
            
            //display date and print next milestone
            cout << milesObject.getYear() << "-" << milesObject.getMonth() << "-" << milesObject.getDay() << endl;
            milestoneObject.printNextMilestone();
            
            //get miles to next milestone
            int nextMilestone = milestoneObject.getNextMilestone();
            Hunting huntingObject(initialSupplies,playerObject);
            
            //prompt user to choose one of the choices in Oregon Trail
            cout << "1. Rest; 2. Continue; 3. Hunt; 4. Quit" << endl;
            cin >> intChoice;
            
            //switch case for each choice
            switch(intChoice)
            {
                //case to rest
                case 1:
                {
                    cout << "How many days would you like to rest for?" << endl;
                    cin >> restChoice;
                    numDays = m1.getDay() + restChoice;
                    //cout << "num days is " << numDays << endl;
                    foodConsumed = (3 * p1.getNumPlayers() * restChoice);
                    cout << "You have chosen to rest for " << restChoice << " days. Food will be consumed accordingly and health will improve as well." << endl;
                    milesObject.setDate(numDays,milesObject.getMonth(),milesObject.getYear());
                    //cout << milesObject.getDay() << endl;
                    //cout << m1.getDay() << " " << m1.getMonth() << " " << m1.getYear() << endl;
                    initialSupplies.setFood(initialSupplies.getFood()-foodConsumed);
                    
                    //display current status
                    cout << "------- CURRENT STATUS -------" << endl;
                    cout << "Current Date: " << milesObject.getYear() << "-" << milesObject.getMonth() << "-" << milesObject.getDay() << "|";
                    cout << " Miles Travelled: " << milesObject.getNumMiles() << "|";
                    cout << " Food: " << initialSupplies.getFood() << "|";
                    cout << " Bullets: " << initialSupplies.getBullets() << "|";
                    cout << " Cash: " << initialSupplies.getMoney() << endl;
                    break;
                }
                
                //case to continue
                case 2:
                {
                    milesTravelled = randomNumbers(70,140);
                    cout << "You have chosen to travel for 2 weeks. You will be travelling " << milesTravelled << " miles" <<endl;
                    bool isMilestone = milestoneObject.isMilestone(nextMilestone,milesTravelled);
                    int newNumMiles = milesObject.getNumMiles() + milesTravelled;
                    milesObject.setNumMiles(newNumMiles);
                    if(isMilestone)
                    {
                        milestoneObject.milestoneFunction(nextMilestone,numMilestones);
                        initialSupplies = milestoneObject.returnSuppliesObject();
                        milesObject = milestoneObject.returnMilesObject();
                        numMilestones++;
                    }
                    
                    else
                    {
                        int newFood = initialSupplies.getFood() - (14 * 3 * playerObject.getNumPlayers());
                        initialSupplies.setFood(newFood);
                        int newNumDays = milesObject.getDay() + 14;
                        milesObject.setDate(newNumDays,milesObject.getMonth(),milesObject.getYear());
                        
                    }
                    
                    //display current status
                    cout << "------- CURRENT STATUS -------" << endl;
                    cout << "Current Date: " << milesObject.getYear() << "-" << milesObject.getMonth() << "-" << milesObject.getDay() << "|";
                    cout << " Miles Travelled: " << milesObject.getNumMiles() << "|";
                    cout << " Food: " << initialSupplies.getFood() << "|";
                    cout << " Bullets: " << initialSupplies.getBullets() << "|";
                    cout << " Cash: " << initialSupplies.getMoney() << endl;
                    cout << endl;
                    break;
                    
                }
                
                //case to hunt
                case 3:
                {
                    initialSupplies = huntingObject.goHunting();
                    //display current status
                    cout << "------- CURRENT STATUS -------" << endl;
                    cout << "Current Date: " << milesObject.getYear() << "-" << milesObject.getMonth() << "-" << milesObject.getDay() << "|";
                    cout << " Miles Travelled: " << milesObject.getNumMiles() << "|";
                    cout << " Food: " << initialSupplies.getFood() << "|";
                    cout << " Bullets: " << initialSupplies.getBullets() << "|";
                    cout << " Cash: " << initialSupplies.getMoney() << endl;
                    cout << endl;
                    break;
                }
                //case to quit
                case 4:
                {
                    cout << "We're sorry you had to cut your trip short. Better luck next time!" << endl;
                    break;
                }
                    
            }
            
            //check for raider attack
            initialSupplies = raiderAttackObject.isRaiderAttack();
            
            //check for misfortune
            bool isMisfortune = misfortuneObject.isMisfortune();
            if(isMisfortune)
            {
                initialSupplies = misfortuneObject.returnMisfortuneSupplies();
                playerObject = misfortuneObject.returnPlayerObject();
            }
            
            
            //break if have passed time limit
            if( milesObject.getMonth()!=milesObject.getEndMonth() && milesObject.getEndDay()!= milesObject.getDay() && milesObject.getEndYear() !=milesObject.getYear())
            {
                cout << "You have failed the Oregon Trail" << endl;
                break;
            }
        }
        while(milesObject.getNumMiles() < 2400 && initialSupplies.getFood() >= 0 && initialSupplies.getOxen() > 0 && initialSupplies.getWheel() >= 0 && initialSupplies.getTongue() >= 0 && initialSupplies.getAxle() >= 0 && playerObject.isMainPlayer());
        
        //if they surpass 2400 miles, display that they have won
        if(milesObject.getNumMiles() >= 2400)
        {
            cout << "Congrats! You have completed the Oregon Trail!" << endl;
        }
        
        //else/display that they have lost
        else
        {
            cout << "You have failed the Oregon trail!" << endl;
        }
    
    }


