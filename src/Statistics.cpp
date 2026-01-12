#include "Statistics.h"


Statistics::Statistics() {
    loadFromFile();
}


Statistics::~Statistics() {
    saveToFile();
}


void Statistics::startTracking(){
    isTracking = true;

    // start time
    startTime = std::chrono::steady_clock::now();

    // clean data
    currentGame.timeSeconds = 0;
    currentGame.moves = 0;
    currentGame.errors = 0;
    currentGame.autoSolved = false;
    currentGame.date = "";

}

void Statistics::loadFromFile() {
    std::ifstream file("records.json");

    // init arr for record if file not founded
    if (!file.is_open()) {
        records.clear();
        return;
    }

    // json file parse
    json j = json::parse(file);

    // read data from recrods arr
    for (auto& item : j["records"]) {
        GameRecord gr;
        gr.timeSeconds = item["timeSeconds"];
        gr.moves = item["moves"];
        gr.errors = item["errors"];
        gr.date = item["date"];
        gr.autoSolved = item["autoSolved"];

        // push data to json
        records.push_back(gr);
    }
}


void Statistics::saveToFile() {
    json j;

    // convers data to json format
    for (const auto& record : records) {
        json jRecord;
        jRecord["timeSeconds"] = record.timeSeconds;
        jRecord["moves"] = record.moves;
        jRecord["errors"] = record.errors;
        jRecord["date"] = record.date;
        jRecord["autoSolved"] = record.autoSolved;

        // add data to array
        j["records"].push_back(jRecord);
    }

    // write file
    std::ofstream file("records.json");
    file << j.dump(4);
}

void Statistics::saveCurrentRecord() {
    // append currentGame to records
    records.push_back(currentGame);

    // sort games (Best of 50)
        std::sort(records.begin(), records.end(),
            [](const GameRecord& a, const GameRecord& b) {
                // auto solved games to end
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

    // calculate game time
    auto endTime = std::chrono::steady_clock::now();
    auto duration = endTime - startTime;

    // convert to seconds
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
    currentGame.timeSeconds = seconds.count();

    // write data
    currentGame.date = getCurrentDateTime();

    currentGame.autoSolved = autoSolved;

    // save record
    saveCurrentRecord();
}


// this method from SOF
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

void Statistics::showRecords() const {
    std::cout << "\n========== ТОП-10 РЕКОРДОВ ==========" << std::endl;

    if (records.empty()) {
        std::cout << "Пока нет сохранённых игр!" << std::endl;
        std::cout << "====================================\n" << std::endl;
        return;
    }

    std::cout << "# | Время | Ходы | Ошибки | Дата | Авто" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    int count = std::min(10, (int)records.size());

    for (int i = 0; i < count; ++i) {
        const auto& rec = records[i];

        // Форматируем время в MM:SS
        int minutes = rec.timeSeconds / 60;
        int seconds = rec.timeSeconds % 60;

        std::cout << (i + 1) << " | ";
        std::cout << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " | ";
        std::cout << rec.moves << " | ";
        std::cout << rec.errors << " | ";
        std::cout << rec.date.substr(0, 10) << " | ";
        std::cout << (rec.autoSolved ? "Да" : "Нет") << std::endl;
    }

    std::cout << "====================================\n" << std::endl;
}


void Statistics::showCurrentStats() const {
    std::cout << "\n========== ТЕКУЩАЯ СТАТИСТИКА ==========" << std::endl;

    if (!isTracking) {
        std::cout << "Игра не начата!" << std::endl;
        std::cout << "========================================\n" << std::endl;
        return;
    }

    int elapsed = getElapsedSeconds();
    int minutes = elapsed / 60;
    int seconds = elapsed % 60;

    std::cout << "Время игры: " << minutes << ":"
              << (seconds < 10 ? "0" : "") << seconds << std::endl;
    std::cout << "Ходов: " << currentGame.moves << std::endl;
    std::cout << "Ошибок: " << currentGame.errors << std::endl;
    std::cout << "========================================\n" << std::endl;
}
