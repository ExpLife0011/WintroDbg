#pragma once
#include <tuple>

namespace wintro {
namespace utils {

template <typename Tuple, typename Func>
auto for_each(Tuple&& tup, Func&& f)
{
    std::apply(
        [&](auto&&... elems) {
            int _[] = { (f(elems), 0)... };
            (void)_; // _ is unreferenced;
        },
        tup);
}

} // namespace utils
} // namespace wintro