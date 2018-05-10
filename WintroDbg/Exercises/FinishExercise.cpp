#include <cstdio>

#include "WintroDbg/Exercises/FinishExercise.h"

namespace wintro {
namespace exercises {

void FinishExercise::display()
{
    printf(R"(That's it. THis journey is over, and another shall soon begin.
Truly, you know no fear, for you have mastered this course.
Onwards, then, to exterminate the bugs that plauge our code!
Onwards, to bigger things.
Hit 'g' to exit.
)");
}

bool FinishExercise::check()
{
    return true;
}

} // namespace exercises
} // namespace wintro