#include <iostream>

#include "Rational.h"
#include "MyString.h"

int main()
{
    Rational::Rational r1(3, 4);
    Rational::Rational r2(1, 2);
    Rational::Rational r3;

    // According to EC++ item 21, if the return of operator* is not const, I could do something like:
    // wow this compiles
    // Now when I add const qualifier to the operator* I get the error: 
    // "error: passing ‘const Rational’ as ‘this’ argument discards qualifiers [-fpermissive]"
    // r1 * r2 = r3;
    r3 = r1 * r2;

    // w/o const I get garbage as the result of the rhs multiplication.
    std::cout << r3.ToStr() << std::endl;

    // The origin of why we have different "constness": bitwise and conceptual.
    const MyString::MyString s("Hello");
    char* constBreach = s;

    // A breach in our const method!
    constBreach[0] = 'Y'; // Dad joke
    std::cout << s << std::endl;

    return 0;
}