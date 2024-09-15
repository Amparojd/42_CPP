/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:32:01 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 12:32:03 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("") {
    std::cout << "Animal constructor called." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called." << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "Some generic animal sound." << std::endl;
}
