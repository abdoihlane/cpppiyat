#include "BitcoinExchange.hpp"
#include <iostream>
#include <map>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::map<std::string, double> btcDatabase;

    if (!loadDatabase("data.csv", btcDatabase))
    {
        std::cerr << "Error: could not csv open file." << std::endl;
        return 1;
    }

    evaluateInput(argv[1], btcDatabase);

    return 0;
}
