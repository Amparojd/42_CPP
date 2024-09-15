/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:32:01 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 12:41:04 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("") {
    std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called." << std::endl;
}

Animal& Animal::operator=(const Animal &other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

std::string Animal::getType() const {
    return type;
}
