#include "ScavTrap.hpp"

void ScavTrap::guardGate(){
    std::cout << "ScavTrap is now in Gate keeper mode " << std::endl;
}

ScavTrap::ScavTrap()
    : ClapTrap("ScavTrap")
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor\n" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if(&other != this)
        {
            name = other.name;
            hitPoints = other.hitPoints;
            energyPoints = other.energyPoints;
            attackDamage = other.attackDamage;
        }
    std::cout << "ScavTrap operator called" << std::endl;
    return *this;
}


ScavTrap::ScavTrap(std::string name) 
    : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap constructor " << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << "ScavTrap " << name << " has no energy or HP to attack." << std::endl;
        return;
    }

    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " damage!" << std::endl;
}