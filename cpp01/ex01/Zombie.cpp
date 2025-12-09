
#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed") {}

Zombie::Zombie(std::string n) : name(n) {}

Zombie::~Zombie() {
    std::cout << name << ": is destroyed 🪓" << std::endl;
}

void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& n) {
    name = n;
}
