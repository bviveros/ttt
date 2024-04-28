#include "ttt.h"

TTT::TTT()
{
    player1 = "";
    player2 = "";
    playerMove = "";
    numOfMoves = 0;
    bool playerOneTurn = true;
    bool repeat = false;
    string grid[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8"};
}

void TTT::splashScreen()
{
    system("clear"); 
    cout << setfill('*') << setw(24) << "\n" << setfill('*') << setw(24) << "\n";
    cout << "****  TIC-TAC-TOE  ****" << endl;
    cout << "****      By       ****" << endl;
    cout << "****Braulio Viveros****" << endl;
    cout << setfill('*') << setw(24) << "\n" << setfill('*') << setw(24) << "\n";

    system("read ballz"); //pauses the program
}


//could be that player1 will just use the name of the main character 
void TTT::askForUserNames(string& player1, string& player2)
{
        
    cout << "Player 1: Enter your name\nEnter a single word with alpha chars only! " << endl;
    getline(cin, player1);
    //validateUserName(player1);
   
    cout << "Player 2: Enter your name\nEnter a single name with alpha chars only! " << endl;
    getline(cin, player2);
    //validateUserName(player2);
}

void TTT::displayGrid()
{
    bool win = false;
    bool endGame = false;

    //do
    //{
        system("clear");

        cout << "TIC-TAC-TOE" << endl;

        cout << "|-----|\n|" << this->grid[0] << "|" <<this-> grid[1] << "|" << this->grid[2] << "|" << "\n|-----|" << endl;

        cout << "|-----|\n|" << this->grid[3] << "|" << this->grid[4] << "|" << this->grid[5] << "|" << "\n|-----|" << endl;

        cout << "|-----|\n|" << this->grid[6] << "|" << this->grid[7] << "|" << this->grid[8] << "|" << endl;
   //}while(endGame != true && win != true); //runs while there are still spaces left and nobody has won

}
