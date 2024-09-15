/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:00:25 by ampjimen          #+#    #+#             */
/*   Updated: 2024/08/31 20:00:27 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
    // Constructor
}

Zombie::~Zombie() {
    std::cout << name << " has been destroyed." << std::endl;
}

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
