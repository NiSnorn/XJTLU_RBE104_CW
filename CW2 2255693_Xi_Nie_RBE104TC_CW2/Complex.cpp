#include <iostream>
#include "Fraction.h"


class Complex {
private:
    Fraction realPart;
    Fraction imaginaryPart;

public:
    Complex(Fraction real, Fraction imaginary) {
        realPart = real;
        imaginaryPart = imaginary;
    }
    /*Overloading of binomial arithmetic operators
        Addition and subtraction add or remove real and imaginary elements.
        Complex multiplication and division formulae are used.
    */
    Complex operator+(const Complex& other) const {
        return Complex(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
    }

    Complex operator-(const Complex& other) const {
        return Complex(realPart - other.realPart, imaginaryPart - other.imaginaryPart);
    }

    Complex operator*(const Complex& other) const {
        Fraction real = realPart * other.realPart - imaginaryPart * other.imaginaryPart;
        Fraction imaginary = realPart * other.imaginaryPart + imaginaryPart * other.realPart;
        return Complex(real, imaginary);
    }

    Complex operator/(const Complex& other) const {
        Fraction divisor = other.realPart * other.realPart + other.imaginaryPart * other.imaginaryPart;
        Fraction real = (realPart * other.realPart + imaginaryPart * other.imaginaryPart) / divisor;
        Fraction imaginary = (imaginaryPart * other.realPart - realPart * other.imaginaryPart) / divisor;
        return Complex(real, imaginary);
    }
    /* 
       Prints the real and imaginary parts of the complex number
    */
    void print() const {
        cout << "Real Part: ";
        realPart.print();
        cout << "Imaginary Part: ";
        imaginaryPart.print();
    }
};