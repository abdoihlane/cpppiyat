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



    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    Fixed &operator++();       
    Fixed operator++(int);    
    Fixed &operator--();       
    Fixed operator--(int);    

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    
    int     getRawBits() const;
    void    setRawBits(int const raw);
    float   toFloat() const;
    int     toInt() const;
};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);

#endif