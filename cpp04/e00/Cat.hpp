#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        Cat(const Cat& other);
        explicit Cat(const std::string& name);
        Cat& operator=(const Cat& other);
        virtual ~Cat();
        void makeSound() const;
};

#endif
