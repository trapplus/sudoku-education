#include "cli.h"
#include "Board.h"
#include "Statistics.h"
#include <algorithm>

void cli::printBoard(const Board& board) {
    std::cout << "\n";
    for (int row = 0; row < 9; ++row) {
        if (row % 3 == 0) {
            printHorizontalLine();
        }
        
        for (int col = 0; col < 9; ++col) {
            if (col % 3 == 0) {
                std::cout << "| ";
            }
            printCellValue(board.get(row, col));
        }
        std::cout << "|" << std::endl;
    }
    printHorizontalLine();
    std::cout << "\n";
}

void cli::printMenu() {
    std::cout << "\n========== MENU ==========" << std::endl;
    std::cout << "1 - Make move" << std::endl;
    std::cout << "2 - Auto solve" << std::endl;
    std::cout << "3 - Clear board" << std::endl;
    std::cout << "4 - Show records" << std::endl;
    std::cout << "5 - Current stats" << std::endl;
    std::cout << "0 - Exit" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Command: ";
}

void cli::printMessage(const std::string& msg) {
    std::cout << "\n>> " << msg << "\n" << std::endl;
}

void cli::printHeader(const std::string& text) {
    std::cout << "\n========== " << text << " ==========" << std::endl;
}

void cli::printRecords(const Statistics& stats) {
    const auto& records = stats.getRecords();
    
    printHeader("TOP-10 RECORDS");
    
    if (records.empty()) {
        std::cout << "No saved games yet!" << std::endl;
        std::cout << "====================================\n" << std::endl;
        return;
    }
    
    std::cout << "# | Time  | Moves | Errors | Date       | Auto" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    
    int count = std::min(10, (int)records.size());
    
    for (int i = 0; i < count; ++i) {
        const auto& rec = records[i];
        
        int minutes = rec.timeSeconds / 60;
        int seconds = rec.timeSeconds % 60;
        
        std::cout << (i + 1) << " | ";
        std::cout << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " | ";
        std::cout << rec.moves << "     | ";
        std::cout << rec.errors << "      | ";
        std::cout << rec.date.substr(0, 10) << " | ";
        std::cout << (rec.autoSolved ? "Yes" : "No") << std::endl;
    }
    
    std::cout << "====================================\n" << std::endl;
}

void cli::printCurrentStats(const Statistics& stats) {
    printHeader("CURRENT STATISTICS");
    
    if (!stats.isCurrentlyTracking()) {
        std::cout << "Game not started!" << std::endl;
        std::cout << "========================================\n" << std::endl;
        return;
    }
    
    int elapsed = stats.getElapsedSeconds();
    int minutes = elapsed / 60;
    int seconds = elapsed % 60;
    
    std::cout << "Game time: " << minutes << ":" 
              << (seconds < 10 ? "0" : "") << seconds << std::endl;
    std::cout << "Moves: " << stats.getCurrentMoves() << std::endl;
    std::cout << "Errors: " << stats.getCurrentErrors() << std::endl;
    std::cout << "========================================\n" << std::endl;
}

void cli::printHorizontalLine() {
    std::cout << "+-------+-------+-------+" << std::endl;
}

void cli::printCellValue(int value) {
    if (value == 0) {
        std::cout << ". ";
    } else {
        std::cout << value << " ";
    }
}