#include "MyString.h"
#include <cstring>

namespace MyString
{
    MyString::MyString(const char* data)
    {
        if(data)
        {
            m_data = new char[strlen(data) + 1]; // Include null terminator
            strcpy(m_data, data);
        }
        else
        {
            m_data = new char[1];
            *m_data = '\0';
        }
    };

    // In this case, the const method is not allowed to modify the attributes of the class
    // Howevert, it is allowed to pass a pointer to its data, even thought the method is const!
    // This is the "wiggle room" that allows for different definitions of "constness": bitwise, and conceptual
    MyString::operator char *() const
    {
        return m_data;
    };
} // namespace Mystring