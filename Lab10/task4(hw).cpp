#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
#include <ctime>

namespace fs = std::filesystem;
using namespace std;

class Logger {
private:
    string logFileName;
    size_t maxFileSize;

    void rotateLogs() {
        size_t logIndex = 1;
        while (fs::exists(logFileName + to_string(logIndex) + ".txt")) {
            logIndex++;
        }
        // Rename the current log file to logX.txt where X is the index
        fs::rename(logFileName + ".txt", logFileName + to_string(logIndex) + ".txt");
    }

public:
    Logger(string fileName, size_t maxSize = 1024 * 1024) : logFileName(fileName), maxFileSize(maxSize) {}

    void log(const string& message) {
        // Check the size of the current log file
        if (fs::exists(logFileName + ".txt") && fs::file_size(logFileName + ".txt") >= maxFileSize) {
            rotateLogs(); // Rotate the logs if file size exceeds the limit
        }

        ofstream logFile(logFileName + ".txt", ios_base::app);
        if (logFile.is_open()) {
            // Get the current time
            time_t now = time(0);
            char* dt = ctime(&now);
            dt[strlen(dt) - 1] = '\0'; // Remove the newline character at the end

            logFile << "[" << dt << "] " << message << endl;
            logFile.close();
        }
        else {
            cerr << "Unable to open log file!" << endl;
        }
    }
};

int main() {
    Logger logger("log", 1024 * 1024);  // 1MB max file size
    logger.log("This is a test log message.");
    logger.log("This is another log message.");
    
    return 0;
}
