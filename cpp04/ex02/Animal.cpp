#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal") {}

Animal::Animal(const Animal& other) : type(other.type) {}

Animal::Animal(const std::string& name) : type(name) {}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Animal::~Animal() {}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "* generic animal sound *" << std::endl;
}
