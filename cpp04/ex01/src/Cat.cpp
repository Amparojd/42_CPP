/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:33:04 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 12:41:44 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain)) {
    type = other.type;
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called." << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}