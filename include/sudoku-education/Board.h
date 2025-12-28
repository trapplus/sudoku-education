#pragma once

#include <array>
#include <iostream>

class Board {
public:
    static constexpr int Size = 9;

    Board();

    void clear();
    void reset();

    int  get(int row, int col) const;
    void set(int row, int col, int value);

    bool isEmpty(int row, int col) const;
    void print() const;

private:
    std::array<std::array<int, Size>, Size> cells;
};
