/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:09:06 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/23 10:14:03 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << GREEN << ITALIC << "ClapTrap " << _name << " (base class) called!" << RESET << std::endl;
    //displayPoints();
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << YELLOW << "ClapTrap copy constructor called!" << RESET << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << PURPLE << ITALIC << "ClapTrap " << _name << " (base class) destructed!" << RESET << std::endl;
}

// Métodos
void ClapTrap::attack(const std::string &target) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        _energyPoints--;
        std::cout << YELLOW << "ClapTrap " << _name << "💥 attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
        displayPoints();
    } else {
        std::cout << "ClapTrap " << _name << " is out of hit points or energy points!" << std::endl;
    }
}


void ClapTrap::takeDamage(unsigned int amount) {
    if (amount >= _hitPoints) {
        _hitPoints = 0;
    } else {
        _hitPoints -= amount;
    }
    std::cout << RED << "ClapTrap " << _name << " 💔 takes " << amount
              << " points of damage!" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0) {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << CYAN << "ClapTrap " << _name << " ❤️‍🩹 is repaired by " << amount
                  << " hit points!" << RESET << std::endl;
        displayPoints();
    } else {
        std::cout << "ClapTrap " << _name << " is out of energy points!" << std::endl;
    }
}

//añadido 

void ClapTrap::displayPoints() {
    std::cout << GRAY << ITALIC << _name << " Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints << RESET << std::endl;
}