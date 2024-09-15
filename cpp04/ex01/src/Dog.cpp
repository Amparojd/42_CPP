/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:32:29 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/15 12:41:26 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {
    type = other.type;
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called." << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
