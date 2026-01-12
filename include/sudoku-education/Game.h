#pragma once

#include "Board.h"
#include "Engine.h"
#include "Statistics.h"

class Game {
public:
    Game();
    void run();
    void reset();

private:
    Board board;
    Engine engine;
    Statistics stats;

    void processInput();
    void update();
    void render() const;
    void loadPuzzle();

    bool isRunning; // game status
};