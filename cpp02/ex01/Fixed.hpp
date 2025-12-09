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
    ~Fixed();
    Fixed(int const intValue);
    Fixed(float const floatValue);
    Fixed(Fixed const &other);
    Fixed &operator=(Fixed const &other);

    int     getRawBits() const;
    void    setRawBits(int const raw);
    float   toFloat() const;
    int     toInt() const;
};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);

#endif