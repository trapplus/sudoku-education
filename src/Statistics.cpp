#include "Statistics.h"

Statistics::Statistics() {
    loadFromFile();
}

Statistics::~Statistics() {
    saveToFile();
}

void Statistics::startTracking(){
    isTracking = true;
    startTime = std::chrono::steady_clock::now();

    currentGame.timeSeconds = 0;
    currentGame.moves = 0;
    currentGame.errors = 0;
    currentGame.autoSolved = false;
    currentGame.date = "";
}

void Statistics::loadFromFile() {
    std::ifstream file("records.json");

    if (!file.is_open()) {
        records.clear();
        return;
    }

    json j = json::parse(file);

    for (auto& item : j["records"]) {
        GameRecord gr;
        gr.timeSeconds = item["timeSeconds"];
        gr.moves = item["moves"];
        gr.errors = item["errors"];
        gr.date = item["date"];
        gr.autoSolved = item["autoSolved"];

        records.push_back(gr);
    }
}

void Statistics::saveToFile() {
    json j;

    for (const auto& record : records) {
        json jRecord;
        jRecord["timeSeconds"] = record.timeSeconds;
        jRecord["moves"] = record.moves;
        jRecord["errors"] = record.errors;
        jRecord["date"] = record.date;
        jRecord["autoSolved"] = record.autoSolved;

        j["records"].push_back(jRecord);
    }

    std::ofstream file("records.json");
    file << j.dump(4);
}

void Statistics::saveCurrentRecord() {
    records.push_back(currentGame);

    std::sort(records.begin(), records.end(),
        [](const GameRecord& a, const GameRecord& b) {
            if (a.autoSolved != b.autoSolved) {
                return !a.autoSolved;
            }
            return a.timeSeconds < b.timeSeconds;
        });

    if (records.size() > 50) {
        records.resize(50);
    }
}

void Statistics::recordMove() {
    if (isTracking) {
        currentGame.moves++;
    }
}

void Statistics::recordError() {
    if (isTracking) {
        currentGame.errors++;
    }
}

void Statistics::finishGame(bool autoSolved) {
    if (!isTracking) {
        return;
    }

    isTracking = false;

    auto endTime = std::chrono::steady_clock::now();
    auto duration = endTime - startTime;
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
    currentGame.timeSeconds = seconds.count();

    currentGame.date = getCurrentDateTime();
    currentGame.autoSolved = autoSolved;

    saveCurrentRecord();
}

std::string Statistics::getCurrentDateTime() const {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* tm = std::localtime(&now_c);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm);
    return std::string(buffer);
}

int Statistics::getElapsedSeconds() const {
    if (!isTracking) {
        return 0;
    }

    auto now = std::chrono::steady_clock::now();
    auto duration = now - startTime;
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);

    return seconds.count();
}

// Getters for CLI
const std::vector<Statistics::GameRecord>& Statistics::getRecords() const {
    return records;
}

int Statistics::getCurrentMoves() const {
    return currentGame.moves;
}

int Statistics::getCurrentErrors() const {
    return currentGame.errors;
}

bool Statistics::isCurrentlyTracking() const {
    return isTracking;
}