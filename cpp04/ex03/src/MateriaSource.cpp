#include "MateriaSource.hpp"
#include <ostream>
#include <iostream>

MateriaSource::MateriaSource() {
    std::cout << RED << "MateriaSource creado" << RESET << std::endl;
    for (int i = 0; i < 4; i++)
        materias[i] = 0; // Inicializa el almacenamiento
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        std::cout << RED << "Eliminando materia de MateriaSource" << RESET << std::endl;
        delete materias[i]; // Elimina las materias
    }
    std::cout << RED << "MateriaSource destruido" << RESET << std::endl;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (materias[i] == 0) {
            materias[i] = m; // Almacena la materia
            std::cout << RED << "Materia " << m->getType() << " aprendida" << RESET << std::endl;
            return;
        }
    }
    std::cout << RED << "MateriaSource lleno, no se puede aprender más materias" << RESET << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (materias[i] && materias[i]->getType() == type) {
            std::cout << RED << "Materia " << type << " creada" << RESET << std::endl;
            return materias[i]->clone(); // Clonar la materia
        }
    }
    return 0; // No se encontró la materia
}
