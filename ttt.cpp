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
  bool valid_player_name = true;

  do{
    std::cout << "Enter player 1's name: ";
    getline(std::cin, m_player1);

    valid_player_name = validate_players_names(m_player1);
    if(!(valid_player_name)){
      std::cout << "invalid name\nEnter a single word with alpha chars only!" << std::endl;
    }
  }while(!valid_player_name);

  do{
    std::cout << "Enter player 2's name: ";
    getline(std::cin, m_player2);

    valid_player_name = validate_players_names(m_player2);
    if(!(valid_player_name)){
      std::cout << "invalid name\nEnter a single word with alpha chars only!" << std::endl;
    }
  }while(!valid_player_name);

  system("clear");

  std::cout << "Welcome to tic-tac-toe " << m_player1 << "(X) and " << m_player2 << "(O)" << std::endl;
}

bool TTT::validate_players_names(std::string player_name)
{    
  unsigned int counter = 0; //used to stop while loop

    //loop checks to see if user's name is all alpha characters
    while(counter < player_name.length() || player_name.length() == 0){
        if(!isalpha(player_name[counter])){//runs if non alphabet characters detected
            counter = 0;//resets counter to 0
            return false;
        }
        else{
            counter++; //increments counter, will stop while loop
        }
    }
    return true;
}
