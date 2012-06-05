#ifndef CALCULEXCEPTION_H
#define CALCULEXCEPTION_H

#include <string>

class CalculException {
    std::string info;
    public:
        CalculException(const string s) : info(s) {}
        const string getInfo() const
        {
            return info;
        }
};

#endif // CALCULEXCEPTION_H
