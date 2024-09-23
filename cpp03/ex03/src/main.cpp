/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:52:11 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/23 11:00:22 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"

int main() {
    // Crear un DiamondTrap
    std::cout << std::endl;
    DiamondTrap diamond("Diamond1");
    diamond.whoAmI();

    std::cout << std::endl;
    DiamondTrap diamond2("Diamond2");
    diamond2.whoAmI();
    
    std::cout << std::endl;
    diamond.attack("Diamond1"); 
    diamond.highFivesGuys();
    diamond.takeDamage(20);
    diamond.beRepaired(10);

    diamond2.attack("Diamond1");
    diamond2.highFivesGuys();

    return 0;
}


