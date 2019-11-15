//include statements
#include <iostream>
#include <iomanip>
#include "Hunting.h"
#include "Supplies.h"
#include "Player.h"

using namespace std;

//constructor
Hunting::Hunting()
{
    deer = 0;
    fox = 0;
    rabbit = 0;
    bear = 0;
    moose = 0;
    numBullets = 0;
    pounds = 0;
    poundsHunted = 0;
}

//random function
int randomNumHunt(int min, int max)
{
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}

//paramterized constructor
Hunting::Hunting(Supplies initialSupplies,Player player)
{
    huntingSupplies = initialSupplies;
    huntingPlayer = player;
}

//puzzle function
bool isPuzzle()
{
    int huntPuzzle = randomNumHunt(1,10);
    int userGuess = 0;
    bool didUserGuess;
    cout << "----welcome to the puzzle!----- " << endl;
    cout << "In order to pass this puzzle, you must correctly guess a number between 1 to 10. You will be given atmost 3 tries. Good luck!" << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << i << " try! Your guess? ";
        cin >> userGuess;
        cout << endl;
         
        if(userGuess == huntPuzzle)
        {
            didUserGuess = true;
            break;
        }
         
        else{
            didUserGuess = false;
        }
    }
    
    return didUserGuess;
}

//functions to see if animals are hunted and updates supplies accordingly
void Hunting::isFoxHunt()
{
    //probability = 25
    //5 pounds
    int poundsFox = 0;
    int foxRand = randomNumHunt(1,100);
    int choiceHuntFox = 0;
    if(foxRand >=1 && foxRand <=25)
    {
        //fox encountered
        //choose to hunt
        //call puzzle function
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A FOX! DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl;
        cin >> choiceHuntFox;
        
        if(choiceHuntFox == 1)
        {
            cout << "num Bullets " << huntingSupplies.getBullets() << endl;
            if(huntingSupplies.getBullets() >=10)
            {
                bool isHunt = isPuzzle();
                if(isHunt)
                {
                    cout << "You have passed the puzzle!" << endl;
                    cout << "Used 10 bullets" << endl;
                    int newBullets = huntingSupplies.getBullets() - 10;
                    huntingSupplies.setBullets(newBullets);
                    poundsFox = 5;
                    int newFood = huntingSupplies.getFood() + poundsFox;
                    huntingSupplies.setFood(newFood);
                    cout << "Food improved by: " << poundsFox << endl;
                }
                else
                {
                    cout << "You have FAILED the puzzle! "<< endl;
                    cout << "Failed the puzzle! Hunt opportunity missed. Moving on!" << endl;
                }
            }
           
            else{
                cout << "Less than 10 bullets left. Hunt unsuccessful." << endl;
            }
        }
    }
}
void Hunting::isDeerHunt()
{
   //probability = 15
   //30-55 pounds
    int poundsDeer = 0;
    int DeerRand = randomNumHunt(1,100);
    int choiceHuntDeer = 0;
    if(DeerRand >=1 && DeerRand <=15)
    {
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A DEER! DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl;
        cin >> choiceHuntDeer;
        
        if(choiceHuntDeer == 1)
        {
            if(huntingSupplies.getBullets() >=10)
            {
                bool isHunt = isPuzzle();
                if(isHunt)
                {
                    cout << "You have passed the puzzle!" << endl;
                    cout << "Used 10 bullets" << endl;
                    int newBullets = huntingSupplies.getBullets() - 10;
                    huntingSupplies.setBullets(newBullets);
                    poundsDeer = randomNumHunt(30,55);
                    int newFood = huntingSupplies.getFood() + poundsDeer;
                    huntingSupplies.setFood(newFood);
                    cout << "Food improved by " << poundsDeer << endl;
                    
                }
                else
                {
                    cout << "You have FAILED the puzzle! "<< endl;
                    cout << "Failed the puzzle! Hunt opportunity missed. Moving on!" << endl;
                }
            }
           
            else{
                cout << "Less than 10 bullets left. Hunt unsuccessful." << endl;
            }
        }
    }
    
}
void Hunting::isRabbitHunt()
{
   //probability = 50
   //2 pounds
    int poundsRabbit = 0;
    int rabbitRand = randomNumHunt(1,100);
    int choiceHuntRabbit = 0;
    if(rabbitRand >=1 && rabbitRand <=50)
    {
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A RABBIT! DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl;
        cin >> choiceHuntRabbit;
        cout << huntingSupplies.getBullets()<< endl;
        
        if(choiceHuntRabbit == 1)
        {
            if(huntingSupplies.getBullets() >=10)
            {
                bool isHunt = isPuzzle();
                if(isHunt)
                {
                    cout << "You have passed the puzzle!" << endl;
                    cout << "Used 10 bullets" << endl;
                    int newBullets = huntingSupplies.getBullets() - 10;
                    huntingSupplies.setBullets(newBullets);
                    poundsRabbit = 2;
                    int newFood = huntingSupplies.getFood() + poundsRabbit;
                    huntingSupplies.setFood(newFood);
                    cout << "Food improved by: " << poundsRabbit << endl;
                }
                else
                {
                    cout << "You have FAILED the puzzle! "<< endl;
                    cout << "Failed the puzzle! Hunt opportunity missed. Moving on!" << endl;
                }
            }
           
            else{
                cout << "Less than 10 bullets left. Hunt unsuccessful." << endl;
            }
        }
    }
}

