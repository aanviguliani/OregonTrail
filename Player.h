#include <string>

using namespace std;
 #ifndef Player_H
 #define Player_H
 
class Player{
    //public members
    public:
        Player();
        Player(string usernameM,string user1,string user2,string user3,string user4,int n,bool mp,bool p1,bool p2,bool p3,bool p4); //player paramterized constructor
        void setMainPlayer(string player1); //set name for main player
        void setPlayer1(string player2); //set name for player 1
        void setPlayer2(string player2); // set name for player 2
        void setPlayer3(string player3); //set name for player 3
        void setPlayer4(string player4); //set name for player 4
        string getMainPlayer(); // get name for main player
        string getPlayer1(); //get name for player 1
        string getPlayer2(); //get name for player 2
        string getPlayer3(); // get name for player 3
        string getPlayer4(); //get name for player 4
        bool isMainPlayer(); // returns if main player is alive
        bool isPlayerOne(); //returns if player one is alive
        bool isPlayerTwo();//returns if player two is alive 
        bool isPlayerThree();//returns if player three is alive
        bool isPlayerFour();//returns if player four is alive
        void setMainPlayerHealth(bool main); //set if main player is alive
        void setPlayer1Health(bool p1); // set if player 1 is alive
        void setPlayer2Health(bool p2);// set if player 2 is alive
        void setPlayer3Health(bool p3);// set if player 3 is alive
        void setPlayer4Health(bool p4);// set if player 4 is alive
        void setNumPlayers(int n); // set the number of players
        int getNumPlayers(); // get the number of players
        
        
    //private members
    private:
        string usernameMain;
        string username1;
        string username2;
        string username3;
        string username4;
        int numPlayers;
        bool mainPlayerHealth;
        bool player1Health;
        bool player2Health;
        bool player3Health;
        bool player4Health;
        
};
#endif