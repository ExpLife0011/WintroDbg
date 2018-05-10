#pragma once
#include <cstdint>

namespace wintro {
namespace exercises {

struct WriteMemoryExercise {
    void display();
    bool check();

    static constexpr auto name = "Writers Are Insane";
};

} // namespace exercises
} // namespace wintro