/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:25:51 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/23 11:07:01 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructor
DiamondTrap::DiamondTrap() {}

DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_name"), FragTrap(name), ScavTrap(name), _name(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << GREEN << "DiamondTrap " << _name << " constructed!" << RESET << std::endl;
}

// Constructor de copia
DiamondTrap::DiamondTrap(const DiamondTrap &other) 
    : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) {
    std::cout << YELLOW << "DiamondTrap copy constructor called!" << RESET << std::endl;
}

// Operador de asignación
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << PURPLE << "DiamondTrap " << _name << " destructed!" << RESET << std::endl;
}

// Función especial
void DiamondTrap::whoAmI() {
    std::cout << PURPLE << BOLD << " Hi! ✌️ I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << RESET << std::endl;
}
