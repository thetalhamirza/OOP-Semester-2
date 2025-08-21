#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>      // For rename()
#include <sys/stat.h>  // For stat()
#include <string>

class Logger {
private:
    std::string baseName = "log";
    std::string extension = ".txt";
    std::string currentFile = "log.txt";
    std::size_t maxSize = 1 * 1024 * 1024; // 1 MB

    std::size_t getFileSize(const std::string& filename) {
        struct stat stat_buf;
        if (stat(filename.c_str(), &stat_buf) == 0)
            return stat_buf.st_size;
        return 0;
    }

    void rotateLogs() {
        int index = 1;
        std::ostringstream oss;
        while (true) {
            oss.str(""); // clear contents
            oss << baseName << index << extension;
            std::ifstream f(oss.str());
            if (!f.good()) break;
            index++;
        }

        for (int i = index - 1; i >= 1; --i) {
            std::string oldName = baseName + std::to_string(i) + extension;
            std::string newName = baseName + std::to_string(i + 1) + extension;
            std::rename(oldName.c_str(), newName.c_str());
        }

        std::rename(currentFile.c_str(), (baseName + "1" + extension).c_str());
    }

public:
    void log(const std::string& message) {
        if (getFileSize(currentFile) >= maxSize) {
            rotateLogs();
        }

        std::ofstream out(currentFile, std::ios::app);
        if (!out) {
            std::cerr << "Error opening log file.\n";
            return;
        }
        out << message << std::endl;
        out.close();
    }
};

int main() {
    Logger logger;
    for (int i = 1; i <= 200000; ++i) {
        logger.log("Log message number: " + std::to_string(i));
    }
    std::cout << "Logging complete.\n";
    return 0;
}
