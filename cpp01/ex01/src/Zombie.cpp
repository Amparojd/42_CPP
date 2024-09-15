/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:24:21 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/12 20:15:56 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("") {
    // Constructor por defecto
}

Zombie::Zombie(std::string name) : name(name) {
    // Constructor name
}

Zombie::~Zombie() {
    std::cout << name << " is no more. Rest in pieces!" << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
