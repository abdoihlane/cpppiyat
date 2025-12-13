#include <iostream>
#include <string>

int main()
{
    std::string  ss = "HI THI IS BRAIN";
    std::string *pointer = &ss;
    std::string &REFERENCE = ss;

    std::cout << "The memory address of the string variable: " << &ss << std::endl;
    std::cout << "The memory address held by stringPTR:      " << pointer << std::endl;
    std::cout << "The memory address held by stringREF:      " << &REFERENCE << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "The value of the string variable  : " << ss << std::endl;
    std::cout << "The value pointed to by stringPTR : " << *pointer << std::endl;
    std::cout << "The value pointed to by stringREF : " << REFERENCE << std::endl;
}

