// Board.h

#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
private:
    std::vector<std::vector<char>> board;

public:
    Board();
    void print() const;
    bool makeMove(int row, int col, char playerSymbol);
    bool isFull() const;
    bool checkWin(char playerSymbol) const;
    void reset();
};

#endif // BOARD_H