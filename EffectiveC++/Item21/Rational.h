#pragma once

#include <string>

namespace Rational
{
    class Rational
    {
        public:
            Rational(){}
            Rational(const int n, const int d) : num(n), den(d){}
            ~Rational(){}
        
            bool operator==(const Rational& lhs);
            Rational& operator=(const Rational& lhs);
            const Rational operator*(const Rational& lhs);
            
            std::string ToStr();

        private:
            int num;
            int den;
    };
}
