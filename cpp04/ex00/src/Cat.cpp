/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:33:04 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/23 19:34:12 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << YELLOW << " Cat created." << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copied." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Cat assigned." << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << RED <<  "Cat destroyed." << RESET << std::endl;
}

void Cat::makeSound() const {
    std::cout << " 🐱 Meow! Meow!" << std::endl;
}

