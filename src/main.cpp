#include <fmt/core.h>

#include <ErrorCode.h>
#include <Math.h>

using namespace core;

int main() {
    auto a = math::division(3, 0);
    if (!a)
        fmt::print("status: {}\r\nmessage:{}\r\n", a.error().value(), getErrorStr(a.error()));
    if (!a)
        return 0;

    fmt::print("The value is: {}\r\n", a.value());
    return 0;
}