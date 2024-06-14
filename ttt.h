/* 
 * Header file for tic-tac-toe class
 * class functions declared 
 */

#ifndef TTT_H
#define TTT_H

/* including predefined libraries */
#include <iostream>
#include <string>

class TTT
{
    private:
        /* member variables */
        // names of the players
        std::string m_player1;
        std::string m_player2;
        // pieces the players will use
        const char m_o_piece;
        const char m_x_piece;
        // grid in which the game will be played
        std::string grid[3][3];
    public:
        /* member functions */
        /* constructor with initilization list */
        TTT() : m_player1(""), m_player2(""), m_o_piece('o'), m_x_piece('x'){}

        /* regular member functions */
        void initialize_grid();
        void display_updated_grid();
        void set_players_names();
        bool validate_players_names(std::string);
};

#endif

/*
//prototypes
**       void splashScreen();
**       void askForUserNames(string&, string&);
(optional)    void validateUserName(string&);
**    void displayGrid(string[], string&, const string, const string, int&, bool);
    void playerMakeMove(string[], string&, const string, const string, int&, bool&, bool&);
    void validatePlayersMove(const string[], string&, const string);
    void checkPositionAvailability(const string[], string&, bool&);
    void updateGrid(string[], const string, const bool);
    void switchPlayer(bool&);
    void checkWin(const string[], string, bool&);
    void checkTie(string[], const int, const bool, bool&);
    void displayFinalGrid(const string[]);
    void resetGame(string[], int&, bool&);
    void resetGrid(string[]);
**     void closingMessage();

*/