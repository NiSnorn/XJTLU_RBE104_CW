
// Created by Xi on 2023/9/22.

#include "Fraction.h"   // Include the Fraction header file
#include <iostream>
#include <cmath>

using namespace std;

// Function to convert a decimal number to a fraction
Fraction decimalToFraction(double decimal) {
    const int maxIterations = 10;   // Maximum number of iterations for approximation
    double epsilon = 1.0e-6;        // Tolerance for approximation

    int sign = 1;                   // Sign of the decimal number
    if (decimal < 0) {
        sign = -1;
        decimal = -decimal;         // Convert decimal to positive for calculation
    }

    int wholePart = static_cast<int>(decimal);   // Integer part of the decimal number

    double fractionPart = decimal - wholePart;   // Fractional part of the decimal number
    double numerator = fractionPart;              // Numerator of the fraction
    double denominator = 1;                       // Denominator of the fraction

    // Approximate the fraction part using continued fraction expansion
    for (int i = 2; i <= maxIterations && fabs(fractionPart - static_cast<int>(fractionPart)) > epsilon; i++) {
        fractionPart = 1 / (fractionPart - static_cast<int>(fractionPart));   // Calculate the next term of the continued fraction
        int tempNumerator = numerator;

        numerator = fractionPart * numerator + wholePart;   // Update the numerator
        wholePart = tempNumerator;                           // Update the whole part
        denominator = fractionPart * denominator + denominator;   // Update the denominator
    }

    Fraction result(sign * (wholePart * denominator + numerator), denominator);   // Create a Fraction object with the calculated values
    result.simplify();   // Simplify the fraction

    return result;   // Return the resulting fraction
}

// Function to convert a fraction to a decimal number
double fractionToDecimal(const Fraction& fraction) {
    return fraction.toDecimal();   // Call the toDecimal() method of the Fraction class to calculate the decimal value of the fraction
}
