#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
    const WrongAnimal* meta = new WrongAnimal();
    // const WrongAnimal* j = new WrongDog();
    const WrongAnimal* i = new WrongCat();
    // std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); 
    // j->makeSound();
    meta->makeSound();
    delete meta;
    // delete j;
    delete i;
    return 0;
}