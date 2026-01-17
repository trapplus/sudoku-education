#pragma once

// forward declaration
class Board;

class Engine {
public:
    bool isMoveValid(const Board& board, int row, int col, int value) const;
    void applyMove(Board& board, int row, int col, int value);
    bool solve(Board& board);
};