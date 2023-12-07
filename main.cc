#include "game.h"

int main() {
  Game game{};
  std::cout << "Welcome to Tic Tac Toe!" << std::endl;
  game.printBoard();

  while (true) {
    int x, y;
    std::cout << "Player " << game.getCurrentPlayer() << ", please enter your move." << std::endl;
    std::cin >> x >> y;
    game.makeMove(x, y);
    game.printBoard();
    if (game.checkWin()) break;
    game.switchPlayer();
  }

  std::cout << "Player " << game.getCurrentPlayer() << " wins!" << std::endl;
  std::cout << "Thanks for playing!" << std::endl;

  return 0;
}
