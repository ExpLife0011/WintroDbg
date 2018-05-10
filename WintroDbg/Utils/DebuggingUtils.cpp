#pragma once
#include <Windows.h>

#include "WintroDbg/Utils/DebuggingUtils.h"

namespace wintro {
namespace utils {

void debugBreak()
{
    DebugBreak();
}

} // namespace utils
} // namespace wintro