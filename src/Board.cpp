#include "Board.h"

Board::Board() {
    clear();
}

void Board::clear() {
    for (auto& row : cells)
        row.fill(0);
}

void Board::reset() {
    clear();
}

int Board::get(int row, int col) const {
    return cells[row][col];
}

void Board::set(int row, int col, int value) {
    cells[row][col] = value;
}

bool Board::isEmpty(int row, int col) const {
    return cells[row][col] == 0;
}

void Board::print() const {
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            std::cout << cells[i][j] << " ";
        }
        std::cout << "\n";
    }
}
