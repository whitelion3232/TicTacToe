// TicTacToe.h

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <string>

class TicTacToe {
public:
    // Function to print the Tic Tac Toe board
    static void printBoard(const std::vector<std::vector<char>>& board);

    // Function to check if a player has won
    static bool checkWin(const std::vector<std::vector<char>>& board, char player);

    // Function to check if the board is full
    static bool isBoardFull(const std::vector<std::vector<char>>& board);

    // Function to play the game
    static void playGame();
};

#endif // TICTACTOE_H