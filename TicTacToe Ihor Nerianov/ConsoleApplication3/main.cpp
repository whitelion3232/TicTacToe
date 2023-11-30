// main.cpp

#include "Game.h"
#include <iostream>

int main() {
    std::string playerXName, playerOName;

    // Get names for players 'X' and 'O'
    std::cout << "Enter name for Player X: ";
    std::cin >> playerXName;
    std::cout << "Enter name for Player O: ";
    std::cin >> playerOName;

    Game ticTacToeGame(playerXName, playerOName);
    ticTacToeGame.play();

    return 0;
}