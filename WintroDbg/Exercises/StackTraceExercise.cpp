#include <cstdio>
#include <intrin.h>

#include "WintroDbg/Exercises/StackTraceExercise.h"
#include "WintroDbg/Utils/IOUtils.h"

#pragma intrinsic(_ReturnAddress)

namespace wintro {
namespace exercises {

void StackTraceExercise::display()
{
    printf(R"(Mighty fine work! You now know how to display the opcodes you're debugging.
But displaying opcodes is only doing half the job.

When your code crashes on you, it's not enough to look at where you are right now -
 you should also figure out where you came from. That, my friends, is stack analysis.
"Stack analysis" is my fancy way of saying you should look at the call stack
and figure out the chain of calls that led you to this place.

Let's do some of that now.
Begin by telling me the return address of this very function.
That's the 'k' command and its variations for you.
)");
}

bool StackTraceExercise::checkInput(uint64_t input)
{
    return input == (uint64_t)_ReturnAddress();
}

uint64_t StackTraceExercise::getInput()
{
    return utils::scanHexLongLong();
}

} // namespace exercises
} // namespace wintro