#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <iomanip>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
};

bool validateDate(const std::string& dateStr);
bool validateNumber(const std::string& valStr);
bool loadDatabase(const char *filename, std::map<std::string, double>& btcDatabase);
void evaluateInput(const char *filename, const std::map<std::string, double>& btcDatabase);

#endif