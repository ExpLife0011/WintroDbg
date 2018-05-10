#pragma once
#include <tuple>
#include <type_traits>

#include "WintroDbg/Exercises/FinishExercise.h"
#include "WintroDbg/Exercises/GoExercise.h"
#include "WintroDbg/Exercises/ReadMemoryExercise.h"
#include "WintroDbg/Exercises/SimpleBpExercise.h"
#include "WintroDbg/Exercises/SymbolBpExercise.h"

namespace wintro {
namespace exercises {

template <typename T, typename = void>
constexpr bool is_input_exercise = false;

template <typename T>
constexpr bool is_input_exercise<T, std::void_t<decltype(std::declval<T>().getInput())>> = true;

template <typename T, typename = void>
constexpr bool should_reset_screen = true;

template <typename T>
constexpr bool should_reset_screen<T, std::void_t<decltype(T::resetScreen)>> = T::resetScreen;

auto getExercises()
{
    return std::make_tuple(GoExercise{}, SimpleBpExercise{}, SymbolBpExercise{},
                           ReadMemoryExercise{},
                           FinishExercise{});
}

template <typename Exercise>
void displayExercise(Exercise ex)
{
    if constexpr (should_reset_screen<Exercise>) {
        system("cls");

        printf("Exercise: %s\n", Exercise::name);
        printf("===============\n\n");
    }

    ex.display();
}

} // namespace exercises
} // namespace wintro