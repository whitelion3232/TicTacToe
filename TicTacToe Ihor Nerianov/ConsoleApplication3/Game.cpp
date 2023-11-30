// Game.cpp

#include "Game.h"
#include <iostream>

Game::Game(const std::string& playerXName, const std::string& playerOName)
    : playerX(playerXName, 'X'), playerO(playerOName, 'O'), winnerName(""), rounds(0), playerXPoints(0), playerOPoints(0) {}

void Game::play() {
    char currentPlayerSymbol = 'X';

    while (rounds < 3) {
        // Print the current state of the board with row and column indices starting from 1
        std::cout << "Round " << rounds + 1 << std::endl;
        std::cout << "Current Board:" << std::endl;
        board.print();

        // Get the player's move
        int row, col;
        std::cout << "Player " << currentPlayerSymbol << " (" << ((currentPlayerSymbol == 'X') ? playerX.getName() : playerO.getName()) << "), enter your move (row and column): ";
        std::cin >> row >> col;

        // Adjust the indices to match the array indexing (subtract 1)
        row -= 1;
        col -= 1;

        // Check if the move is valid
        if (!board.makeMove(row, col, currentPlayerSymbol)) {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        // Check if the current player has won
        if (board.checkWin(currentPlayerSymbol)) {
            // Print the final state of the board
            std::cout << "Current Board:" << std::endl;
            board.print();

            // Store the winner's name and update points
            winnerName = (currentPlayerSymbol == 'X') ? playerX.getName() : playerO.getName();
            (currentPlayerSymbol == 'X') ? playerXPoints++ : playerOPoints++;

            std::cout << "Player " << currentPlayerSymbol << " (" << winnerName << ") wins round " << rounds + 1 << "!" << std::endl;
            rounds++;

            // Display points table
            displayPointsTable();
            std::cout << std::endl;

            // Reset the board for the next round
            board.reset();
            continue;
        }

        // Check if the board is full (a tie)
        if (board.isFull()) {
            // Print the final state of the board
            std::cout << "Current Board:" << std::endl;
            board.print();

            std::cout << "Round " << rounds + 1 << " is a tie!" << std::endl;
            rounds++;

            // Display points table
            displayPointsTable();
            std::cout << std::endl;

            // Reset the board for the next round
            board.reset();
            continue;
        }

        // Switch to the other player
        currentPlayerSymbol = (currentPlayerSymbol == 'X') ? 'O' : 'X';
    }

    // Display the final winner
    std::cout << "Final Winner: " << ((playerXPoints > playerOPoints) ? playerX.getName() : playerO.getName()) << std::endl;
}

void Game::displayPointsTable() const {
    std::cout << "Points Table:" << std::endl;
    std::cout << playerX.getName() << " | " << playerO.getName() << std::endl;
    std::cout << playerXPoints << " | " << playerOPoints << std::endl;
}