/* 
 * Header file for tic-tac-toe class
 * class functions declared 
 */


#ifndef TTT_H
#define TTT_H

#include <string>

using std::string;

class TTT{
    public:
        /* member functions */
        void display_grid();
    private:
        /* member variables */
        // names of the players
        string player1;
        string player2;
        // pieces the players will use
        char o_piece = 'o';
        char x_piece = 'x';

};


#endif
