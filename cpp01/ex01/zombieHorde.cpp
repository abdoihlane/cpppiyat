#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i =0;
    Zombie *zz = new Zombie[N];

    while(i < N)
    {
        zz[i].setName(name);
        zz[i].announce();
        i++;
    }
    return zz;
}
