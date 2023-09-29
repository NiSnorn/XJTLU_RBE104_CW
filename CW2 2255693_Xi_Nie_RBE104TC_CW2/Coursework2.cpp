#include <iostream>
#include "Fraction.h"
#include "Complex.cpp"
#include "Transformer.cpp"

using namespace std;


int main() {
    cout << "==========  Exercise 1  ==========" << endl;

    // Create Fraction objects
    Fraction a;
    Fraction b(2, 5);
    Fraction c(6);

    cout << "-------  Part 1  -------" << endl;

    // Print the Fraction objects
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    cout << "-------  Part 2  -------" << endl;

    // Perform arithmetic operations on the Fraction objects
    cout << a + c << endl;
    cout << b * c << endl;
    cout << b - c << endl;
    cout << b / c << endl;
    cout << (b > c) << endl;
    cout << (b < c) << endl;

    // Convert decimal to fraction
    double decimal = 3.1415926535897932384626433832795028;
    Fraction fraction = decimalToFraction(decimal);
    cout << "Decimal: " << decimal << endl;
    cout << "Fraction: " << fraction << endl;

    // Convert fraction to decimal
    double convertedDecimal = fractionToDecimal(fraction);
    cout << "Converted Decimal: " << convertedDecimal << endl;

    cout << "==========  Exercise 2  ==========" << endl;

    // Create iFraction objects
    iFraction d(68, 4);
    d.MixedFraction();
    iFraction e(578, -7);
    e.MixedFraction();

    // Convert Fraction objects to mixed fractions
    convertF(b);
    convertF(c);

    cout << "==========  Exercise 3  ==========" << endl;

    // Create Fraction objects
    Fraction f1(3, 8);
    Fraction f2(346, 47);
    Fraction f3(35, 8);

    // Create Complex objects
    Complex c1(f1, f2);
    Complex c2(f2, f3);

    // Perform arithmetic operations on Complex objects
    Complex sum = c1 + c2;
    cout << "Sum: " << endl;
    sum.print();

    Complex diff = c1 - c2;
    cout << "Difference: " << endl;
    diff.print();

    Complex product = c1 * c2;
    cout << "Product: " << endl;
    product.print();

    Complex quotient = c1 / c2;
    cout << "Quotient: " << endl;
    quotient.print();

    return 0;
}
