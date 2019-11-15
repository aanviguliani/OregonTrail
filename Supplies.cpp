//include statements
#include <iostream>
#include <iomanip>
#include "Supplies.h"

using namespace std;

//constructor
Supplies::Supplies()
{
    amtMoney = 1000;
    numOxen = 0;
    poundsFood = 0;
    numBullets = 0;
    numWagons = 1;
    numAidKits = 0;
    numAxle=0;
    numTongues = 0;
    numWheels = 0;
}

//paramterized constructor
Supplies::Supplies(int money,int oxen,int food,int bullets,int wheels,int tongues,int axles,int wagons,int aidKit)
{
    amtMoney = money;
    numOxen = oxen;
    poundsFood = food;
    numBullets = bullets;
    numWheels = wheels;
    numTongues = tongues;
    numAxle = axles;
    numWagons = wagons;
    numAidKits = aidKit;
}

//set money function
void Supplies::setMoney(int m)
{
    amtMoney = m;
}

//set oxen function
void Supplies::setOxen(int o)
{
    numOxen = o;
}

//set bullets function
void Supplies::setBullets(int b)
{
    numBullets = b;
}

//set food function
void Supplies::setFood(int p)
{
    poundsFood = p;
}

//set wheel function
void Supplies::setWheel(int w)
{
    numWheels = w;
}

//set tongue function
void Supplies::setTongue(int t)
{
    numTongues = t;
}

//set axle function
void Supplies::setAxle(int a)
{
    numAxle = a;
}

//set wagon function
void Supplies::setWagon(int wagons)
{
    numWagons = wagons;
}

//set aid kit function
void Supplies::setAidKit(int a)
{
    numAidKits = a;
}

//get money function
int Supplies::getMoney()
{
    return amtMoney;
}

//get oxen function
int Supplies::getOxen()
{
    return numOxen;
}

//get bullets function
int Supplies::getBullets()
{
    return numBullets;
}

//get food function
int Supplies::getFood()
{
    return poundsFood;
}

//get wheels function
int Supplies::getWheel()
{
    return numWheels;
}

//get tongue function
int Supplies::getTongue()
{
    return numTongues;
}

//get axle function
int Supplies::getAxle()
{
    return numAxle;
}

//get wagon function
int Supplies::getWagon()
{
    return numWagons;
}

//get aid kit function
int Supplies::getAidKit()
{
    return numAidKits;
}

