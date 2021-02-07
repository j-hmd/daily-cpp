#include <iostream>
#include "String.h"

int main()
{   
    const EffectiveCpp::String s("Hello world!");
    std::cout << s << std::endl;
    
    // With the safe implementation, we're not able to modify the data
    // because what we're returning is of type const, and the method is const
    // can't *str = "Mello world!";
    const char* str = s;

    std::cout << str << std::endl; 

    return 0;
}