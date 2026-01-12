#include "Game.h"

// class init
Game::Game() : isRunning(true) {
    board.clear();
    loadPuzzle();
    stats.startTracking();
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
    std::cout <<"1 - сделать ход" << std::endl <<
                "2 - решить судоку автоматически" << std::endl <<
                "3 - отчистить доску" << std::endl <<
                "4 - показать рекорды" << std::endl <<
                "5 - текущая статистика" << std::endl <<
                "0 - выход" << std::endl;
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
                stats.recordMove();
                std::cout << "Ход выполнен!" << std::endl;
            } else {
                stats.recordError();
                std::cout << "Недопустимый ход!" << std::endl;
            }
            break;
        }

        case 2: {  // auto play
            if (engine.solve(board)) {
                stats.finishGame(true);
                std::cout << "Судоку решено!" << std::endl;
            }
            break;
        }

        case 3: {
            board.clear();
            loadPuzzle();
            stats.startTracking();
            break;
        }

        case 4: {
            stats.showRecords();
            break;
        }

        case 5: {
            stats.showCurrentStats();
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

// board hard data. generate it, is so hard
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
