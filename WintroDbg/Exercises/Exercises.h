#pragma once
#include <tuple>
#include <type_traits>

#include "WintroDbg/Exercises/DisassemblyExercise.h"
#include "WintroDbg/Exercises/FinishExercise.h"
#include "WintroDbg/Exercises/GoExercise.h"
#include "WintroDbg/Exercises/ReadMemoryExercise.h"
#include "WintroDbg/Exercises/SimpleBpExercise.h"
#include "WintroDbg/Exercises/SymbolBpExercise.h"
#include "WintroDbg/Exercises/WriteMemoryExercise.h"

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
    return std::make_tuple( //GoExercise{}, SimpleBpExercise{}, SymbolBpExercise{},
        //ReadMemoryExercise{}, WriteMemoryExercise{},
        DisassemblyExercise{},
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

void displayFailureMessage()
{
    const char* messages[] = { "Let's try that again, shall we?",
                               "Too bad, try again :(",
                               "\"If at first you don't succeed, get a bigger hammer.\" - Alan Lewis",
                               "Looks like you should debug it.",
                               "You're almost there, buddy. One last push.",
                               "If \"Plan A\" doesn't work, the alphabet has 25 more letters! Stay cool." };

    static size_t currentIndex = 0;
    printf("%s\n", messages[currentIndex]);

    if (currentIndex + 1 > std::size(messages)) {
        currentIndex = 0;
    } else {
        currentIndex++;
    }
}

} // namespace exercises
} // namespace wintro