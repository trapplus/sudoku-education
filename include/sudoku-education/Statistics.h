 #pragma once
 
 #include <vector>
 #include <string>
 #include <chrono>
 
 class Statistics {
 public:
     Statistics();   // load json
     ~Statistics();  // save json
 
     // current game tracking
     void startTracking();
     void recordMove();
     void recordError();
     void finishGame(bool autoSolved);
 
     // show methods
     void showRecords() const;
     void showCurrentStats() const;
     int getElapsedSeconds() const;
 
 private:
     struct GameRecord {
         int timeSeconds;
         int moves;
         int errors;
         std::string date;
         bool autoSolved;
     };
 
     std::vector<GameRecord> records;  // records data
 
     // current game
     GameRecord currentGame;
     std::chrono::time_point<std::chrono::steady_clock> startTime;
     bool isTracking = false;
 
     // json methods
     void loadFromFile();
     void saveToFile();
     void saveCurrentRecord();
 };
