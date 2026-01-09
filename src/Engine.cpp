#include "Engine.h"
#include "Board.h"
#include "Validator.h"

// validate move 4 applyMove
bool Engine::isMoveValid(const Board& board, int row, int col, int value) const {
    return Validator::isRowValid(board, row, value) &&
           Validator::isColValid(board, col, value) &&
           Validator::isBoxValid(board, row, col, value); 
}

// Применить ход
void Engine::applyMove(Board& board, int row, int col, int value) {
    board.set(row, col, value); // apply after validation
}

/*
Как работает bt алгоритм:
1. Находит пустую ячейку
2. Пробуем поставить 1..9 пока не подойдет!
3. Ставим 5 и вызываем рекурсию для следующей ячейки
4. Если в какой-то момент не подходит ничего откат и пробуем другое число
*/

// BT алгос by ai
bool Engine::solve(Board& board) {
    // Ищем первую пустую ячейку
    for (int row = 0; row < Board::Size; ++row) {
        for (int col = 0; col < Board::Size; ++col) {
            if (board.isEmpty(row, col)) {  // нашли пустую ячейку
                // трай всех чисел 1..9
                for (int num = 1; num <= 9; ++num) {
                    // проверка
                    if (isMoveValid(board, row, col, num)) {
                        board.set(row, col, num);
                        // рекурсия
                        if (solve(board)) {
                            return true;
                        }
                        // BT
                        board.set(row, col, 0);
                    }
                }
                // случай если не одно из чисел не подошло
                return false;
            }
        }
    }
    
    // все ячейким заполнены - вин
    return true;
}