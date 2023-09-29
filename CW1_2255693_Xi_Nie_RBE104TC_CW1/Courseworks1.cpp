/*
Name: RBE104_Courseworks1 
File Name: Courseworks1.cpp
Author: Xi Nie
Description: 
    Exercise 1: Looping structures, two judgement structures, logical operators, forced type conversions, io streams, and basic operators solve most problems.
    Exercise 2: In Part1:Two loop structures, two judgement structures, and a const_free representation complete function internals.
                In Part2:Prompts the user for a string and calls the findC function.
*/
#include <iostream>/* include standard library iostream for use of cin, cout, getline, endl, oct, hex */
#include <cmath>/* include standard library cmath for use of sqrt() */
#include <iomanip>
using namespace std;/*Using the std namespace eliminates the need for the full namespace qualifier.*/

/*Exercise 2 Part1:
    Define a function.
    Use if loops to initialis pointers.
    Nested while loops and if judgements using while loops with arithmetic operations on pointers to change pointers.
    Use const_cast<>() to eliminate const effects.
*/
char *findC (char const *source, char const *obj){
    if (source == nullptr || obj == nullptr) {
        return nullptr;
    }
    
    while (*source != '\0') {
        char const * s = source;
        char const * o = obj;
        
        while (*s == *o && *o != '\0') {
            s++;
            o++;
        }
        
        if (*o == '\0') {
            return const_cast<char*>(source);
        }
        
        source++;
    }
    
    return const_cast<char*>(source);
}


int main() {
//_______________________________________________Declare variable
    string name;
    long long phoneNumber,interimRepositoryPhoneNumber,fiveDigit,sixDigit;
    int decimalNumber,interimRepositoryDecimalNumber;
    float temperature;
    double a,b,c,dscrmt;

//______________________________________________Solution______________________________________________

//Exercise 1:Q1

cout<<"===============================  Exercise 1  ==============================="<<"\n"<<endl;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your telephone number (11 digits): ";
    cin >> interimRepositoryPhoneNumber;

    /*
    Use the do while structure to nest the if structure to complete the judgement on the number of digits.
    Use logical operators ||(or) juxtaposing conditions.
    Assign the correct result to the appropriate variable.
    */
    do{
        if (interimRepositoryPhoneNumber < 10000000000 || interimRepositoryPhoneNumber > 99999999999)
        {
            cout<<"Formatting error. Please re-enter:"<< endl;
            cin >> interimRepositoryPhoneNumber;
        }       
    } while (interimRepositoryPhoneNumber<10000000000 || interimRepositoryPhoneNumber>99999999999);
        phoneNumber = interimRepositoryPhoneNumber;

    cout << "Enter a 2-digit decimal number: ";
    cin >> interimRepositoryDecimalNumber;
    do{
        if (interimRepositoryDecimalNumber<10 || interimRepositoryDecimalNumber>99)
        {
            cout<<"Formatting error. Please re-enter:"<< endl;
            cin >> interimRepositoryDecimalNumber;
        }  
    } while (interimRepositoryDecimalNumber<10 || interimRepositoryDecimalNumber>99);
        decimalNumber = interimRepositoryDecimalNumber;

    cout << "Enter temperature in degrees Celsius: ";
    cin >> temperature;


    cout<<"-----------------------  Exercise 1:Q2 Q3 Q4 output  -----------------------"<<"\n"<<endl;


/*Exercise 1:Q2
    Use divide 100000 to get each part of the number;
    Use forced type conversion to convert the long integer sixDigit to an SFP type, which can get an accurate solution.
*/
    sixDigit = phoneNumber / 100000;
    fiveDigit = phoneNumber % 100000;
    float divisionResult = static_cast<float>(sixDigit) / fiveDigit;
    cout << "Division Result: " << sixDigit << "/" << fiveDigit << " = " << divisionResult <<"\n"<< endl;


/*Exercise 1:Q3
    Use oct and hex.
*/
    cout << "Decimal: " << decimalNumber << endl;
    cout << "Octal: " << oct << decimalNumber << endl;
    cout << "Hexadecimal: " << hex << decimalNumber <<"\n"<< endl;


/*Exercise 1:Q4
    Compute the temperature into degrees Fahrenheit and Kelvin according to the formula.
    The "fixed" function ensures that floating-point numbers have a set number of decimal places. 
    The "setprecision(0)" function generates integer-trimmed floating-point numbers. 
    The "round()" method rounds floating-point integers to two decimal places.
*/
    cout<<temperature<<" °C -> "<< fixed << setprecision(0)<<round((temperature*9/5+32)*100)/100<<"°F,"<<round((temperature+273.15)*100)/100<<"°K"<<"\n"<<endl;


/*Exercise 1:Q5
    Use else if structure to discuss the different situations.
    Get the answers by the math calculation.
*/ 

    cout<<"-----------------------------  Exercise 1:Q5  -----------------------------"<<"\n"<<endl;

    cout<<"Type three numbers to be the a,b,c in the quadratic equation(e.g.12 13 14)"<<endl;
    cin >>a>>b>>c;/*Assign the input values to the three variables a,b,c respectively.*/
    dscrmt = b*b-(4*a*c);/*Calculate the discriminant of equation*/
    if(a==0){
        cout<<"The answer is "<<-c/b<<"\n"<<endl;
    }else if ( dscrmt < 0){
        cout<<"There is no real root of this function. "<<"\n"<<endl;
    }else if(dscrmt==0){
        cout<<"There is only one real root of this function. The answer is"<<-b/(2*a)<<"\n"<<endl;
    }else{
        cout<<"There are two real roots of this function. The answer are"<<(-b+sqrt(dscrmt))/(2*a)<<"and"<< (-b-sqrt(dscrmt))/(2*a)<<"\n"<<endl;
    }

cout<<"===============================  Exercise 2  ==============================="<<"\n"<<endl;

/*Exercise 2 Part 2
    Use a variable to consume the return value
*/
    string source0, target;
    cout<<"Please provide a source for research: ";
    cin.ignore();
    getline(cin, source0);
    cout<<"Please provide a target to research: ";
    getline(cin, target);
    char* result = findC(source0.c_str(), target.c_str());
    cout << "Return the pointer point to the:" << *result << endl;
    return 0;
}