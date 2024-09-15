/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:25:23 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/08 12:46:34 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N = 5;
    Zombie* horde = zombieHorde(N, "Zombie");

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;

    return 0;
}
