#include <Windows.h>

#include <cstdio>
#include <iostream>
#include <limits>
#include <stdexcept>

#include "WintroDbg/Exercises/DisassemblyExercise.h"
#include "WintroDbg/Utils/IOUtils.h"

namespace wintro {
namespace exercises {

#pragma optimize("", off)
static void toDis(int x)
{
    x ^= 7;
    printf("Cool, I know how to dissassemble!");
}
#pragma optimize("", on)

void DisassemblyExercise::display()
{
    printf(R"(We're warming up.

Debugging is not worth anything if you can't view the code you're debugging.
Read about the 'u' command.

Disassemble the function at address: %x
Tell me the the name of the 1st instruction.
)",
           (uintptr_t)&toDis);
}

bool DisassemblyExercise::checkInput(const std::string& input)
{
    return input.find("push") != std::string::npos;
}

std::string DisassemblyExercise::getInput()
{
    printf("> ");

    std::string input;
    std::cin >> input;
    return input;
}

} // namespace exercises
} // namespace wintro