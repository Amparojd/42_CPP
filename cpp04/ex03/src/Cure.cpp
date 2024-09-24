#include "Cure.hpp"
#include <ostream>
#include <iostream>

Cure::Cure() : AMateria("cure") {
    std::cout << YELLOW << "Cure materia creada" << RESET <<std::endl;
}

Cure::~Cure() {
    std::cout << YELLOW << "Cure materia destruida" << RESET << std::endl;
}

AMateria* Cure::clone() const {
    std::cout << YELLOW << "Clonando Cure materia" << RESET << std::endl;
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << YELLOW << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}
