#include <iostream>
#include <string>


int main()
{
    std::string  ss = "HI THI IS BRAIN";
    std::string *stringPTR = &ss;
    std::string &stringREF = ss;

    std::cout << &ss << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << ss << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}
