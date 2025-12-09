#include "Harl.hpp"

int main(int ac, char **av)
{
    if(ac!= 2)
    {
        std::cout << "harl want his extra bacon and also need you to use his program like :" << std::endl <<" \n            ./harlFilter <level>\n" << std::endl;
        return 1;
    }
    std::string level = av[1];
    Harl harl;
    harl.check_level(level);
    return 0;
}