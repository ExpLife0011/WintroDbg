#include <Windows.h>

#include <cstdio>
#include <limits>
#include <stdexcept>

#include "WintroDbg/Exercises/WriteMemoryExercise.h"
#include "WintroDbg/Utils/IOUtils.h"

namespace wintro {
namespace exercises {

static DWORD writeHere = 0xFFFF;

void WriteMemoryExercise::display()
{
    printf(R"(So you think you can read, eh?
Let's see how well you can write!
Alright then. Here's an Address: %x
Write the DWORD 0xB there.
That's the 'ed' command for you :)
)",
           (uintptr_t)&writeHere);
}

bool WriteMemoryExercise::check()
{
    return writeHere == 0xB;
}

} // namespace exercises
} // namespace wintro