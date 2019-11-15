//include statements
#include <iostream>
#include <iomanip>
#include "Player.h"
#include "Misfortune.h"
#include "Supplies.h"
#include "Miles.h"
#include "Hunting.h"

using namespace std;

//constructor
Player::Player()
{
    //initializes vars
    string usernameMain;
    string username1;
    string username2;
    string username3;
    string username4;
    numPlayers = 4;
    mainPlayerHealth = true;
    player1Health = true;
    player2Health = true;
    player3Health = true;
    player4Health = true;
}

//parameterized constructor
Player::Player(string usernameM,string user1,string user2,string user3,string user4,int n,bool mp,bool p1,bool p2,bool p3,bool p4)
{
    usernameMain = usernameM;
    username1 = user1;
    username2 = user2;
    username3 = user3;
    username4 = user4;
    numPlayers = n;
    mainPlayerHealth = mp;
    player1Health = p1;
    player2Health = p2;
    player3Health = p3;
    player4Health = p4;
}

//set/get functions for main player, player 1, 2, 3, 4, and their healths
void Player::setMainPlayer(string player1)
{
    usernameMain = player1;
}

void Player::setPlayer1(string player2)
{
    username2 = player2;
}

void Player::setPlayer2(string player2)
{
    username2 = player2;
}

void Player::setPlayer3(string player3)
{
    username3 = player3;
}

void Player::setPlayer4(string player4)
{
    username4 = player4;
}

string Player::getMainPlayer()
{
    return usernameMain;
}

string Player::getPlayer1()
{
    return username1;
}

string Player::getPlayer2()
{
    return username2;
}

string Player::getPlayer3()
{
    return username3;
}

string Player::getPlayer4()
{
    return username4;
}

void Player::setMainPlayerHealth(bool main)
{
    mainPlayerHealth = main;
}

void Player::setPlayer1Health(bool p1)
{
    player1Health = p1;
}

void Player::setPlayer2Health(bool p2)
{
    player2Health = p2;
}

void Player::setPlayer3Health(bool p3)
{
    player3Health = p3;
}

void Player::setPlayer4Health(bool p4)
{
    player4Health = p4;
}

bool Player::isMainPlayer()
{
    return mainPlayerHealth;
}

bool Player::isPlayerOne()
{
    return player1Health;
}

bool Player::isPlayerTwo()
{
    return player2Health;
}

bool Player::isPlayerThree()
{
    return player3Health;
}

bool Player::isPlayerFour()
{
    return player4Health;
}

void Player::setNumPlayers(int n)
{
    numPlayers = n;
}

int Player::getNumPlayers()
{
    return numPlayers;
}

