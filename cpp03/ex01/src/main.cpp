/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:10:12 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/23 09:33:39 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    std::cout << std::endl;
    ScavTrap *Player1 = new ScavTrap("Player1");
    std::cout << std::endl;
    ScavTrap *Player2 = new ScavTrap("Player2");

    std::cout << std::endl;
    Player1->attack("Player2");
    Player2->takeDamage(20);
    Player2->beRepaired(5);
    
    Player1->guardGate();

    std::cout << std::endl;
    delete Player1;
    delete Player2;

    return 0;
}

