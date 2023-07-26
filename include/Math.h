#pragma once

#include <ErrorCode.h>
#include <iterator>

namespace core::math {
template <typename TType> TType add(TType a, TType b) { return a + b; }

expected<float> division(float a, float b);

class ComplexNumber {
  private:
    int64_t real;
    int64_t imaginer;

  public:
    ComplexNumber(int64_t real, int64_t imaginer) : real(real), imaginer(imaginer) {}
    ComplexNumber() {}

    auto getRealNumber() const { return this->real; }
    auto getImaginer() const { return this->imaginer; }

    ComplexNumber operator+(ComplexNumber const &other) {
        return ComplexNumber(this->real + other.real, this->imaginer + other.imaginer);
    }
    ComplexNumber operator-(ComplexNumber const &other) {
        return ComplexNumber(this->real - other.real, this->imaginer - other.imaginer);
    }
    bool operator==(ComplexNumber const &other) const {
        return this->real == other.real and this->imaginer == other.imaginer;
    }
};

} // namespace core::math