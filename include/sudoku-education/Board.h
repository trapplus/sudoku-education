#pragma once
#include <array>
#include <iostream>

class Board {
public:
    static constexpr int Size = 9; // board const size

    Board(); // class init

    void clear(); // clear board 
    int  get(int row, int col) const; // get val
    void set(int row, int col, int value); // set val
    bool isEmpty(int row, int col) const; // check is void cell
    void print() const; // render board

private:
    std::array<std::array<int, Size>, Size> cells;  // td arr 9x9
};
