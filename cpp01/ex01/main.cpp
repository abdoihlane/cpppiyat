#include "Zombie.hpp"

int main() {
    int n = 5;
    Zombie* horde = zombieHorde(n, "rich");
    delete[] horde; 
    return 0;
}