void Hunting::isMooseHunt()
{
    //probability = 5
    //300-600 pounds
    int poundsMoose = 0;
    int mooseRand = randomNumHunt(1,100);
    int choiceHuntMoose = 0;
    if(mooseRand >=1 && mooseRand <=5)
    {
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A MOOSE! DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl;
        cin >> choiceHuntMoose;
        
        if(choiceHuntMoose == 1)
        {
            if(huntingSupplies.getBullets() >=10)
            {
                bool isHunt = isPuzzle();
                if(isHunt)
                {
                    cout << "You have passed the puzzle!" << endl;
                    cout << "Used 10 bullets" << endl;
                    int newBullets = huntingSupplies.getBullets() - 10;
                    huntingSupplies.setBullets(newBullets);
                    poundsMoose = randomNumHunt(300,600);
                    int newFood = huntingSupplies.getFood() + poundsMoose;
                    huntingSupplies.setFood(newFood);
                    cout << "Food improved by: " << poundsMoose << endl;
                }
                else
                {
                    cout << "You have FAILED the puzzle! "<< endl;
                    cout << "Failed the puzzle! Hunt opportunity missed. Moving on!" << endl;
                }
            }
           
            else{
                cout << "Less than 10 bullets left. Hunt unsuccessful." << endl;
            }
        }
    }
}
void Hunting::isBearHunt()
{
    //probability = 7
    //100-350 pounds
    int poundsBear = 0;
    int bearRand = randomNumHunt(1,100);
    int choiceHuntBear = 0;
    if(bearRand >=1 && bearRand <=7)
    {
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A DEER! DO YOU WANT TO HUNT: (1) YES, (2) NO" << endl;
        cin >> choiceHuntBear;
        
        if(choiceHuntBear == 1)
        {
            if(huntingSupplies.getBullets() >=10)
            {
                bool isHunt = isPuzzle();
                if(isHunt)
                {
                    cout << "You have passed the puzzle!" << endl;
                    cout << "Used 10 bullets" << endl;
                    int newBullets = huntingSupplies.getBullets() - 10;
                    huntingSupplies.setBullets(newBullets);
                    poundsBear = randomNumHunt(100,350);
                    int newFood = huntingSupplies.getFood() + poundsBear;
                    huntingSupplies.setFood(newFood);
                    cout << "Food improved by: " << poundsBear << endl;
                    huntingSupplies.setFood(newFood);
                }
                else
                {
                    cout << "You have FAILED the puzzle! "<< endl;
                    cout << "Failed the puzzle! Hunt opportunity missed. Moving on!" << endl;
                }
            }
           
            else{
                cout << "Less than 10 bullets left. Hunt unsuccessful." << endl;
            }
        }
    }
}

//main go hunting function
Supplies Hunting::goHunting()
{
    isRabbitHunt();
    isFoxHunt();
    isDeerHunt();
    isBearHunt();
    isMooseHunt();
    int eatChoice  = 0;
    int poundsPerPerson = 0;
    cout << "How well do you want to eat?" << endl;
    cout << "1. Poorly	2. Moderately	3. Well" << endl;
    cin >> eatChoice;
    switch(eatChoice)
    {
        case 1: poundsPerPerson = 2; break;
        case 2: poundsPerPerson = 3; break;
        case 3: poundsPerPerson = 5; break;
    }
    
    int newFood = huntingSupplies.getFood() - (poundsPerPerson * huntingPlayer.getNumPlayers());
    huntingSupplies.setFood(newFood);
    
    return huntingSupplies;
}