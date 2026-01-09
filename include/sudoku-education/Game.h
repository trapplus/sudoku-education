#pragma once

#include "Board.h"
#include "Engine.h"

class Game {
public:
    Game();
    void run();
    void reset();

private:
    Board board;
    Engine engine;

    void processInput();
    void update();
    void render() const;
    void loadPuzzle();

    bool isRunning; // game status
};