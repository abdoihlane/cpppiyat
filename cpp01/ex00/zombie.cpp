#include "Zombie.hpp"

Zombie::Zombie(string n) {
    name = n;
}

void Zombie::announce() {
    cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}

Zombie::~Zombie() {
    cout << name << " is destroyed." << endl;
}