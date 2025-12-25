#ifndef  SCAVTRAP_HPP
#define  SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    
    public :
        void guardGate();

        ScavTrap();
        ScavTrap(const ScavTrap& other);
        ScavTrap(std::string name);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();
        void attack(const std::string& target);

};

#endif
