#include <Math.h>
#include <gtest/gtest.h>

using namespace core;
TEST(MathDivision, DenumZero) {
    auto expectDiv = math::division(1, 0);
    ASSERT_FALSE(expectDiv);

    ASSERT_EQ(expectDiv.error().value(), fmt::underlying(ErrorCode::ZERO_DENOMINATOR))
        << "Status: " << expectDiv.error().value();
}

TEST(MathDivision, PositiveCase) {
    auto expectDiv = math::division(1, 1);
    ASSERT_TRUE(expectDiv);
    ASSERT_EQ(1, expectDiv.value());
}

TEST(MathAddition, PositiveCase) {
    ASSERT_EQ(math::add<int>(10, 5), 15);
    ASSERT_EQ(math::add<float>(10, 5), 15);
}

TEST(MathComplexNumber, Addition) {
    math::ComplexNumber a{1, 2};
    math::ComplexNumber b{2, 3};

    auto c = a + b;
    ASSERT_EQ(c, math::ComplexNumber(3, 5));
}

TEST(MathComplexNumber, Substraction) {
    math::ComplexNumber a{1, 2};
    math::ComplexNumber b{2, 3};

    auto c = a - b;
    ASSERT_EQ(c, math::ComplexNumber(-1, -1));
}