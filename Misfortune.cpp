//include statements
#include <iostream>
#include <iomanip>
#include "Misfortune.h"
#include "Supplies.h"
#include "Player.h"

using namespace std;

//random num function
int randomNum(int min, int max)
{
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}

//parameterized constructor
Misfortune::Misfortune(Supplies initialSupplies,Player player,Miles miles)
{
    misfortuneSupplies = initialSupplies;
    misfortunePlayer = player;
    milesMisfortune = miles;
}

//function that misfortune goes to if oxen dies
void Misfortune::isOxenAlive()
{
    int newNumOxen = misfortuneSupplies.getOxen() - 1;
    cout << "OH NO! ONE OF YOUR OXEN HAS DIED! YOU HAVE " << newNumOxen << " LEFT." << endl;
    misfortuneSupplies.setOxen(newNumOxen);
    
}

//part broken function
void Misfortune::isWheelPopped()
{
    int randomPart = randomNum(1,3);
    cout << randomPart << endl;
    int newNumParts = 0;
    switch(randomPart)
    {
        case 1:
        {
            newNumParts = misfortuneSupplies.getWheel() - 1;
            cout << "OH NO! ONE OF YOUR WHEELS IS BROKEN!" << endl;
            misfortuneSupplies.setWheel(newNumParts);
            break;
        }
        case 2:
        {
            newNumParts = misfortuneSupplies.getTongue() - 1;
            cout << "OH NO! ONE OF YOUR TONGUES IS BROKEN!" << endl;
            misfortuneSupplies.setTongue(newNumParts);
            break;
        }
        case 3:
        {
            newNumParts = misfortuneSupplies.getAxle() - 1;
            cout << "OH NO! ONE OF YOUR AXLES IS BROKEN!" << endl;
            misfortuneSupplies.setAxle(newNumParts);
            break;
        }
    }
}

//one player gets sick function
void Misfortune::isSick()
{
    bool checkIfAlive = true;
    string disease;
    string playerName;
    int randomPlayer;
    do{
        randomPlayer = randomNum(1,5);
        switch(randomPlayer)
        {
            case 1:
            {
                playerName = misfortunePlayer.getMainPlayer();
                checkIfAlive = misfortunePlayer.isMainPlayer();
                break;
            }
            
            case 2:
            {
                playerName = misfortunePlayer.getPlayer1();
                checkIfAlive = misfortunePlayer.isPlayerOne();
                break;
            }
            
            case 3:
            {
                playerName = misfortunePlayer.getPlayer2();
                checkIfAlive = misfortunePlayer.isPlayerTwo();
                break;
            }
            
            case 4:
            {
                playerName = misfortunePlayer.getPlayer3();
                checkIfAlive = misfortunePlayer.isPlayerThree();
                break;
            }
            
            case 5:
            {
                playerName = misfortunePlayer.getPlayer4();
                checkIfAlive = misfortunePlayer.isPlayerFour();
                break;
            }
        }
    }
    while(checkIfAlive = false);
    
    int randomDisease = randomNum(1,6);
    switch(randomDisease)
    {
        case 1:
        {
            disease = "TYPHOID";
            break;
        }
        
        case 2:
        {
            disease = "CHOLERA";
            break;
        }
        
        case 3:
        {
            disease = "DIARRHEA";
            break;
        }
        
        case 4:
        {
            disease = "DYSENTERY";
            break;
        }
        
        case 5:
        {
            disease = "MEASLES";
            break;
        }
        
        case 6:
        {
            disease = "FEVER";
            break;
        }
    }
    
    cout << "OH NO! " << playerName << " HAS " << disease << endl;
    int probability = 0;
    int choicePushOn = 0;
    
    if(misfortuneSupplies.getAidKit() >= 1)
    {
        probability = 50;
        cout << "USED MEDICAL AID KIT" << endl;
        int newAidKit = misfortuneSupplies.getAidKit() - 1;
    }
    
    else
    {
        cout << "1. Rest; 2. Press on!" << endl;
        cin >> choicePushOn;
        
        switch(choicePushOn)
        {
            case 1:
            {
                probability = 30;
                int newDay = milesMisfortune.getDay() + 3;
            }
            case 2:
            {
                probability = 70;
            }
        }
    }
    
    bool check = isAlive(probability,playerName,disease);
    bool theyDead = false;
    if(check = false)
    {
        switch(randomPlayer)
        {
            case 1: misfortunePlayer.setMainPlayerHealth(theyDead);break;
            case 2: misfortunePlayer.setPlayer1Health(theyDead); break;
            case 3: misfortunePlayer.setPlayer2Health(theyDead); break;
            case 4: misfortunePlayer.setPlayer3Health(theyDead); break;
            case 5: misfortunePlayer.setPlayer4Health(theyDead); break;
        }
    }
}

//check to see if they're still alive based on whether they rest or push on or use aid kit
bool Misfortune::isAlive(int probability,string playerName,string disease)
{
    int randomNumAlive = randomNum(1,100);
    if(randomNumAlive >=1 && probability)
    {
        cout << "OH NO! " << playerName << " HAS DIED OF " << disease << endl;
        int numPlayersNow = misfortunePlayer.getNumPlayers() - 1;
        misfortunePlayer.setNumPlayers(numPlayersNow);
        return false;
    }
    else
        return true;
}

//check if misfortune occurs
bool Misfortune::isMisfortune()
{
    int random = randomNum(1,100);
    //cout << random << endl;
    bool misfortune;
    if(random <=40 && random >=1)
    {
        misfortune = true;
        random = randomNum(1,3);
        //cout << random << endl;
        switch(random)
        {
            case 1:
            {
                isSick();
                break;
            }
            
            case 2:
            {
                isWheelPopped();
                break;
            }
            
            case 3:
            {
                isOxenAlive();
                break;
            }
        }
    }
    else
    {
        misfortune = false;
    }
}

//return objects that misfortune uses
Player Misfortune::returnPlayerObject()
{
    return misfortunePlayer;
}

Supplies Misfortune::returnMisfortuneSupplies()
{
    return misfortuneSupplies;
}
