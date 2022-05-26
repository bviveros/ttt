/*
* TIC-TAC-TOE(player vs player)
* Braulio Viveros
*
* 0 1 2
* 3 4 5
* 6 7 8
**/

#include <iostream> //access to input and output operators
#include <string>   //access to string class
#include <cstdlib>  //access to system function calls
#include <iomanip>  //access to manipulate output

using namespace std;

//prototypes
void splashScreen();
void askForUserNames(string&, string&);
void validateUserName(string&);
void displayGrid(string[], string&, const string, const string, int&, bool);
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
void closingMessage();

//global constants
const int GRID_SIZE = 9;

int main()
{
    //initializes the tic-tac-toe board
    string grid[GRID_SIZE] = {"0", "1", "2", "3", "4", "5", "6", "7", "8"};

    string player1 = ""; //player one first name
    string player2 = ""; //player two first name
    bool playerOneTurn = true; //determines which player's turn
    string playerMove = ""; //holds players' game move
    int numOfMoves = 0; //increments number of moves made, will be limited at nine
    bool repeat = false; //determines whether the players will keep playing

    splashScreen(); //display introduction screen

    askForUserNames(player1, player2); //prompts users to enter their names

    do //loops at least once, may loop numerous times
    {
        //function call, displays the checkers field
        displayGrid(grid, playerMove, player1, player2, numOfMoves, playerOneTurn);

        //function call, determines whether to restart or end the program
        resetGame(grid, numOfMoves, repeat);

    }while(repeat == true); //repeat is changed in called function

    system("read ballZ"); //pauses the program
    return 0;
}


//displays game and developer's information in a fixed matter
void splashScreen()
{
    system("clear"); 
    cout << setfill('*') << setw(24) << "\n" << setfill('*') << setw(24) << "\n";
    cout << "****  TIC-TAC-TOE  ****" << endl;
    cout << "****      By       ****" << endl;
    cout << "****Braulio Viveros****" << endl;
    cout << setfill('*') << setw(24) << "\n" << setfill('*') << setw(24) << "\n";

    system("read ballZ"); //pauses the program
}


//Requests for players' user names
void askForUserNames(string& player1, string& player2)
{
    system("clear"); //clears terminal screen

    //prompts user and accepts player one's name
    cout << "Player 1,Enter your name\nEnter a single word with alpha chars only! " << endl;
    getline(cin, player1);
    validateUserName(player1); //validates user's entry to be a single string of alpha characters

    //prompts user and accepts player two's name
    cout << "Player 2,Enter your name\nEnter a single word with alpha chars only! " << endl;
    getline(cin, player2);
    validateUserName(player2); //validates user's entry to be a single string of alpha characters
}


//validates user names
void validateUserName(string& userName)
{
    unsigned int counter = 0; //used to stop while loop

    //loop checks to see if user's name is all alpha characters
    while(counter < userName.length() || userName.length() == 0){
        if(!isalpha(userName[counter])){//runs if non alphabet characters detected

            //prompts user to re enter their first name
            cout << "Invalid name\nEnter a single word with alpha chars only!" << endl;
            getline(cin, userName);
            counter = 0;//resets counter to 0
        }
        else{
            counter++; //increments counter, will stop while loop
        }
    }
}


//display the grid after each player makes a move
void displayGrid(string grid[], string& playerMove, const string player1, const string player2, int& numOfMoves, bool playerOneTurn)
{
    bool win = false; //determines if there is a winner
    bool endGame = false; //determines whether the game is over

    do
    {
        system("clear"); //clears terminal screen

        //outputs updated tic-tac-toe playing field
        cout << "TIC-TAC-TOE" << endl;
        cout << "|-----|" << endl;
        cout << "|" << grid[0] << "|" << grid[1] << "|" << grid[2] << "|" << endl;
        cout << "|-----|" << endl;
        cout << "|" << grid[3] << "|" << grid[4] << "|" << grid[5] << "|" << endl;
        cout << "|-----|" << endl;
        cout << "|" << grid[6] << "|" << grid[7] << "|" << grid[8] << "|" << endl;

        //function call, allows players to take thier turns
        playerMakeMove(grid, playerMove, player1, player2, numOfMoves, playerOneTurn, win);

        //when all spaces have been occupied
        if(numOfMoves == 9)
        {
            checkTie(grid, numOfMoves, win, endGame);//function call, checks if game is a tie
        }

  }while(endGame != true && win != true); //runs while game is not over

}


