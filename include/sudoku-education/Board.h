#pragma once
#include <array>

class Board {
public:
    static constexpr int Size = 9; // board const size

    Board(); 
    
    void clear();
    // get cell val
    int  get(int row, int col) const;
    // set cell val
    void set(int row, int col, int value);
    // check is void cell
    bool isEmpty(int row, int col) const; 

private:
    std::array<std::array<int, Size>, Size> cells;  // td arr 9x9
};