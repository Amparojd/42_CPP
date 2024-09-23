/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:10:01 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/23 10:02:54 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << GREEN << BOLD << "ScavTrap " << _name << " constructed!" << RESET << std::endl;
    displayPoints();
}

// Constructor de copia
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << YELLOW << "ScavTrap copy constructor called!" << RESET << std::endl;
}

// Operador de asignación
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << PURPLE << BOLD << "ScavTrap " << _name << " destructed!" << RESET << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        _energyPoints--;
        std::cout << YELLOW << "ScavTrap " << _name << "💥 attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
        displayPoints();
    } else {
        std::cout << "ScavTrap " << _name << " is out of hit points or energy points!" << std::endl;
    }
}


// Nueva función especial
void ScavTrap::guardGate() {
    std::cout << GREEN << "ScavTrap " << _name << " is now in Gatekeeper mode!" << RESET << std::endl;
}

