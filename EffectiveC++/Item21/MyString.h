#pragma once

namespace MyString
{
    class MyString
    {
        public:
            MyString(const char* data);
            ~MyString(){ delete [] m_data; }

            operator char *() const;

        private:
            char* m_data;
    };
} // namespace Mystring