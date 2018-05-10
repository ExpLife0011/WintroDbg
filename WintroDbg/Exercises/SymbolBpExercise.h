#pragma once

namespace wintro {
namespace exercises {

struct SymbolBpExercise {
    void display();
    bool check();

    static constexpr auto name = "Symbols Make Us Stop";
    static const bool resetScreen = false;
};

} // namespace exercises
} // namespace wintro