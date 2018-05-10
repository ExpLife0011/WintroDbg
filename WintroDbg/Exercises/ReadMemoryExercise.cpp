#include <Windows.h>

#include <cstdio>
#include <limits>
#include <stdexcept>

#include "WintroDbg/Exercises/ReadMemoryExercise.h"
#include "WintroDbg/Utils/IOUtils.h"

namespace wintro {
namespace exercises {

static WORD toRead = 0x1337;

void ReadMemoryExercise::display()
{
    printf(R"(Next up: memory manipulation.
First, reading memory.

Here's an Address: %x
Tell me the WORD that's stored there.
So you should get the WORD, resume execution, and type it at the comand line.
That's the 'dw' command for you :)
Of course, this is just one of the many commands for displaying memory contents.
However, I trust in your '.hh' skills enough to not go over them here.
)",
           (uintptr_t)&toRead);
}

bool ReadMemoryExercise::checkInput(uint16_t input)
{
    return input == toRead;
}

uint16_t ReadMemoryExercise::getInput()
{
    auto input = utils::scanHexLongLong();
    if (input > std::numeric_limits<uint16_t>::max()) {
        throw std::out_of_range("I asked for a WORD (== 16 bits)!");
    }

    return static_cast<uint16_t>(input);
}

} // namespace exercises
} // namespace wintro