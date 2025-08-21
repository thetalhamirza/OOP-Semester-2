#include <iostream>
#include <vector>
using namespace std;


class Logger {
    private:
    vector<string> logs;
    const int maxLogs = 1000;

    void storeLog(const string& severity, const string& message) {
        string logEntry = severity + ": " + message;

        if (logs.size() >= maxLogs) {
            logs.erase(logs.begin());
        }
        logs.push_back(logEntry);
    }
    public:
    void logInfo(const string& message) {
        storeLog("INFO", message);
    }
    void logWarning(const string& message) {
        storeLog("WARNING", message);
    }
    void logError(const string& message) {
        storeLog("ERROR", message);
    }


    class Auditor {
        private:
        bool auth;
    
        public:
        Auditor() : auth(false) {}
        void authenticate() {auth = true;}
        void deauthenticate() {auth = false;}
        bool isAuthenticated() {
            if (auth) {
                return 1;
            } else {return 0;}
        }
    };

    vector<string> getLogs(Auditor& auditor) const {
        if (!auditor.isAuthenticated()) {
            cout << "Unauthorized" << endl;
            return {};
        }
        return logs;
    }
};


int main() {
    Logger logger;

    logger.logInfo("Device started");
    logger.logInfo("Service initiated");
    logger.logWarning("Low disk space");
    logger.logError("Connection aborted");
    logger.logError("Shutting down");

    Logger::Auditor auditor;

    vector<string> logs = logger.getLogs(auditor);      // unauth

    auditor.authenticate();     // authed
    logs = logger.getLogs(auditor);

    cout << "Audit logs: " << endl;
    for (const string& log: logs) {
        cout << log << endl;
    }
}