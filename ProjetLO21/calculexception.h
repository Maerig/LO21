#ifndef CALCULEXCEPTION_H
#define CALCULEXCEPTION_H

#include <exception>
#include <string>

class CalculException {
private :
    std::string info;

public:
    CalculException(const std::string str) : info("Erreur : " + str) {}
    const std::string getInfo() const { return info; }
};

#endif // CALCULEXCEPTION_H
