#pragma once
#include <cstdint>

namespace wintro {
namespace exercises {

struct ReadMemoryExercise {
    void display();
    bool checkInput(uint16_t input);
    uint16_t getInput();

    static constexpr auto name = "Learning To Read";
};

} // namespace exercises
} // namespace wintro