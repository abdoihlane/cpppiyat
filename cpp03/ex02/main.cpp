#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "=== Testing ClapTrap ===" << std::endl;
    ClapTrap clap("CL4P-TP");
    clap.attack("Enemy1");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.takeDamage(20); // should bring HP to 0
    clap.attack("Enemy2"); // should fail due to 0 HP
    clap.beRepaired(10);   // should fail due to 0 HP

    std::cout << "\n=== Testing ScavTrap ===" << std::endl;
    ScavTrap scav("SC4V-TP");
    scav.attack("Enemy3");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate(); // unique function

    std::cout << "\n=== Testing FragTrap ===" << std::endl;
    FragTrap frag("FR4G-TP");
    frag.attack("Enemy4");
    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.highFivesGuys(); // unique function

    std::cout << "\n=== Copy and Assignment ===" << std::endl;
    ClapTrap clapCopy = clap;        // copy constructor
    ScavTrap scavCopy;
    scavCopy = scav;                 // assignment operator
    FragTrap fragCopy(frag);         // copy constructor

    std::cout << "\n=== End of Test ===" << std::endl;
    return 0;
}
