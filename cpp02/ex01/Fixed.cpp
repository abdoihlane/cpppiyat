
#include <iostream>

#include "Fixed.hpp"

int Fixed::fractionalBits = 8;

Fixed::Fixed(): value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(int const intValue) {
	std::cout << "Int constructor called" << std::endl;
	value = intValue << fractionalBits;
}

Fixed::Fixed(float const floatValue) {
	std::cout << "Float constructor called" << std::endl;
	value = (int)roundf(floatValue * (1 << fractionalBits));
}

Fixed&	Fixed::operator=(Fixed const &other) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other) {
		value = other.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}


float	Fixed::toFloat(void) const {
	return (float)value / (float)(1 << fractionalBits);
}

int	Fixed::toInt(void) const {
	return (int)(value >> fractionalBits);
}

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return o;
}
