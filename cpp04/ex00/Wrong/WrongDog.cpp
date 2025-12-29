#include "WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog() : WrongAnimal("WrongDog") {}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other) {}

WrongDog::WrongDog(const std::string& name) : WrongAnimal(name) {}

WrongDog& WrongDog::operator=(const WrongDog& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongDog::~WrongDog() {}

void WrongDog::makeSound() const {
    std::cout << "Woof" << std::endl;
}
