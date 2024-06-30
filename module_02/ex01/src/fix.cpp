#include <iostream>
#include <bitset>
#include <cmath>

const int SIGN_BIT = 1;
const int EXPONENT_BITS = 8;
const int MANTISSA_BITS = 23;

int getSign(float f) {
    unsigned int* p = reinterpret_cast<unsigned int*>(&f);
    return (*p >> 31) & ((1 << SIGN_BIT) - 1);
}

int getExponent(float f) {
    unsigned int* p = reinterpret_cast<unsigned int*>(&f);
    return (*p >> (MANTISSA_BITS)) & ((1 << EXPONENT_BITS) - 1);
}

unsigned int getMantissa(float f) {
    unsigned int* p = reinterpret_cast<unsigned int*>(&f);
    return *p & ((1 << MANTISSA_BITS) - 1);
}

float calculateFloatValue(int sign, int exponent, unsigned int mantissa) {
    // Adjusting the exponent for bias
    exponent -= 127;

    // Constructing the normalized mantissa with the implied leading 1
    double normalizedMantissa = 1 + static_cast<double>(mantissa) / pow(2, MANTISSA_BITS);

    // Calculating the final value
    return static_cast<float>(pow(-1, sign) * normalizedMantissa * pow(2, exponent));
}

int main() {
    float f = 25.34567f;

    int sign = getSign(f);
    int exponent = getExponent(f);
    unsigned int mantissa = getMantissa(f);

    std::cout << "Original Float: " << f << std::endl;
    std::cout << "Sign Bit: " << sign << std::endl;
    std::cout << "Exponent Bits: " << exponent << std::endl;
    std::cout << "Mantissa Bits: " << std::bitset<MANTISSA_BITS>(mantissa) << std::endl;

    float decodedValue = calculateFloatValue(sign, exponent, mantissa);
    std::cout << "Decoded Float: " << decodedValue << std::endl;

    return 0;
}

