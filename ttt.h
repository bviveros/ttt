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
        std::string player_choice;
        std::string winner;
        // current player's turn
        bool first_players_turn;
        std::string cur_player;
        char cur_piece;
        // pieces the players will use
        const char m_o_piece;
        const char m_x_piece;
        // grid in which the game will be played
        char grid[9];
    public:
        /* member functions */
        /* constructor with initilization list */
        TTT() : 
        m_player1(""), 
        m_player2(""),
        player_choice(""),
        winner(""),
        first_players_turn(true),
        cur_player(""),
        cur_piece(' '),
        m_o_piece('O'),
        m_x_piece('X')
        {initialize_grid();};

        /* regular member functions */
        void initialize_grid();
        void display_updated_grid();
        void set_players_names();
        bool validate_players_names(std::string);
        void switch_player_turn();
        std::string get_current_player_name();
        void player_move();
        bool valid_move();
        bool check_position(int);
        void update_grid();
        bool winner_found();
        bool tie_found(short);
        std::string get_winner();
};

#endif
