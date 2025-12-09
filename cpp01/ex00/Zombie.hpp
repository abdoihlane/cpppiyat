#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
using namespace std;

class Zombie {
private:
    std::string name;
public:
    Zombie(string n);
    ~Zombie();
    Zombie* newZombie( std::string name );
    void randomChump(std::string name );
    void announce();
};

#endif 