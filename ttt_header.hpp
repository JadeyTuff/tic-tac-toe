//print the current game board
void print_board(std::vector<char> board);

//calculate player's space on the board and determine validity
int p_input(int row, int col, std::vector<char> input);

//check for win condition
bool win_check(bool winner, std::vector<char> input);

//check for stalemate condition
bool stale_check(bool stalemate, std::vector<char> input);
