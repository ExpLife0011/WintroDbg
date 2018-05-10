#include <cstdio>

#include "WintroDbg/Exercises/SimpleBpExercise.h"
#include "WintroDbg/Utils/DebuggingUtils.h"

namespace wintro {
namespace exercises {

static void putBreakPointHere()
{
}

void SimpleBpExercise::display()
{
    printf(R"(Good job there!
I know you're eager to get some action, but first you need to master some basics.

The most important thing you can do in a debugger is set breakpoints.
Let's do that now.
Here's an address: %x
Read about the 'bp' command, then set a breakpoint there and hit go.

)",
           (uintptr_t)&putBreakPointHere);
}

bool SimpleBpExercise::check()
{
    char opcodeAtFunc = *(char*)putBreakPointHere;
    return opcodeAtFunc == utils::getBreakpointOpcode();
}

} // namespace exercises
} // namespace wintro