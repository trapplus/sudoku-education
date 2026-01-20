#include "Game.h"
#include "cli.h"

Game::Game() : isRunning(true) {
    board.clear();
    loadPuzzle();
    stats.startTracking();
}

void Game::run() {
    cli::printHeader("Sudoku Game");
    while (isRunning) {
        render();
        processInput();
    }
}

void Game::processInput() {
    cli::printMenu();
    
    short command = 0;
    std::cin >> command;

    switch (command) {
        case 1: {
            int row, col, value;
            std::cin >> row >> col >> value;
            
            if (engine.isMoveValid(board, row, col, value)) {
                engine.applyMove(board, row, col, value);
                stats.recordMove();
                cli::printMessage("Move applied!");
            } else {
                stats.recordError();
                cli::printMessage("Invalid move!");
            }
            break;
        }

        case 2: {
            if (engine.solve(board)) {
                stats.finishGame(true);
                cli::printMessage("Sudoku solved!");
            }
            break;
        }

        case 3: {
            board.clear();
            loadPuzzle();
            stats.startTracking();
            cli::printMessage("Board cleared!");
            break;
        }

        case 4: {
            cli::printRecords(stats);
            break;
        }

        case 5: {
            cli::printCurrentStats(stats);
            break;
        }

        case 0: {
            isRunning = false;
            break;
        }
    }
}

void Game::render() const {
    cli::printBoard(board);
}

void Game::loadPuzzle() {
    int puzzle[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            board.set(i, j, puzzle[i][j]);
        }
    }
}