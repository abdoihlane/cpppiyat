#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include <string>

using namespace std;

class Zombie {
private:
    std::string name; 

public:
    Zombie();             
    Zombie(std::string n);     
    ~Zombie();           

    void announce() const;    
    void setName(std::string n); 
};

Zombie::Zombie() {
    name = "Unnamed";
}

Zombie::Zombie(std::string n) {
    name = n;
}

Zombie::~Zombie() {
    std::cout << name << " is destroyed 🪓" << std::endl;
}

void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string n) {
    name = n;
}

Zombie* newZombie( std::string name )
{
    return new Zombie(name);
}
Zombie* zombieHorde(int N, std::string name);

#endif