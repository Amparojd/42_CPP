/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:16:09 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 12:16:11 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructor
FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructed with a bang!" << std::endl;
}

// Destructor
FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destructed with a crash!" << std::endl;
}

// Método específico de FragTrap
void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " is requesting high fives!" << std::endl;
}
