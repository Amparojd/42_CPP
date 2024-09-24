#include "AMateria.hpp"
#include <ostream>
#include <iostream>

AMateria::AMateria(std::string const & type) : m_type(type) {
    std::cout << GREEN << "AMateria creado: " << m_type << RESET << std::endl;
}

AMateria::~AMateria() {
    std::cout << GREEN << "AMateria destruido" << RESET << std::endl;
}

std::string const & AMateria::getType() const {
    return m_type;
}

void AMateria::use(ICharacter& target) {
    (void)target; // Previene advertencias de variable no utilizada
}
