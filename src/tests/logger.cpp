//
// Created by matteoverz on 6/3/25.
//

#include "logger.h"
#include "../../include/constants.h"

void Logger::log(std::ostream &os, const std::string &what, const std::string &color = LoggerColors::RESET) {
    os << color << "[LOG] " << what << std::endl;
}

void Logger::print_ok(std::ostream &os, const std::string &what) {
    os << LoggerColors::GREEN << "[+] Ok! " << what << " work(s)" << LoggerColors::RESET << std::endl;
}

void Logger::print_warn(std::ostream &os, const std::string &what, const std::string &warning) {
    os << LoggerColors::YELLOW << "[?] " << what << " warning: " << warning << LoggerColors::RESET << std::endl;
}

void Logger::print_error(std::ostream &os, const std::string &what, const std::string &error) {
    os << LoggerColors::RED << "[!] " << what << " error: " << error << LoggerColors::RESET << std::endl;
}
