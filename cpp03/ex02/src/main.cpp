/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:16:23 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 12:16:25 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    // Crear ClapTrap
    ClapTrap claptrap("CLTP");
    claptrap.attack("target1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    // Crear ScavTrap
    ScavTrap scavtrap("SCVT");
    scavtrap.attack("target2");
    scavtrap.takeDamage(10);
    scavtrap.beRepaired(20);
    scavtrap.guardGate();

    // Crear FragTrap
    FragTrap fragtrap("FRGT");
    fragtrap.attack("target3");
    fragtrap.takeDamage(20);
    fragtrap.beRepaired(50);
    fragtrap.highFivesGuys();

    return 0;
}
