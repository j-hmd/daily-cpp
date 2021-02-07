#pragma once

#include <cstring>

namespace EffectiveCpp
{
    class String
    {
        public:
            String(const char*);
            ~String() { delete [] m_data; }

            operator const char *() const;
        private:
            char* m_data;
    };

    String::String(const char* data)
    {
        // one way to implement this constructor
        if(data)
        {
            m_data = new char[strlen(data) + 1];
            strcpy(m_data, data);
        }
        else
        {
            m_data = new char[1];
            *m_data = '\0';
        }
    }

    /**
     * @note this implementation also has downsides. We need to create the temporary, which will call its
     * destructor and constructor, and the client has to call delete [] on the returned value. A possible memory
     * leak.
     **/ 
    // String::operator const char *()
    // {
    // // a naive implementation that is efficient but flawed is:
    // // return m_data. But this breaks abstraction, clients have access to data.
    // char* temp = new char[strlen(m_data)+1];
    // strcpy(temp, m_data);
    
    // return temp;
    // }

    /**
     * @brief This is the implementation done by the C++ language with the c_str
     * The method can't modify the classe's data, unless they're marked 'mutable'
     * and it returns a const char, which also can't be modified.
     */
    String::operator const char *() const
    {
        return m_data;
    }

} // namespace EffectiveCpp