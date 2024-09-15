/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:05:02 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 12:05:03 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    // Crear un ClapTrap llamado "CLTP"
    ClapTrap claptrap("CLTP");

    // Realizar operaciones de ataque, daño y reparación
    claptrap.attack("target1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    // Crear otro ClapTrap y realizar operaciones similares
    ClapTrap anotherClaptrap("CLTP2");
    anotherClaptrap.attack("target2");
    anotherClaptrap.takeDamage(15);
    anotherClaptrap.beRepaired(10);

    return 0;
}
