#include "ex04.hpp"

int main(int ac,char **av)
{
    ex04    replace;
    if(ac != 4)
        return 1;
    replace.s1 = av[2];
    replace.s2= av[3];
    replace.filename = av[1];
    std::ifstream file_in(replace.filename.c_str());
    
    if(!file_in.is_open())
        {
            std::cout << "could not open this file"<< replace.filename << std::endl;
            return 1;
        }

    std::string file_out_name = replace.filename + ".replace";
    std::ofstream file_out(file_out_name.c_str());

    if(!file_out.is_open())
    {
        std::cout << "could not create the output file"<< std::endl;
            return 1;  
    }

    std::string line;
    while (std::getline(file_in, line))
    {
        size_t pos = 0;
        while ((pos = line.find(replace.s1, pos)) != std::string::npos)
        {
            line.erase(pos, replace.s1.length());
            line.insert(pos, replace.s2);
            pos += replace.s2.length();
        }
        file_out << line << std::endl;
    }

    file_in.close();
    file_out.close();
    return 0;
}