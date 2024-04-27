#ifndef TTT_H
#define TTT_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>

class TTT{
    public:
        //member FUNCTIONS
        TTT();
        void splashScreen();
        void askForUserNames(string&, string&);
        //void validateUserName(string&);
        void displayGrid();

        //member VARIABLES
        string player1;
        string player2;
        string playerMove;
        int numOfMoves;
        bool playerOneTurn;
        bool repeat;
};


#endif
