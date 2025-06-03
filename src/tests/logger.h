//
// Created by matteoverz on 6/3/25.
//

#pragma once
#include <ostream>

class Logger {
    Logger() = default;
    ~Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
public:
    static Logger& instance() {
        static Logger instance;
        return instance;
    }

    void print_ok(std::ostream& os, const std::string& what);
    void print_warn(std::ostream& os, const std::string& what, const std::string& warning);
    void print_error(std::ostream& os, const std::string& what, const std::string& error);
};