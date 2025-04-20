#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum LogSeverity { INFO, WARNING, ERROR };

class Logger {
private:
    vector<string> logs;
    const int maxLogs = 1000;
    const string adminPassword = "secure123";
    int authAttempts = 0;
    const int maxAuthAttempts = 3;

    void addLog(const string& module, LogSeverity severity, const string& message) {
        string severityStr;
        switch (severity) {
            case INFO: severityStr = "INFO"; break;
            case WARNING: severityStr = "WARN"; break;
            case ERROR: severityStr = "ERROR"; break;
        }

        string logEntry = "[" + severityStr + "] " + module + ": " + message;

        if (logs.size() >= maxLogs) {
            logs.erase(logs.begin());
        }

        logs.push_back(logEntry);
    }

public:
    void logInfo(const string& module, const string& message) {
        addLog(module, INFO, message);
    }

    void logWarning(const string& module, const string& message) {
        addLog(module, WARNING, message);
    }

    void logError(const string& module, const string& message) {
        addLog(module, ERROR, message);
    }

    bool getLogs(const string& password, vector<string>& outLogs) {
        if (authAttempts >= maxAuthAttempts) {
            cout << "Account locked. Too many failed attempts.\n";
            return false;
        }

        if (password != adminPassword) {
            authAttempts++;
            cout << "Authentication failed. Attempts remaining: " 
                 << maxAuthAttempts - authAttempts << "\n";
            return false;
        }

        outLogs = logs;
        authAttempts = 0;
        return true;
    }

    int getLogCount() const {
        return logs.size();
    }
};

class NetworkModule {
    Logger& logger;
public:
    NetworkModule(Logger& logService) : logger(logService) {}
    
    void connect() {
        logger.logInfo("Network", "Attempting connection...");
        if (rand() % 5 == 0) {
            logger.logError("Network", "Connection timeout");
        } else {
            logger.logInfo("Network", "Connected successfully");
        }
    }
};

class DatabaseModule {
    Logger& logger;
public:
    DatabaseModule(Logger& logService) : logger(logService) {}
    
    void query(const string& sql) {
        logger.logInfo("Database", "Executing query: " + sql);
        if (sql.find("DROP") != string::npos) {
            logger.logWarning("Database", "Potential dangerous query");
        }
    }
};

int main() {
    Logger systemLogger;
    NetworkModule network(systemLogger);
    DatabaseModule database(systemLogger);

    for (int i = 0; i < 50; i++) {
        network.connect();
        database.query("SELECT * FROM users");
        if (i % 10 == 0) {
            database.query("DROP TABLE temp_" + to_string(i));
        }
    }

    vector<string> logs;
    cout << "Attempting to access logs with wrong password...\n";
    if (!systemLogger.getLogs("wrongpass", logs)) {
        cout << "Access denied.\n";
    }

    cout << "\nAttempting with correct password...\n";
    if (systemLogger.getLogs("secure123", logs)) {
        cout << "Retrieved " << logs.size() << " logs:\n";
        for (const auto& log : logs) {
            cout << log << "\n";
        }
    }

    //test logging limits
    cout << "\nCurrent log count: " << systemLogger.getLogCount() << "\n";
    cout << "Adding logs until limit...\n";
    while (systemLogger.getLogCount() < 1005) {
        systemLogger.logInfo("Test", "Log #" + to_string(systemLogger.getLogCount() + 1));
    }
    cout << "Final count: " << systemLogger.getLogCount() << " (max is 1000)\n";

    return 0;
}
