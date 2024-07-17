#include <iostream>
#include <vector>
#include "ttt_header.hpp"

int main() {

  std::cout << "Let's play Tic Tac Toe\n";
  std::cout << "----------------------\n";
  std::cout << "\n";

  std::cout << "Player 1 will be X\n";
  std::cout << "Player 2 will be O\n";
  std::cout << "\n";

  std::vector<char> input = {'-','-','-','-','-','-','-','-','-'};
  
  print_board(input);

  bool p1_turn = false;
  bool winner = false;
  bool stalemate = false;

  int p1_space = 0;
  int p2_space = 0;

  int row = 0;
  int col = 0;

  do {

    p1_turn = !p1_turn;

    if (p1_turn == true) {
      
      std::cout << "Player 1, it is your turn. \n";

      std::cout << "Please enter a row number 1-3: ";
      std::cin >> row;

      std::cout << "Please enter a column number 1-3: ";
      std::cin >> col;

      p1_space = p_input(row, col, input);

      if (p1_space != 10) {
        input[p1_space] = 'X';
      }
      else {
        std::cout << "Your input was invalid.  Please enter a valid row and column or your turn will be forfeit. \n";

        std::cout << "Please enter a row number 1-3: ";
        std::cin >> row;

        std::cout << "Please enter a column number 1-3: ";
        std::cin >> col;

        p1_space = p_input(row, col, input);
      }
      if (p1_space != 10) {
        input[p1_space] = 'X';
      }
      else {
        std::cout << "Moving on to the next player. \n";
      }
    }
    
    else {

      std::cout << "Player 2, it is your turn. \n";

      std::cout << "Please enter a row number 1-3: ";
      std::cin >> row;

      std::cout << "Please enter a column number 1-3: ";
      std::cin >> col;

      p2_space = p_input(row, col, input);

      if (p2_space != 10) {
        input[p2_space] = 'X';
      }
      else {
        std::cout << "Your input was invalid.  Please enter a valid row and column or your turn will be forfeit. \n";

        std::cout << "Please enter a row number 1-3: ";
        std::cin >> row;

        std::cout << "Please enter a column number 1-3: ";
        std::cin >> col;

        p2_space = p_input(row, col, input);
      }
      if (p2_space != 10) {
        input[p2_space] = 'O';
      }
      else {
        std::cout << "Moving on to the next player. \n";
      }

    }

    print_board(input);

    winner = win_check(winner, input);
    stalemate = stale_check(stalemate, input);

  } while (winner == false && stalemate == false);

  if (stalemate == true) {
    std::cout << "No more moves.  This game ends in a stalemate. \n";
  }
  else if (winner == true && p1_turn == true) {
    std::cout << "Congratulations, Player 1!  You win! \n";
  }
  else {
    std::cout << "Congratulations, Player 2!  You win! \n";
  }
  return 0;
}
