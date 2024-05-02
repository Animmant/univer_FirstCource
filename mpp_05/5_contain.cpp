#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Database {
protected:
    std::string name;
    std::vector<std::string> records;

public:
    Database(const std::string& dbName) : name(dbName) {}

    void addRecord(const std::string& record) {
        records.push_back(record);
    }

    void removeRecord(const std::string& record) {
        auto it = std::find(records.begin(), records.end(), record);
        if (it != records.end()) {
            records.erase(it);
        } else {
            std::cout << "Record '" << record << "' not found." << std::endl;
        }
    }

    void showRecords() const {
        std::cout << "Database: " << name << std::endl;
        for (const auto& record : records) {
            std::cout << record << std::endl;
        }
    }
};
