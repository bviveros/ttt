/* 
 * tic-tac-toe class
 * class functions defined
 */


#include "ttt.h"

void TTT::initialize_grid()
{
  int k = 1;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      grid[i][j] = std::to_string(k);
      k++;
    }
  }

}

void TTT::display_updated_grid()
{
  std::cout << "Current Grid" << std::endl;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      std::cout << grid[i][j];
      if(j == 2){break;}
      std::cout << " || ";
    }
    std::cout << std::endl;
    if( i == 2){break;}
    std::cout << "___ ___ ___" << std::endl;
    std::cout << std::endl;
  }
}

void TTT::set_players_names()
{
  std::cout << "Enter player 1's name: ";
  std::cin >> m_player1;

  std::cout << "Enter player 2's name: ";
  std::cin >> m_player2;

  system("clear");

  std::cout << "Welcome to tic-tac-toe " << m_player1 << "(X) and " << m_player2 << "(O)" << std::endl;
}

