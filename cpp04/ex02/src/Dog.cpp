/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:32:29 by ampjimen          #+#    #+#             */
/*   Updated: 2024/09/24 10:43:16 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog() {
    type = "Dog";
    brain = new Brain();
    std::cout << CYAN << " Dog created." << RESET << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other) {
    brain = new Brain(*other.brain);
    std::cout << CYAN << "Dog copied.(copy constructor)" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << CYAN << "Dog assigned.(Copy Assignment Operator)" << RESET << std::endl;
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << RED <<  "Dog destroyed." << RESET << std::endl;
}

void Dog::makeSound() const {
    std::cout << CYAN << " 🐶 Woof! Woof!" << RESET << std::endl;
}

//new
void Dog::showIdeas() const {
    for (int i = 0; i < 10; ++i) { // Muestra las primeras 10 ideas
        std::cout << "Cat's idea at index " << i << ": " << brain->getIdea(i) << std::endl;
    }
}

void Dog::setIdea(int index, const std::string &idea) {
    brain->setIdea(index, idea); // Llama al método de Brain para establecer la idea
}
