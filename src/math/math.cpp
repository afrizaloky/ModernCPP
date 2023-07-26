#include <Math.h>
#include <boost/outcome.hpp>

namespace core::math {

expected<float> division(float a, float b) {
    if (b == 0)
        return ErrorCode::ZERO_DENOMINATOR;

    return a / b;
}

} // namespace core::math
