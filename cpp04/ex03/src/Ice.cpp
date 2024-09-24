#include "Ice.hpp"
#include <ostream>
#include <iostream>

Ice::Ice() : AMateria("ice") {
    std::cout << CYAN << "Ice materia creada" << RESET << std::endl;
}

Ice::~Ice() {
    std::cout << CYAN << "Ice materia destruida" << RESET << std::endl;
}

AMateria* Ice::clone() const {
    std::cout << PURPLE << "Clonando Ice materia" << RESET << std::endl;
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << PURPLE <<  "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
