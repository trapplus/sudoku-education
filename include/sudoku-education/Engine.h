#pragma once

class Board;

class Engine {
public:
    bool isMoveValid(const Board& board, int row, int col, int value) const;
    void applyMove(Board& board, int row, int col, int value);
    bool solve(Board& board);

private:
    bool isRowValid(const Board& board, int row, int value) const;
    bool isColValid(const Board& board, int col, int value) const;
    bool isBoxValid(const Board& board, int row, int col, int value) const;
};
