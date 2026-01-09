#include "Game.h"
#include <cstddef> // idk, autoimport
#include <iostream>

// class init
Game::Game() : isRunning(true) {
    board.clear();
    loadPuzzle();
}

// game mainloop 
void Game::run() {
    std::cout << "=== Sudoku Game ===" << std::endl;

    
    while (isRunning) {
        render();
        processInput();
    }
}

// player input proc
void Game::processInput() {
    std::cout << "1 - сделать ход" << std::endl << "2 - решить судоку автоматически" << std::endl << "3 - выход" << std::endl;
    std::cout << "Введите команду: ";
    short command = 0;
    std::cin >> command; 
    
    switch (command) {
        case 1: { 
            int row, col, value;
            std::cin >> row >> col >> value;
            
            // check move via engine
            if (engine.isMoveValid(board, row, col, value)) {
                engine.applyMove(board, row, col, value);
                std::cout << "Ход выполнен!" << std::endl;
            } else {
                std::cout << "Недопустимый ход!" << std::endl;
            }
            break;
        }
        
        case 2: {  // auto play
            if (engine.solve(board)) {
                std::cout << "Судоку решено!" << std::endl;
            }
            break;
        }
        
        case 0: { // exit
            isRunning = false;
            break;
        }
    }
}

// render
void Game::render() const {
    board.print();
}

// idk, im forget)
void Game::loadPuzzle() {
    int puzzle[9][9] = { };
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            board.set(i, j, puzzle[i][j]);

        }
    }
}