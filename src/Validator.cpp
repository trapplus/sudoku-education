#include "Validator.h"
#include "Board.h"

// row validation
bool Validator::isRowValid(const Board& board, int row, int value) {
    for (int col = 0; col < Board::Size; ++col) {
        if (board.get(row, col) == value) {
            return false;
        }
    }
    return true;
}

// col validation
bool Validator::isColValid(const Board& board, int col, int value) {
    for (int row = 0; row < Board::Size; ++row) {
        if (board.get(row, col) == value) {
            return false;
        }
    }
    return true;
}

// 3х3 cells validation
bool Validator::isBoxValid(const Board& board, int row, int col, int value) {
    int boxStartRow = (row / 3) * 3;
    int boxStartCol = (col / 3) * 3;
    
    // all cells validation
    for (int r = boxStartRow; r < boxStartRow + 3; ++r) {
        for (int c = boxStartCol; c < boxStartCol + 3; ++c) {
            if (board.get(r, c) == value) {
                return false;
            }
        }
    }
    return true;
}