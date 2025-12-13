#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
private:
    int                 value;
    static int    fractionalBits;
public:
    Fixed();
    Fixed(const Fixed &other);
    ~Fixed();
    Fixed &operator=(const Fixed &other);
    int     getRawBits() const;
    void    setRawBits(int const raw);
};

#endif