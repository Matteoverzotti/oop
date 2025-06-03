//
// Created by matteoverz on 6/3/25.
//

#pragma once
#include <string>
#include <iostream>

#include "logger.h"

class BaseTest {
    static Logger &logger() { return Logger::instance(); }
protected:
    static void base(const std::string &name, auto &&test) {
        bool ok = true;
        try {
            test();
        } catch (std::exception &e) {
            ok = false;
            logger().print_error(std::cerr, name, e.what());
        }
        if (ok) {
            logger().print_ok(std::cerr, name);
        }
    }
};
