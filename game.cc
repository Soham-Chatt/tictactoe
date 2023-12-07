#include "game.h"

void Game::makeMove(int x, int y) {
  if (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != EMPTY) throw std::invalid_argument("Invalid move.");
  board[x][y] = currentPlayer;
  std::cout << "Player " << currentPlayer << " moved to (" << x << ", " << y << ")." << std::endl;
}

bool Game::checkWin() {
  for (int i = 0; i < 3; i++) {
    if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
        (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
      return true;
    }
  }

  if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
      (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
    return true;
  }

  return false;
}

void Game::printBoard() {
  for (int i = 0; i < 3; i++) {
    std::cout << board[i][0] << " " << board[i][1] << " " << board[i][2] << std::endl;
  }
}

void Game::switchPlayer() {
  currentPlayer = currentPlayer == PLAYER_1 ? PLAYER_2 : PLAYER_1;
}

int Game::getCurrentPlayer() const {
  return currentPlayer;
}
