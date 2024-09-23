/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:16:23 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/23 10:05:15 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    FragTrap *player1 = new FragTrap("Player1");
    FragTrap *player2 = new FragTrap("Player2");

    player1->attack("Player2");
    player2->takeDamage(30);
    player2->beRepaired(5);
    player1->highFivesGuys();

    delete player1;
    delete player2;

    return 0;
}
