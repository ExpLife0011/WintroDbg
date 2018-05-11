#pragma once
#include <cstdint>
#include <string>

namespace wintro {
namespace exercises {

struct StackTraceExercise {
    void display();
    bool checkInput(uint64_t input);
    uint64_t getInput();

    static constexpr auto name = "Looking For Traces";
};

} // namespace exercises
} // namespace wintro