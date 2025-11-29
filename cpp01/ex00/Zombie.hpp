#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
using namespace std;

class Zombie {
private:
    std::string name;

public:
    Zombie(string n) {
        name = n;
    }

    void announce() {
        cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
    }
};

#endif