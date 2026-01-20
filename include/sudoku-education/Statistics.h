#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <iostream>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Statistics {
public:
    struct GameRecord {
        int timeSeconds;
        int moves;
        int errors;
        std::string date;
        bool autoSolved;
    };

    Statistics();   // load json
    ~Statistics();  // save json

    // current game tracking
    void startTracking();
    void recordMove();
    void recordError();
    void finishGame(bool autoSolved);

    // getters for CLI
    const std::vector<GameRecord>& getRecords() const;
    int getElapsedSeconds() const;
    int getCurrentMoves() const;
    int getCurrentErrors() const;
    bool isCurrentlyTracking() const;

private:
    std::vector<GameRecord> records;  // records data

    // current game
    GameRecord currentGame;
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    bool isTracking = false;

    // json methods
    void loadFromFile();
    void saveToFile();
    void saveCurrentRecord();
    std::string getCurrentDateTime() const;
};