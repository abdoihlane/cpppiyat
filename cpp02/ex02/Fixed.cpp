
#include <iostream>

#include "Fixed.hpp"

int Fixed::fractionalBits = 8;

Fixed::Fixed(): value(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(int const intValue) {
	// std::cout << "Int constructor called" << std::endl;
	value = intValue << fractionalBits;
}

Fixed::Fixed(float const floatValue) {
	// std::cout << "Float constructor called" << std::endl;
	value = (int)roundf(floatValue * (1 << fractionalBits));
}

Fixed&	Fixed::operator=(Fixed const &other) {
	// std::cout << "Assignation operator called" << std::endl;
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


bool Fixed::operator>(const Fixed &other) const {
	return this->value > other.value;	
}

bool Fixed::operator<(const Fixed &other) const {
	return this->value < other.value;	
}

bool Fixed::operator>=(const Fixed &other) const {

	return this->value >= other.value;	
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->value <= other.value;	
}

bool Fixed::operator==(const Fixed &other) const {
	return this->value == other.value;	
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->value != other.value;	
}




Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() { 
	this->value++;
	return *this;
}	

Fixed Fixed::operator++(int) { 
	Fixed temp = *this;
	this->value++;
	return temp;
}

Fixed& Fixed::operator--()
 {   
	this->value--;
	return *this;
}	

Fixed Fixed::operator--(int) 
{
	Fixed temp = *this;
	this->value--;
	return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	if(a < b)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	if(a < b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	if(a > b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	if(a > b)
		return a;
	else
		return b;
}	