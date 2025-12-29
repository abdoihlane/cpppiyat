#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal(const std::string& name);
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual ~WrongAnimal();
        std::string getType() const;
        void makeSound() const;
};

#endif
