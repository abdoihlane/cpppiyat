#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), Dog_brain(new Brain()) {
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), Dog_brain(new Brain(*other.Dog_brain)) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);

        if (!Dog_brain)
            Dog_brain = new Brain();
        *Dog_brain = *other.Dog_brain;
    }
    return *this;
}

Dog::~Dog() {
    delete Dog_brain;
    Dog_brain = 0;
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}
