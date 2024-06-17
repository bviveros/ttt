/* 
 * tic-tac-toe class
 * class functions defined
 */


#include "ttt.h"

void TTT::initialize_grid()
{
  char digits[] = {'1', '2','3','4','5','6','7','8','9'};
  for(int i = 0; i < 9; i++){
    grid[i] = digits[i];
  }

}

void TTT::display_updated_grid()
{
  system("clear");

  std::cout << "It is now " << cur_player << "'s turn!" << std::endl;
  std::cout << "Current Grid" << std::endl;
  for(int i = 0; i < 9; i++){
    std::cout << grid[i];
    if((i+1)%3==0){
      std::cout << std::endl;
    std::cout << "___ ___ ___" << std::endl;
      std::cout << std::endl;
    }
    if((i+1)%3!=0){
      std::cout << " || ";
    }
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

  cur_player = m_player1;

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

void TTT::switch_player_turn()
{
  first_players_turn = !first_players_turn;
  if(first_players_turn){
    cur_player = m_player1;
  }
  else{
    cur_player = m_player2;
  }
  
}

std::string TTT::get_current_player_name()
{
  return cur_player;
}

void TTT::player_move()
{
  if(first_players_turn){
    cur_piece = m_x_piece;
  }
  else{
    cur_piece = m_o_piece;
  }

  bool valid = false;
  
  do {
    std::cout << "Pick a number on the current grid" << std::endl;
    getline(std::cin ,player_choice);
    valid = valid_move();
    if(!valid){
      std::cout << "Invalid choice; try again" << std::endl;
    }
  }while(!valid);

}

bool TTT::valid_move()
{
  int board_position = 0;

  if(!player_choice.empty() && player_choice[1] == '\0'){
    board_position = atoi(player_choice.c_str());
    return ((board_position>=1) && (board_position<=9) && (check_position(board_position)));
  }
  return false;
}

bool TTT::check_position(int board_position)
{
  return(!((grid[board_position-1] == m_o_piece) || (grid[board_position-1] == m_x_piece)));
}

void TTT::update_grid()
{
  int board_position = 0;

  board_position = atoi(player_choice.c_str());

  grid[board_position-1] = cur_piece;
}

bool TTT::winner_found()
{
  return false;
}

bool TTT::tie_found()
{
  return false;
}