// Board.cpp

#include "Board.h"
#include <iostream>

Board::Board() : board(3, std::vector<char>(3, ' ')) {}

void Board::print() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            char symbol = board[i][j];
            if (symbol == ' ') {
                symbol = ' '; // Display an empty space for empty spaces
            }

            std::cout << symbol;

            if (j < 2) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "---------" << std::endl;
        }
    }
}

bool Board::makeMove(int row, int col, char playerSymbol) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return false; // Invalid move
    }

    board[row][col] = playerSymbol;
    return true;
}

bool Board::isFull() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool Board::checkWin(char playerSymbol) const {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == playerSymbol && board[i][1] == playerSymbol && board[i][2] == playerSymbol) ||
            (board[0][i] == playerSymbol && board[1][i] == playerSymbol && board[2][i] == playerSymbol)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol) ||
        (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)) {
        return true;
    }

    return false;
}

void Board::reset() {
    // Reset the board to an empty state