#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void){
    std::cout << "RATATATAAA!! High five!!! ✋"<< std::endl;;
}

FragTrap::FragTrap()
    : ClapTrap("FragTrap")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor\n" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other)
{
    std::cout << "FragTrap " << name << " copied." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if(&other != this)
        {
            name = other.name;
            hitPoints = other.hitPoints;
            energyPoints = other.energyPoints;
            attackDamage = other.attackDamage;
        }
    std::cout << "FragTrap operator called" << std::endl;
    return *this;
}

FragTrap::FragTrap(std::string name) 
    : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap constructor " << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor\n";
}

void FragTrap::attack(const std::string& target)
{
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << "FragTrap " << name << " has no energy or HP to attack." << std::endl;
        return;
    }

    energyPoints--;
    std::cout << "FragTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " damage!" << std::endl;
}