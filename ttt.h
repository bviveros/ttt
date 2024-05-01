/* 
 * Header file for tic-tac-toe class
 * class functions declared 
 */

#ifndef TTT_H
#define TTT_H

#include <iostream>
#include <string>

class TTT
{
    private:
        /* member variables */
        // names of the players
        std::string player1;
        std::string player2;
        // pieces the players will use
        const char o_piece;
        const char x_piece;
        // grid in which the game will be played
        std::string grid[3][3];
    public:
        /* member functions */
        /* constructor with initilization list */
        TTT() : player1(""), player2(""), o_piece('o'), x_piece('x'){}

        /* regular member functions */
        void initialize_grid();
        void display_grid();
        void get_players_names();
};


#endif
