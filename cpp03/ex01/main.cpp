#include "ClapTrap.hpp"
#include <iostream>

int main() {
    ClapTrap a("Alpha");
    ClapTrap b("Bravo");
    ClapTrap c(a);

    a.attack("Target1");
    b.attack("Alpha");

    a.takeDamage(3); 
    b.takeDamage(12); 
    b.takeDamage(12); //NJEREB WACH MAT 

    a.beRepaired(5); 
    b.beRepaired(5); 

    c = a;

    c.attack("Target3");

    return 0;
}
