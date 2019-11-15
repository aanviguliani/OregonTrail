//include statements
#include <iostream>
#include <iomanip>
#include <math.h>
#include "Supplies.h"
#include "Miles.h"

using namespace std;

//random num function
int getRandomNum(int min, int max)
{
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}

//non parameterized constructor
RaiderAttack::RaiderAttack()
{
    probability = 0;
}

//paramterized constructor
RaiderAttack::RaiderAttack(Supplies initialSupplies, Miles miles)
{
    raiderAttackSupplies = initialSupplies;
    raiderAttackMiles = miles;
}

//if raider attack, go to raider attack function and return new supplies object
Supplies RaiderAttack::isRaiderAttack()
{
    int miles = raiderAttackMiles.getNumMiles();
    double numeratorTop =  pow(((miles/100)-4),2) + 72;
    double numeratorBottom = pow(((miles/100)-4),2) + 12;
    double numerator = (numeratorTop/numeratorBottom) - 1;
    double probability = numerator/10;
    
    int randNum = getRandomNum(1,100);
    if(randNum >= 1 && randNum <= probability)
    {
        raiderAttackFunction();
        
    }
    
    return raiderAttackSupplies;
}

//raider attack that presents user with choices and updates supplies accordingly
void RaiderAttack::raiderAttackFunction()
{
     int raiderChoice = 0;
     cout << "RIDERS AHEAD! THEY LOOK HOSTILE!" << endl;
     cout << "1. Run; 2. Attack; 3. Surrender" << endl;
     cin >> raiderChoice;
     
     int lostMoney = 0;
     int battleBulletsLose = 0;
     int battleBullets = 0;
     
     switch(raiderChoice)
     {
         case 1:
         {
             int raidedOxen = raiderAttackSupplies.getOxen() - 1;
             raiderAttackSupplies.setOxen(raidedOxen);
             int raidedFood = raiderAttackSupplies.getFood() - 10;
             raiderAttackSupplies.setFood(raidedFood);
             int raidedPartRand = getRandomNum(1,3);
             int raidedPart = 0;
             if(raidedPart == 1)
             {
                 raidedPart = raiderAttackSupplies.getWheel() - 1;
                 raiderAttackSupplies.setWheel(raidedPart);
             }
             else if(raidedPart == 2)
             {
                 raidedPart = raiderAttackSupplies.getTongue() - 1;
                 raiderAttackSupplies.setWheel(raidedPart);
             }
             
             else
             {
                 raidedPart = raiderAttackSupplies.getAxle() - 1;
                 raiderAttackSupplies.setWheel(raidedPart);
             }
             break;
         }
         case 2:
         {
             int randPuzzle = getRandomNum(1,10);
             int userGuess;
             bool didUserGuess;
             cout << "----welcome to the puzzle!----- " << endl;
             cout << "In order to pass this puzzle, you must correctly guess a number between 1 to 10. You will be given atmost 3 tries. Good luck!" << endl;
             for(int i = 0; i < 3; i++)
             {
                 cout << i << " try! Your guess? ";
                 cin >> userGuess;
                 cout << endl;
                 
                 if(userGuess == randPuzzle)
                 {
                     didUserGuess = true;
                     break;
                 }
                 
                 else{
                     didUserGuess = false;
                 }
             }
             
             if(didUserGuess)
             {
                 cout << "You passed the puzzle and won the battle!" << endl;
                 int battleFood = raiderAttackSupplies.getFood() + 50;
                 raiderAttackSupplies.setFood(battleFood);
                 battleBullets = raiderAttackSupplies.getBullets() + 50;
                 raiderAttackSupplies.setBullets(battleBullets);
             }
             
             else{
                 cout << "You lost the battle!" << endl;
                 battleBulletsLose = raiderAttackSupplies.getBullets() - 50;
                 lostMoney = (raiderAttackSupplies.getMoney()) * .75;
                 raiderAttackSupplies.setMoney(lostMoney);
             }
             break;
         }
         case 3:
         {
             cout << "You surrendered and lost a quarter of your cash reserves." << endl;
             lostMoney = (raiderAttackSupplies.getMoney()) * .75;
             raiderAttackSupplies.setMoney(lostMoney);
             break;
         }
     }
     
     //status update
    cout << "------- CURRENT STATUS -------" << endl;
    cout << "Current Date: " << raiderAttackMiles.getYear() << "-" << raiderAttackMiles.getMonth() << "-" << raiderAttackMiles.getDay() << "|";
    cout << " Miles Travelled: " << raiderAttackMiles.getNumMiles() << "|";
    cout << " Food: " << raiderAttackSupplies.getFood() << "|";
    cout << " Bullets: " << raiderAttackSupplies.getBullets() << "|";
    cout << " Cash: " << raiderAttackSupplies.getMoney() << endl;
}