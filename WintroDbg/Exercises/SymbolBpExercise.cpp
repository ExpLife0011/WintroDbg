#include <Windows.h>

#include <cstdio>

#include "WintroDbg/Exercises/SymbolBpExercise.h"
#include "WintroDbg/Utils/DebuggingUtils.h"

namespace wintro {
namespace exercises {

void SymbolBpExercise::display()
{
    printf(R"(Alrighty them, let's do something else.
Same thing as above, but now with a symbolic name: kernel32!LoadLibraryW
)");
}

bool SymbolBpExercise::check()
{
    auto loadLibraryAddress = GetProcAddress(GetModuleHandleW(L"kernel32"), "LoadLibraryW");

    char opcodeAtFunc = *(char*)loadLibraryAddress;
    return opcodeAtFunc == utils::getBreakpointOpcode();
}

} // namespace exercises
} // namespace wintro