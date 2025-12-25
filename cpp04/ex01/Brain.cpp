#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructure called" << std::endl;
}

Brain::Brain(const Brain& other) 
{ 
    std::cout << "Brain copy constructure called" << std::endl;
    *this = other; 
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    std::cout << "assingment operator called" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain default destructure called" << std::endl;

}
