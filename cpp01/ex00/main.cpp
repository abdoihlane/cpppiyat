#include <iostream>
#include "Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie( std::string name );

int main()
{
    Zombie* zombie1 = newZombie("HeapZombie");
    zombie1->announce();
    delete zombie1;

    randomChump("StackZombie");

    return 0;
}