#ifndef GAME_H
#define GAME_H
#include <iostream>

class Game {
private:
  const int EMPTY = 0;
  const int PLAYER_1 = 1;
  const int PLAYER_2 = 2;
  int board[3][3]{};
  int currentPlayer;
public:
  [[nodiscard]] int getCurrentPlayer() const;
  void makeMove(int x, int y);
  bool checkWin();
  void switchPlayer();
  void printBoard();


  Game() {
    currentPlayer = 1;
    for (auto & row : board) {
      for (int & cell : row) {
        cell = 0;
      }
    }
  }
};

#endif // GAME_H