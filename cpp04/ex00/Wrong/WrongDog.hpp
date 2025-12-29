#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
    public:
        WrongDog();
        WrongDog(const WrongDog& other);
        WrongDog(const std::string& name);
        WrongDog& operator=(const WrongDog& other);
        virtual ~WrongDog();
         void makeSound() const;
};

#endif
