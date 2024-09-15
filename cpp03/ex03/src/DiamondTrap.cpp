/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:25:51 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 12:25:53 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
    std::cout << "DiamondTrap " << name << " constructed." << std::endl;
    
    // Use ClapTrap's members with explicit qualification
    ClapTrap::_hitPoints = FragTrap::getHitPoints();  // Asume getHitPoints() es un método accesible
    ClapTrap::_energyPoints = ScavTrap::getEnergyPoints();  // Asume getEnergyPoints() es un método accesible
    ClapTrap::_attackDamage = FragTrap::getAttackDamage();  // Asume getAttackDamage() es un método accesible
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destroyed." << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << "!" << std::endl;
}
