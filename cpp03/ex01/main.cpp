#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    // ClapTrap a("Alpha");
    // ClapTrap b("Bravo");
    // ClapTrap c(a);
    ScavTrap s("moonlight");
    ScavTrap aa("jr");
    ScavTrap ss("star");
    ScavTrap c("camel");
    // a.attack("Target1");
    // b.attack("Alpha");
    c.attack("Alpha");
    ss.attack("jr");
    aa.takeDamage(10);
    // a.takeDamage(3); 
    // b.takeDamage(12); 

    c = aa;

    c.attack("Target3");

    return 0;
}