//allows players to make the next move
void playerMakeMove(string grid[], string& playerMove, const string player1, const string player2, int& numOfMoves, bool& playerOneTurn, bool& win)
{
    char piece = ' '; //used to show player's piece
    string player = ""; //holds player's name if its their turn


    if(playerOneTurn) //runs if its first player's turn
    {
        player = player1; //assigns first player's name
        piece = 'X'; //assign's first player's game piece
    }
    else //runs if its second player's turn
    {
        player = player2; //assigns second player's name
        piece = 'O'; //assign's second player's game piece
    }

    //displays respective player's name and game piece
    cout << "It is " << player << "'s turn; You are " << piece << "\nGive me your best move!" << endl;
    getline(cin, playerMove); //accepts player's move

    validatePlayersMove(grid, playerMove, player); //function call, validates player's move
    updateGrid(grid, playerMove, playerOneTurn); //function call, updates game grid
    checkWin(grid, player, win); //checks if there is a winner

    if(win != true) //runs if there isn't a winner
    {
        switchPlayer(playerOneTurn); //switches players
        numOfMoves++; //increments to the total number of moves made by both players
    }
}


//validates that user entry X is such that 0<=X<=8
void validatePlayersMove(const string grid[], string& playerMove, const string player)
{
    unsigned int counter = 0; //used to control while loop
    bool validInput = false; //used to check if position is still available

    while(counter < playerMove.length() || counter == 0)
    {
        //runs if player's move is any number from 0 to 8
        if((playerMove == "0") || (playerMove == "1") || (playerMove == "2") || (playerMove == "3") ||
           (playerMove == "4") || (playerMove == "5") || (playerMove == "6") || (playerMove == "7") ||
           (playerMove == "8"))
        {
            //function call, checks to see if position is still avaiable
            checkPositionAvailability(grid, playerMove, validInput);
            if(validInput == true) //runs if there is a valid input
            {
                counter++; //increments counter by one
            }
        }
        else
        {
            //prompts user to try to re-enter a valid move
            cout << "invalid entry" << endl;
            cout << player << "'s turn" << endl;
            getline(cin, playerMove);
        }
    }
}


//check that the position selected by the user is available
void checkPositionAvailability(const string grid[], string& playerMove, bool& validInput)
{
    //converts player's move to an integer value
    int move = atoi(playerMove.c_str());

    //checks to see if position in grid is already taken

    if(grid[move] == "X" || grid[move] == "O")
    {
        //displays appropriate message and prompts user to re-enter a valid move
        cout << "Position not available" << endl;
        cout << "make a different choice" << endl;
        getline(cin, playerMove);
    }
    else
    {
        validInput = true; //verifies that there was a valid input
    }
}


//updates the playing grid after a player's move
void updateGrid(string grid[], const string playerMove, const bool playerOneTurn)
{
    string x = "\033[38;5;160mX\033[0m";
    string o = "\033[38;5;21mO\033[0m";
    //runs if its the first player's turn
    //assigns 'X' in respect to player's choice
    if(playerOneTurn)
    {
        if(playerMove == "0")
        {
            grid[0] = x;
        }
        else if(playerMove == "1")
        {
            grid[1] = x;
        }
        else if (playerMove == "2")
        {
            grid[2] = x;
        }
        else if(playerMove == "3")
        {
            grid[3] = x;
        }
        else if (playerMove == "4")
        {
            grid[4] = x;
        }
        else if(playerMove == "5")
        {
            grid[5] = x;
        }
        else if (playerMove == "6")
        {
            grid[6] = x;
        }
        else if(playerMove == "7")
        {
            grid[7] = x;
        }
        else if (playerMove == "8")
        {
            grid[8] = x;
        }
    }
    //runs if its the second player's turn
    //assigns 'O' in respect to player's choice
    else if(!playerOneTurn)
    {
        if(playerMove == "0")
        {
            grid[0] = o;
        }
        else if(playerMove == "1")
        {
            grid[1] = o;
        }
        else if (playerMove == "2")
        {
            grid[2] = o;
        }
        else if(playerMove == "3")
        {
            grid[3] = o;
        }
        else if (playerMove == "4")
        {
            grid[4] = o;
        }
        else if(playerMove == "5")
        {
            grid[5] = o;
        }
        else if (playerMove == "6")
        {
            grid[6] = o;
        }
        else if(playerMove == "7")
        {
            grid[7] = o;
        }
        else if (playerMove == "8")
        {
            grid[8] = o;
        }
    }
}


//switch from one player to another
void switchPlayer(bool& playerOneTurn)
{
    if(playerOneTurn)
    {
        playerOneTurn = false;
    }
    else
        playerOneTurn = true;
}


