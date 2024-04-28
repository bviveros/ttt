/*
 * The main file that'll run the tic-tac-toe class
 */

/* included libraries */
#include <iostream>
#include <string>
#include <iomanip>

/* only using specific sections from the std namespace */
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setfill;

/* user defined libraries */
#include "ttt.h"

/* function prototypes */
void splash_screen();

int main()
{
    splash_screen();

    return 0;
}

void splash_screen()
{
    system("clear"); 
    cout << setfill('*') << setw(24) << "\n" << setfill('*') << setw(24) << "\n";
    cout << "****  TIC-TAC-TOE  ****" << endl;
    cout << "****      By       ****" << endl;
    cout << "****Braulio Viveros****" << endl;
    cout << setfill('*') << setw(24) << "\n" << setfill('*') << setw(24) << "\n";

    system("read ballZ"); //pauses the program
}