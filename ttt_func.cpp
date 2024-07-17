#include <iostream>
#include <vector>

//print the current game board
void print_board(std::vector<char> board) {
  std::cout << "  1 2 3\n"; //indicate column numbers
  std::cout << "1 " << board[0] << "|" << board[1] << "|" << board[2] << "\n"; //row 1
  //std::cout << "  -----\n";
  std::cout << "2 " << board[3] << "|" << board[4] << "|" << board[5] << "\n"; //row 2
  //std::cout << "  -----\n";
  std::cout << "3 " << board[6] << "|" << board[7] << "|" << board[8] << "\n"; //row 3
  std::cout << "\n";
}

//calculate player's first input and determine validity
int p_input(int row, int col, std::vector<char> input) {

  int vector_calc = 0;

  vector_calc = ((row-1)*3)+(col-1);

  //if new vector calc == X or O, OR if the vector_calc < allowed value OR if the vector_calc > allowed value
  if (input[vector_calc] == 'X' || input[vector_calc] == 'O' || vector_calc < 0 || vector_calc > 8) {
    vector_calc = 10;
  }
  return vector_calc;
}

//check for win condition
bool win_check(bool winner, std::vector<char> input) {
  //winning combos are:
    /* 
      0, 4, 8
      0, 3, 6
      1, 4, 7
      2, 5, 8
      2, 4, 6
      0, 1, 2
      3, 4, 5
      6, 7, 8
    */
  
  if (input[0] != '-' && input[0] == input[4] && input[4] == input[8]) {
    winner = true;
  }
  else if (input[0] != '-' && input[0] == input[3] && input[3] == input[6]) {
    winner = true;
  }
  else if (input[1] != '-' && input[1] == input[4] && input[4] == input[7]) {
    winner = true;
  }
  else if (input[2] != '-' && input[2] == input[5] && input[5] == input[8]) {
    winner = true;
  }
  else if (input[2] != '-' && input[2] == input[4] && input[4] == input[6]) {
    winner = true;
  }
  else if (input[0] != '-' && input[0] == input[1] && input[1] == input[2]) {
    winner = true;
  }
  else if (input[3] != '-' && input[3] == input[4] && input[4] == input[5]) {
    winner = true;
  }
  else if (input[6] != '-' && input[6] == input[7] && input[7] == input[8]) {
    winner = true;
  }
  else {
    winner = false;
  }
  return winner;
}

//check for stalemate condition
bool stale_check(bool stalemate, std::vector<char> input) {
  stalemate = true;
  for (int i = 0; i < input.size(); ++i) {
    if (input[i] == '-') {
      stalemate = false;
    }
  }
  return stalemate;
}
