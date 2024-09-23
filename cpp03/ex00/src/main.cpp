/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:05:02 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/23 08:55:07 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    std::cout << std::endl;
    ClapTrap *Player1 = new ClapTrap("Player1");
    std::cout << std::endl;
    ClapTrap *Player2 = new ClapTrap("Player2");

    std::cout << std::endl;
    Player1->attack("Player2");
    Player2->takeDamage(5);
    Player2->beRepaired(3);
    
    std::cout << std::endl;
    delete Player1;
    delete Player2;

    return 0;
}