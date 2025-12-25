#ifndef  FRAGTRAP_HPP
#define  FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    
    public :
        void guardGate();

        FragTrap();
        FragTrap(const FragTrap& other);
        FragTrap(std::string name);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();
        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
