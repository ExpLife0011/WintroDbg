#include <cstdio>

#include "WintroDbg/Exercises/GoExercise.h"

namespace wintro {
namespace exercises {

void GoExercise::display()
{
    printf(R"(Howdy! Welcome to WintroDbg - your first formal meeting with WinDbg!

Before we start let's clarify some things:
1. To read documentation - use the '.hh <subject>' command in WinDbg.
2. WinDbg's default number representation is in hex.
3. All the numbers in this tutorial are in hex.
4. You can use numbers in different bases like this:
	- hex		- 0xBAADF00D
	- octal		- 0t01234567
	- decimal	- 0n0123456789
	- binary	- 0y1001010110
5. Good Luck!


Here's your first task!
You are currently inside a breakpoint.
'.hh' about the 'g' command, and continue!

)");
}

bool GoExercise::check()
{
    return true;
}

} // namespace exercises
} // namespace wintro