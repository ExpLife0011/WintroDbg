#pragma once

#include <conio.h>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>

#include "WintroDbg/Utils/IOUtils.h"

namespace wintro {
namespace utils {

uint64_t scanHexLongLong()
{
    printf("> ");

    std::string input;
    std::cin >> input;

    for (char c : input) {
        if (!isxdigit(c)) {
            throw std::domain_error("Please enter a hexadecimal number!");
        }
    }

    uint64_t hex = 0;
    if (sscanf(input.c_str(), "%llx", &hex) == 1) {
    } else if (sscanf(input.c_str(), "%llX", &hex) == 1) {
    } else if (sscanf(input.c_str(), "0x%llx", &hex) == 1) {
    } else if (sscanf(input.c_str(), "0X%llX", &hex) == 1) {
    } else if (sscanf(input.c_str(), "0X%llx", &hex) == 1) {
    } else if (sscanf(input.c_str(), "0x%llX", &hex) == 1) {
    } else {
        throw std::domain_error("Please enter a hexadecimal number!");
    }

    return hex;
}

void flush()
{
    if (_kbhit()) {
        int c;
        while ((c = getchar()) != EOF && c != '\n') {
        }
    }
}

} // namespace utils
} // namespace wintro