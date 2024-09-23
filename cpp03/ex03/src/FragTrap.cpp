/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:16:09 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/23 10:34:03 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructor
FragTrap:: FragTrap() {}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << GREEN << "FragTrap " << _name << " constructed!" << RESET << std::endl;
    displayPoints();
}

// Constructor de copia
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << YELLOW << "FragTrap copy constructor called!" << RESET << std::endl;
}

// Operador de asignación
FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Destructor
FragTrap::~FragTrap() {
    std::cout << PURPLE << "FragTrap " << _name << " destructed!" << RESET << std::endl;
}

// Sobrescritura de la función attack
void FragTrap::attack(const std::string &target) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        _energyPoints--;
        std::cout << YELLOW << "FragTrap " << _name << "💥 attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
        displayPoints();
    } else {
        std::cout << "FragTrap " << _name << " is out of hit points or energy points!" << std::endl;
    }
}

// Función especial
void FragTrap::highFivesGuys() {
    std::cout << GREEN << "FragTrap " << _name << " says: High fives, guys!" << RESET << std::endl;
}
