#include "Board.h"

Board::Board() {
    clear();
}

void Board::clear() {
    for (auto& row : cells)
        row.fill(0);
}

int Board::get(int row, int col) const {
    return cells[row][col];
}

void Board::set(int row, int col, int value) {
    cells[row][col] = value;
}

bool Board::isEmpty(int row, int col) const {
    return cells[row][col] == 0;  // if 0 = вернет true
}
