#pragma once

namespace wintro {
namespace utils {

void debugBreak();

constexpr char getBreakpointOpcode()
{
    return '\xCC';
}

} // namespace utils
} // namespace wintro