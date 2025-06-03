//
// Created by matteoverz on 6/3/25.
//

#pragma once
#include <ostream>

class Logger {
public:
    static void print_ok(std::ostream& os, const std::string& what);

    static void print_warn(std::ostream& os, const std::string& what, const std::string& warning);

    static void print_error(std::ostream& os, const std::string& what, const std::string& error);
};
