/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:10:12 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 12:10:14 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

    return 0;
}
