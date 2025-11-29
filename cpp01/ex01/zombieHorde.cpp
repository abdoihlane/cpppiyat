#include "Zombie.h"

Zombie* zombieHorde( int N, std::string name )
{
    int i =0;
    Zombie *zz = new Zombie[N];

    while(i < N)
    {
        cout  << i+1<< " "; 
        zz->setName(name);
        zz->announce();
        i++;
    }
    return zz;
}
