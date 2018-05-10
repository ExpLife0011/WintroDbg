#pragma once
#include <cstdint>
#include <string>

namespace wintro {
namespace exercises {

struct DisassemblyExercise {
    void display();
    bool checkInput(const std::string& input);
    std::string getInput();

    static constexpr auto name = "Learning To Read";
};

} // namespace exercises
} // namespace wintro