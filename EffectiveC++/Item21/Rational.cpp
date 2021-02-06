#include "Rational.h"
#include <string>

namespace Rational
{
    bool Rational::operator==(const Rational& lhs)
    {
        if(this == &lhs)
        {
            return true;
        }

        return false;
    }

    Rational& Rational::operator=(const Rational& lhs)
    {
        // Avoid self assignment
        if(*this == lhs)
        {
            return *this;
        }

        this->num = lhs.num;
        this->den = lhs.den;

        return *this;

    }

    const Rational Rational::operator*(const Rational& lhs)
    {
        Rational prod = Rational(this->num * lhs.num, this->den * lhs.den);
        return prod;
    }

    std::string Rational::ToStr()
    {
        std::string out = std::to_string(this->num) + '/' + std::to_string(this->den); 
        return out;
    }
}