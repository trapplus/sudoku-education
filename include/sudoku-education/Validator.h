#pragma once

class Board;

class Validator {
public:
    static bool isRowValid(const Board& board, int row, int value);
    static bool isColValid(const Board& board, int col, int value);
    static bool isBoxValid(const Board& board, int row, int col, int value);
};
