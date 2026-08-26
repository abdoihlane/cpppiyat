#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { (void)other; }
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) { (void)other; return *this; }
BitcoinExchange::~BitcoinExchange() {}

static std::string trimWhitespace(const std::string& str)
{
    size_t start = 0;
    size_t end = str.size();

    while (start < end && std::isspace(static_cast<unsigned char>(str[start])))
        ++start;

    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
        --end;

    return str.substr(start, end - start);
}

static bool checkLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0)
        || (year % 400 == 0);
}

static bool checkDateFormat(const std::string& dateStr)
{
    if (dateStr.size() != 10)
        return false;

    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
        {
            if (dateStr[i] != '-')
                return false;
        }
        else if (!std::isdigit(static_cast<unsigned char>(dateStr[i])))
        {
            return false;
        }
    }

    return true;
}

bool validateDate(const std::string& dateStr)
{
    if (!checkDateFormat(dateStr))
        return false;

    int year = std::atoi(dateStr.substr(0, 4).c_str());
    int month = std::atoi(dateStr.substr(5, 2).c_str());
    int day = std::atoi(dateStr.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    int monthDays[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (month == 2 && checkLeapYear(year))
        monthDays[1] = 29;

    if (day < 1 || day > monthDays[month - 1])
        return false;

    return true;
}

bool validateNumber(const std::string& valStr)
{
    if (valStr.empty())
        return false;

    size_t i = 0;
    bool hasDot = false;
    bool hasDigit = false;

    if (valStr[i] == '+' || valStr[i] == '-')
        ++i;

    for (; i < valStr.size(); ++i)
    {
        if (std::isdigit(static_cast<unsigned char>(valStr[i])))
        {
            hasDigit = true;
        }
        else if (valStr[i] == '.' && !hasDot)
        {
            hasDot = true;
        }
        else
        {
            return false;
        }
    }

    return hasDigit;
}

bool loadDatabase(const char *filename,
                   std::map<std::string, double>& btcDatabase)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: could not open database." << std::endl;
        return false;
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string dateStr;
        std::string rateStr;

        if (!std::getline(ss, dateStr, ','))
            continue;

        if (!std::getline(ss, rateStr))
            continue;

        dateStr = trimWhitespace(dateStr);
        rateStr = trimWhitespace(rateStr);

        if (dateStr.empty() || rateStr.empty())
            continue;

        btcDatabase[dateStr] = std::atof(rateStr.c_str());
    }

    return true;
}

static bool findExchangeRate(
    const std::map<std::string, double>& btcDatabase,
    const std::string& dateStr,
    double& exchangeRate)
{
    std::map<std::string, double>::const_iterator it =
        btcDatabase.lower_bound(dateStr);

    if (it != btcDatabase.end() && it->first == dateStr)
    {
        exchangeRate = it->second;
        return true;
    }

    if (it == btcDatabase.begin())
        return false;

    --it;
    exchangeRate = it->second;

    return true;
}

void evaluateInput(
    const char *filename,
    const std::map<std::string, double>& btcDatabase)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        line = trimWhitespace(line);

        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string dateStr;
        std::string amountStr;

        if (!std::getline(ss, dateStr, '|') ||
            !std::getline(ss, amountStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        dateStr = trimWhitespace(dateStr);
        amountStr = trimWhitespace(amountStr);

        if (!validateDate(dateStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!validateNumber(amountStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double amount = std::atof(amountStr.c_str());

        if (amount < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (amount > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        double exchangeRate;

        if (!findExchangeRate(btcDatabase, dateStr, exchangeRate))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::cout << dateStr
                  << " => "
                  << amount
                  << " = "
                  << std::fixed
                  << std::setprecision(2)
                  << amount * exchangeRate
                  << std::endl;
    }
}