//check for a winning player
void checkWin(const string grid[], string player, bool& win)
{
    string x = "X";
    string o = "O";

    //possible winning combinations for first player
    if((grid[0] == x && grid[1] == x && grid[2] == x) ||
       (grid[3] == x && grid[4] == x && grid[5] == x) ||
       (grid[6] == x && grid[7] == x && grid[8] == x) ||
       (grid[0] == x && grid[3] == x && grid[6] == x) ||
       (grid[1] == x && grid[4] == x && grid[7] == x) ||
       (grid[2] == x && grid[5] == x && grid[8] == x) ||
       (grid[0] == x && grid[4] == x && grid[8] == x) ||
       (grid[2] == x && grid[4] == x && grid[6] == x))
    {
        displayFinalGrid(grid);
        win = true; //signals that there is a winner
        cout << player << " wins!" << endl; //displays the winner
    }
    //possible winning combinations for second player
    else if (
             (grid[0] == o && grid[1] == o && grid[2] == o) ||
             (grid[3] == o && grid[4] == o && grid[5] == o) ||
             (grid[6] == o && grid[7] == o && grid[8] == o) ||
             (grid[0] == o && grid[3] == o && grid[6] == o) ||
             (grid[1] == o && grid[4] == o && grid[7] == o) ||
             (grid[2] == o && grid[5] == o && grid[8] == o) ||
             (grid[0] == o && grid[4] == o && grid[8] == o) ||
             (grid[2] == o && grid[4] == o && grid[6] == o))
    {
        displayFinalGrid(grid);
        win = true; //signals that there is a winner
        cout << player << " wins!" << endl; //displays the winner
    }
}


//checks for a tie
void checkTie(string grid[], const int numOfMoves, const bool win, bool& endGame)
{
    //runs if max possible moves have been made and nobody has won yet
    if(numOfMoves == 9 && !win)
    {
        //displays the final grid
        displayFinalGrid(grid);
        cout << "The game was a tie!" << endl; //outputs tie game
        endGame = true; //signals the end of the game
    }
}

//outputs the grid at the end of the game
void displayFinalGrid(const string grid[])
{
    system("clear"); //clears terminal screen

    //outputs updated and final tic-tac-toe playing field
    cout << "TIC-TAC-TOE" << endl;
    cout << "|-----|" << endl;
    cout << "|" << grid[0] << "|" << grid[1] << "|" << grid[2] << "|" << endl;
    cout << "|-----|" << endl;
    cout << "|" << grid[3] << "|" << grid[4] << "|" << grid[5] << "|" << endl;
    cout << "|-----|" << endl;
    cout << "|" << grid[6] << "|" << grid[7] << "|" << grid[8] << "|" << endl;
}

//reset the game when one concludes; this includes filling the array with vales 0-8
void resetGame(string grid[], int& numOfMoves, bool& repeat)
{
    string reset = ""; //determines if player wants to reset the grid
    bool validInput = false; //determines if input is valid

    do//loops at least once, possibly more loops
    {

        //prompts user to enter if they wish to play again
        cout << "game over!, play again? y/n" << endl;
        getline(cin, reset);

        //resets everything if user wishes to
        if(reset == "y" || reset == "O")
        {
            //flag to reset the game
            repeat = true;
            validInput = true;
            numOfMoves = 0;
            resetGrid(grid); //function call, resets the grid
        }
        //ends program if user wishes to
        else if (reset == "n" || reset == "N")
        {
            //Ends Program
            repeat = false;
            validInput = true;
            closingMessage(); //function call, displays good-bye message
        }
        //runs if invalid input was entered
        else
        {
            cout << "invalid entry, try again" << endl;
        }
    }while(validInput == false); //runs while invalid input is entered
}


//reassigns the original values to the array
void resetGrid(string grid[])
{
    //loops through the grid and assigns the original values to the grid
    for(int index = 0; index < GRID_SIZE; index++)
    {
        if(index == 0)
        {
            grid[0] = "0";
        }
        else if(index == 1)
        {
            grid[1] = "1";
        }
        else if (index == 2)
        {
            grid[2] = "2";
        }
        else if(index == 3)
        {
            grid[3] = "3";
        }
        else if (index == 4)
        {
            grid[4] = "4";
        }
        else if(index == 5)
        {
            grid[5] = "5";
        }
        else if (index == 6)
        {
            grid[6] = "6";
        }
        else if(index == 7)
        {
            grid[7] = "7";
        }
        else if (index == 8)
        {
            grid[8] = "8";
        }
    }
}


//displays good-bye to end user
void closingMessage()
{
    cout << "Good-Bye" << endl;
}
