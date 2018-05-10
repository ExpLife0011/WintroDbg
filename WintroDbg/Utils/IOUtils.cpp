#pragma once

#include <conio.h>
#include <cstdio>
#include <stdexcept>

#include "WintroDbg/Utils/IOUtils.h"

namespace wintro {
namespace utils {

uint32_t scanHexInt()
{
    printf("> ");

    uint32_t hex = 0;
    if (scanf("%x", &hex) == 1) {
    } else if (scanf("%X", &hex) == 1) {
    } else if (scanf("0x%x", &hex) == 1) {
    } else if (scanf("0X%X", &hex) == 1) {
    } else if (scanf("0X%x", &hex) == 1) {
    } else if (scanf("0x%X", &hex) == 1) {
    } else {
        throw std::domain_error("Please enter a hexadecimal number!");
    }

    return hex;
}

uint64_t scanHexLongLong()
{
    printf("> ");

    uint64_t hex = 0;
    if (scanf("%llx", &hex) == 1) {
    } else if (scanf("%llX", &hex) == 1) {
    } else if (scanf("0x%llx", &hex) == 1) {
    } else if (scanf("0X%llX", &hex) == 1) {
    } else if (scanf("0X%llx", &hex) == 1) {
    } else if (scanf("0x%llX", &hex) == 1) {
    } else {
        throw std::domain_error("Please enter a hexadecimal number!");
    }

    return hex;
}

void flush()
{
    int ch;
    if (_kbhit()) {
        while ((ch = getchar()) != EOF && ch != '\n')
            ;
    }
}

} // namespace utils
} // namespace wintro