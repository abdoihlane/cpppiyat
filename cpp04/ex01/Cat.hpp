#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private :
        Brain* cat_brain;
    public:
        Cat();
        Cat(const Cat& other);
        explicit Cat(const std::string& name);
        Cat& operator=(const Cat& other);
        virtual ~Cat();
        void makeSound() const;
};

#endif
