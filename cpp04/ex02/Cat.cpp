#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
        std::cout << "default Cat constructor called" << std::endl;
    cat_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {}

Cat::Cat(const std::string& name) : Animal(name) {}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat() {
        std::cout << "default Cat destructor called" << std::endl;
    delete cat_brain;
}   

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}
