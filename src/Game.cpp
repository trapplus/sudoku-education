#include "Game.h"
#include <iostream>

Game::Game() : isRunning(true) {
    board.clear();
}

void Game::run() {
    while (isRunning) {
        render();
        processInput();
        update();

        isRunning = false;
    }
}

void Game::reset() {
    board.clear();
    isRunning = true;

}

void Game::processInput() {

}

void Game::update() {
    
}

void Game::render() const {
    board.print();
}
