#include "Brain.hpp"
#include "Animal.hpp"
#include "iostream"
#include "Dog.hpp"
#include "Cat.hpp"
int main()
{

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    // Subtype Polymorphism, Abstract Classes, and Interfaces
    delete j;//should not create a leak
    delete i;

    return 0;
}