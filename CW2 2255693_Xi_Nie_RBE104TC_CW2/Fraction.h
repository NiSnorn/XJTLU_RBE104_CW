#ifndef FRACTION_H
#define  FRACTION_H

#include<iostream>
using namespace std;


class Fraction {
private:
    int top;
    int bottom;



public:
    //constructor
    Fraction();
    Fraction(int num);
    Fraction(int num, int denom);
    
    /*Overloading of binomial arithmetic operators
        Add and subtract the fractions by cross-multiplying.
        Divide and multiply the numerators and denominators.
    */
    Fraction operator+(const Fraction& other) const {
        int num = (top * other.bottom) + (other.top * bottom);
        int denom = bottom * other.bottom;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = (top * other.bottom) - (other.top * bottom);
        int denom = bottom * other.bottom;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = top * other.top;
        int denom = bottom * other.bottom;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {
        int num = top * other.bottom;
        int denom = bottom * other.top;
        return Fraction(num, denom);
    }
    

    // Overloading of Relational Operators by cross-multiplying
    bool operator==(const Fraction& other) const {
        return (top * other.bottom) == (other.top * bottom);
    }
    
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }
    
    bool operator<(const Fraction& other) const {
        return (top * other.bottom) < (other.top * bottom);
    }
    
    bool operator>(const Fraction& other) const {
        return (top * other.bottom) > (other.top * bottom);
    }
    
    bool operator<=(const Fraction& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>=(const Fraction& other) const {
        return (*this > other) || (*this == other);
    }
    
    /*
     Overloaded << and >> operators in Fraction class for buddy functions.
     Fraction objects are output and input by them.
     */
    friend ostream& operator<<(ostream& os, const Fraction& fraction) {
        if (fraction.top*fraction.bottom<0)
        {
            os << - abs(fraction.top) << "/" << abs(fraction.bottom);
        }else{
            os << abs(fraction.top) << "/" << abs(fraction.bottom);
        }
        
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& fraction) {
        char slash;
        is >> fraction.top >> slash >> fraction.bottom;
        return is;
    }

    //Declare a friend function
    friend void convertF(Fraction& fraction);

    double toDecimal() const {
        return static_cast<double>(top) / bottom;
    }

    // Accessor method to get the private top and bottom value.
    int getPrivateTop() const {
        return top;
    }
    int getPrivateBottom() const {
        return bottom;
    }

    // Print the fraction in the form of "top/bottom"
    void print() const {
        cout << top << "/" << bottom << endl;
    };



    /*Calculate GCD using recursion.
        The function takes two fraction numerator and denominator parameters.
        The code yields a when b = 0.
        The recursive function calls itself with b as the numerator and the residue of a divided by b as the denominator.
        Repeat until base case is reached and GCD is returned.
    */
    int findGCD(int a, int b) {
        // Base case: if b is 0, return a
        if (b == 0)
            return a;
        // Recursive case: compute the GCD using modulo operator
        return findGCD(b, a % b);
    }
    // Find the greatest common divisor using recursion
    void simplify() {
        int gcd = findGCD(top, bottom);
        top /= gcd;
        bottom /= gcd;
    }
};

/*Depending on the number of input data, the corresponding constructor is initialised.
    Default constructor: initialize top to 0 and bottom to 1.
    Constructor with one argument: initialize top to num and bottom to 1.
    Constructor with two arguments: initialize top to num and bottom to denom.
*/
Fraction::Fraction() {
    top = 0;
    bottom = 1;
}
Fraction::Fraction(int num) {
    top = num;
    bottom = 1;
}
Fraction::Fraction(int num, int denom) {
    top = num;
    bottom = denom;
    simplify(); 
}

// Convert the fraction to a mixed fraction
void convertF(Fraction& fraction) {
    int fWhole = fraction.top / fraction.bottom;
    int fRemainder = fraction.top % fraction.bottom;

    cout << "Mixed Fraction: " << fWhole << " " << fRemainder << "/" << fraction.bottom << endl;
}

//Define a derived class based on Fraction()
class iFraction :public Fraction{
public:
    //Constructor for iFraction
    iFraction(int sTop, int sBottom) : Fraction(sTop, sBottom) {}
    int sTop = getPrivateTop();
    int sBottom = getPrivateBottom();

    // Convert the fraction to a mixed fraction
    void MixedFraction (){
        int numerator,integer;
        if (sTop * sBottom<0)
        {
            integer = - abs(sTop) / abs(sBottom);
            numerator = abs(sTop) % abs(sBottom);
        }else{
            integer = sTop / sBottom;
            numerator = sTop % sBottom;
        }

        cout << "Mixed Fraction: " << integer << " " << numerator << "/" << abs(sBottom) << endl;
        
    };

    friend void convertF(iFraction& fraction);
};

void convertF(iFraction& fraction) {
    // Convert the fraction to a mixed fraction
    int sWhole = fraction.sTop / fraction.sBottom;
    int sRemainder = fraction.sTop % fraction.sBottom;

    cout << "Mixed Fraction: " << sWhole << " " << sRemainder << "/" << fraction.sBottom << endl;
}



#endif