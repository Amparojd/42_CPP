/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:17:47 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/12 20:24:13 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("") {}

Weapon::Weapon(const std::string& type) : type(type) {}

Weapon::~Weapon() {
    // Destructor 
}

const std::string& Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string& type) {
    this->type = type;
}
