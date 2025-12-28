#include "Engine.h"
#include "Board.h"


bool Engine::isMoveValid(const Board& board, int row, int col, int value) const {
    return true; 
}

void Engine::applyMove(Board& board, int row, int col, int value) {
    board.set(row, col, value); 
}

bool Engine::solve(Board& board) {
    return true; 
}

bool Engine::isRowValid(const Board& board, int row, int value) const { return true; }
bool Engine::isColValid(const Board& board, int col, int value) const { return true; }
bool Engine::isBoxValid(const Board& board, int row, int col, int value) const { return true; }
