/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:32:29 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/23 19:34:30 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//Dog::Dog() {}

Dog::Dog() {
    type = "Dog";
    std::cout << CYAN << " Dog created." << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copied." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Dog assigned." << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << RED <<  "Dog destroyed." << RESET << std::endl;
}

void Dog::makeSound() const {
    std::cout << CYAN << " 🐶 Woof! Woof!" << RESET << std::endl;
}
