#pragma once
#include <iostream>
#include <string>

class Board;
class Statistics;

class cli {
public:
    // Board rendering with 3x3 boxes
    static void printBoard(const Board& board);
    
    // Menu & messages
    static void printMenu();
    static void printMessage(const std::string& msg);
    static void printHeader(const std::string& text);
    
    // Statistics display
    static void printRecords(const Statistics& stats);
    static void printCurrentStats(const Statistics& stats);
    
private:
    static void printHorizontalLine();
    static void printCellValue(int value);
};