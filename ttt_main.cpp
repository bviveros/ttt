/*
 * The main file that'll run the tic-tac-toe game
 */

#include <iostream>
#include <string>
#include <iomanip>

/* user defined libraries */
#include "ttt.h"

/* function prototypes */
void splash_screen();
void farewell_screen();

int main()
{
    /* intro screen */
    splash_screen();

    TTT game;

    game.set_players_names();
    // game.initialize_grid();
    do{
        game.display_updated_grid();
        game.player_move();
        game.update_grid();

        game.switch_player_turn();
    }while(true);

    farewell_screen();

    return 0;
}

void splash_screen()
{
    system("clear"); 
    std::cout << std::setfill('*') << std::setw(24) << "\n" << std::setfill('*') << std::setw(24) << "\n";
    std::cout << "****  TIC-TAC-TOE  ****" << std::endl;
    std::cout << "****      By       ****" << std::endl;
    std::cout << "****Braulio Viveros****" << std::endl;
    std::cout << std::setfill('*') << std::setw(24) << "\n" << std::setfill('*') << std::setw(24) << "\n";

    system("read ballZ"); //pauses the program
}

void farewell_screen()
{
    std::cout << std::setfill('*') << std::setw(24) << "\n" << std::setfill('*') << std::setw(24) << "\n";
    std::cout << "*****  Fare-well  *****"  << std::endl;
    std::cout << std::setfill('*') << std::setw(24) << "\n" << std::setfill('*') << std::setw(24) << "\n";

    system("read ballZ"); //pauses the program

}
