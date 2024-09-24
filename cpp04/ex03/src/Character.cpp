#include "Character.hpp"
#include <ostream>
#include <iostream>

Character::Character(std::string const & name) : m_name(name) {
    std::cout << PURPLE << "Personaje creado: " << m_name << RESET << std::endl;
    for (int i = 0; i < 4; i++)
        m_inventory[i] = 0; // Inicializa el inventario
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        std::cout << PURPLE << "Eliminando materia de personaje: " << m_name << RESET << std::endl;
        delete m_inventory[i]; // Elimina las Materias
    }
    std::cout << PURPLE << "Personaje destruido" << RESET << std::endl;
}

std::string const & Character::getName() const {
    return m_name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (m_inventory[i] == 0) {
            m_inventory[i] = m; // Equipar Materia
            std::cout << PURPLE << "Materia " << m->getType() << " equipada en " << m_name << RESET << std::endl;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        m_inventory[idx] = 0; // Des-equipar Materia (sin eliminarla)
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && m_inventory[idx] != 0) {
        std::cout << m_name << PURPLE << " usando materia " << m_inventory[idx]->getType() << " en " << target.getName() << RESET << std::endl;
        m_inventory[idx]->use(target); // Usar Materia
    }else {
        std::cout << PURPLE << m_name << " no tiene materia en la posición " << idx << RESET << std::endl;
    }
}

// Constructor de copia
Character::Character(const Character& other) : m_name(other.m_name) {
    std::cout << PURPLE << "Copiando personaje: " << m_name << RESET << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other.m_inventory[i]) {
            m_inventory[i] = other.m_inventory[i]->clone(); // Clonar Materias
        } else {
            m_inventory[i] = 0;
        }
    }
}

// Operador de asignación
Character& Character::operator=(const Character& other) {
    if (this != &other) {
        std::cout << PURPLE << "Asignando personaje: " << other.m_name << " a " << m_name << RESET << std::endl;
        m_name = other.m_name;
        for (int i = 0; i < 4; i++) {
            delete m_inventory[i]; // Elimina las Materias antiguas
            if (other.m_inventory[i]) {
                m_inventory[i] = other.m_inventory[i]->clone(); // Clonar Materias
            } else {
                m_inventory[i] = 0;
            }
        }
    }
    return *this;
}
