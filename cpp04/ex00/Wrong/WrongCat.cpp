#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {}

WrongCat::WrongCat(const std::string& name) : WrongAnimal(name) {}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat() {}

void WrongCat::makeSound() const {
    std::cout << "Meow" << std::endl;
}
